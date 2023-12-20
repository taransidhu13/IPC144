/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Tarandeep Kaur
Student ID#: 139389225
Email      : tarandeep-kaur6@myseneca.ca
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
        printf("\n");
    }
    
    else
    {    
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            printf("\n");
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("\n");
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n");
        }
        else if (selection == 2)
        {
            printf("Phone Information\n"
                "-----------------\n"
                "How will the patient like to be contacted?\n");
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n");
        }

    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------



// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i; // Declare loop variable outside of the loop
    if (fmt == FMT_TABLE)
        displayPatientTableHeader();
    int noRecords = 1;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            noRecords = 0;
        }
    }
    if (noRecords) {
        printf("*** No records found ***\n");
    } 
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        selection = inputIntRange(0, 2);

        switch (selection)
        {
        case 0:
            printf("\n");
            return; // Return to the previous menu
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i; // Declare loop variable outside of the loop
    int index = -1;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("ERROR: Patient listing is FULL!\n");
        printf("\n");
        return;
    }

    printf("Patient Data Input\n"
        "------------------\n");
    int nextNum = nextPatientNumber(patient, max);
    patient[index].patientNumber = nextNum;
    printf("Number: %05d\n", nextNum);
    inputPatient(&patient[index]);

    printf("*** New patient record added ***\n");
    printf("\n");
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int patientNumber;
    printf("Enter the patient number: ");
    patientNumber = inputInt();

    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
        return;
    }

    menuPatientEdit(&patient[index]);
}


// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int patientNumber;
    printf("Enter the patient number: ");
    patientNumber = inputInt();
    printf("\n");

    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
        return;
    }

    displayPatientData(&patient[index], FMT_FORM);

    char confirm;
    printf("Are you sure you want to remove this patient record? (y/n): ");
    confirm = inputCharOption("yn");

    if (confirm == 'y')
    {
        patient[index].patientNumber = 0;
        printf("Patient record has been removed!\n\n");
    }
    else
    {
        printf("Operation aborted.\n\n");
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber;
    printf("\n");
    printf("Search by patient number: ");
    patientNumber = inputInt();
    printf("\n");

    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("*** No records found ***\n\n");
        return;
    }

    displayPatientData(&patient[index], FMT_FORM);
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i; // Declare loop variable outside of the loop
    char phoneNumber[PHONE_LEN + 1];
    printf("\n");
    printf("Search by phone number: ");
    inputCString(phoneNumber, 10, PHONE_LEN);
    printf("\n");

    int noRecords = 1;

    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        
        if (strncmp(patient[i].phone.number, phoneNumber, PHONE_LEN) == 0)
        {
          
            displayPatientData(&patient[i], FMT_TABLE);
            noRecords = 0;

        }
    }

    if (noRecords) {
        printf("\n");
        printf("*** No records found ***\n");
    }
    printf("\n");
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i; // Declare loop variable outside of the loop
    int nextNum = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > nextNum)
            nextNum = patient[i].patientNumber;
    }

    return nextNum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i; // Declare loop variable outside of the loop 
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
            return i;
    }
    return -1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    printf("Phone Information\n"
           "-----------------\n"
           "How will the patient like to be contacted?\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int option;
    printf("1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    
    option = inputIntRange(1, 4);
    printf("\n");
    switch (option)
    {
    case 1:
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: CELL\n");
        break;
    case 2:
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: HOME\n");
        break;
    case 3:
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: WORK\n");
        break;
    case 4:
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        phone->description[PHONE_DESC_LEN] = '\0';
        phone->number[0] = '\0';
        return;
    }

    printf("Number : ");
    inputCString(phone->number, 10, PHONE_LEN);
    printf("\n");
}