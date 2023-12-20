/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>
#include <stdio.h>
#include "core.h"
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
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }

}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);

    }

    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);

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
            menuAppointment(data);
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
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            printf("Phone Information\n"
                "-----------------\n"
                "How will the patient like to be contacted?\n");
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:viewAllAppointments(data->appointments, data->maxAppointments, data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            printf("\n");
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data->appointments, data->maxAppointments, data->patients, data->maxPatient);// ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments, data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #2 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Display's all patient data in the FMT_FORM | FMT_TABLE format

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
    printf("\n");
    menuPatientEdit(&patient[index]);
}


// Remove a patient record from the patient array
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
    printf("\nAre you sure you want to remove this patient record? (y/n): ");

    while (1) {
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 

        if (strlen(input) == 1 && strchr("yn", input[0])) {
            confirm = input[0];
            break;
        }
        else {
            printf("ERROR: Character must be one of [yn]: ");
        }
    }

    if (confirm == 'y') {
        patient[index].patientNumber = 0;
        printf("Patient record has been removed!\n\n");
    }
    else {
        printf("Operation aborted.\n\n");
    }

    return 0;
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Comparison function for sorting appointments by date and time
int compareAppsbyDateandTime(const void* a, const void* b) {
    const struct Appointment* apptA = (const struct Appointment*)a;
    const struct Appointment* apptB = (const struct Appointment*)b;

    // Compare dates
    if (apptA->date.year != apptB->date.year)
        return apptA->date.year - apptB->date.year;
    if (apptA->date.month != apptB->date.month)
        return apptA->date.month - apptB->date.month;
    if (apptA->date.day != apptB->date.day)
        return apptA->date.day - apptB->date.day;

    // Compare times
    if (apptA->time.hour != apptB->time.hour)
        return apptA->time.hour - apptB->time.hour;
    return apptA->time.min - apptB->time.min;

}
  

// View ALL scheduled appointments
    void viewAllAppointments(const struct Appointment appointments[], int apptSize,
        const struct Patient patients[], int patientSize) {
        // Sort the appointments array using the comparison function
        qsort((void*)appointments, apptSize, sizeof(struct Appointment), compareAppsbyDateandTime);

        // Display the schedule header
        displayScheduleTableHeader(NULL, 1);

        // Loop through each appointment
        int i;
        for (i = 0; i < apptSize; i++) {
            const struct Appointment* appointment = &appointments[i];
            int patientIndex = findPatientIndexByPatientNum(appointment->patientNumber, patients, patientSize);

            if (patientIndex != -1) {
                const struct Patient* patient = &patients[patientIndex];
                displayScheduleData(patient, appointment, 1); 
            }
        }
    }

// View appointment schedule for the user input date
void viewAppointmentSchedule(const struct Appointment appointments[], int apptSize, const struct Patient patients[], int patientSize) {
    int day = 31;
    struct Date d;

    printf("Year        : ");
    d.year = inputIntPositive();
    printf("Month (1-12): ");
    d.month = inputIntRange(1, 12);
    printf("Day (1-");
    if (d.month == 4 || d.month == 9 || d.month == 11)
    {
        day = 30;
    }

    if (d.month == 2)
    {
        day = 28;
    }

    if (d.year % 4 == 0 && d.month == 2)
    {
        day = 29;
    }

    printf("%d)  : ", day);
    d.day = inputIntRange(1, day);
    printf("\n");

    displayScheduleTableHeader(&d, 0);
    int i;
    for (i = 0; i < apptSize; i++) {
        const struct Appointment* appointment = &appointments[i];

        if (appointment->date.year == d.year &&
            appointment->date.month == d.month &&
            appointment->date.day == day) {

            int patientIndex = findPatientIndexByPatientNum(appointment->patientNumber, patients, patientSize);

            if (patientIndex != -1) {
                const struct Patient* patient = &patients[patientIndex];
                displayScheduleData(patient, appointment, 0); 
            }
        }
   }
    printf("\n");
}


// Add an appointment record to the appointment array
// Todo:
    void addAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients)
    {

        struct Date d;
        struct Time t;
        int dayMax = 31;
        int numP;
        int index;
        int notAvailable = 1;

        printf("Patient Number: ");
        numP = inputIntPositive();
        index = findPatientIndexByPatientNum(numP, pt, maxPatients);

        if (index >= 0)
        {

        while (notAvailable)
            {
        printf("Year        : ");
        d.year = inputIntPositive();

        printf("Month (1-12): ");
        d.month = inputIntRange(1, 12);

        printf("Day (1-");

        if (d.month == 4 || d.month == 9 || d.month == 11)
         {
          dayMax = 30;
         }

        if (d.month == 2)
         {
          dayMax = 28;
         }

        if (d.year % 4 == 0 && d.month == 2)
         {
          dayMax = 29;
         }

        printf("%d)  : ", dayMax);
        d.day = inputIntRange(1, dayMax);

        printf("Hour (0-23)  : ");
        t.hour = inputIntRange(0, 23);

        printf("Minute (0-59): ");
        t.min = inputIntRange(0, 59);


        if (timeSlotAvailable(d, t, app, maxAppointments))
        {
        printf("\nERROR: Appointment timeslot is not available!");
        printf("\n\n");
        }

        else
        {

        while ((t.hour < START_HOUR || t.hour > END_HOUR) || (t.hour == END_HOUR && t.min > 0) || (t.min % APPOINTMENT_INTERVAL != 0))

         {
         printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, APPOINTMENT_INTERVAL);

         printf("Hour (0-23)  : ");

         t.hour = inputIntRange(0, 23);

         printf("Minute (0-59): ");

         t.min = inputIntRange(0, 59);
         }

         notAvailable = 0;
        }
        }
            index = nextSlotAvailable(app, maxAppointments);
            app[index].date = d;
            app[index].time = t;
            app[index].patientNumber = numP;

            printf("\n*** Appointment scheduled! ***");
            printf("\n\n");
        }

        else
        {
            printf("\nERROR: Patient record not found!");
            printf("\n\n");
        }

        return;
    }

    // Remove an appointment record from the appointment array
    // Todo:
    void removeAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients)
    {
        struct Date d;
        int index;
        int numP;
        int day = 0;
        int aptIndex;

        printf("Patient Number: ");
        numP = inputIntPositive();
        index = findPatientIndexByPatientNum(numP, pt, maxPatients);

        if (index >= 0)
        {

            printf("Year        : ");
            d.year = inputIntPositive();


            printf("Month (1-12): ");
            d.month = inputIntRange(1, 12);


            printf("Day (1-");

            if (d.month == 4 || d.month == 9 || d.month == 11)
            {

                day = 30;

            }

            if (d.month == 2)
            {

                day = 28;

            }

            if (d.year % 4 == 0 && d.month == 2)
            {

                day = 29;

            }

            printf("%d)  : ", day);
            d.day = inputIntRange(1, day);

            aptIndex = validAppointment(numP, d, app, maxAppointments);

            if (aptIndex >= 0)
            {
                printf("\n");

                displayPatientData(&pt[index], FMT_FORM);
                printf("Are you sure you want to remove this appointment (y,n): ");

                if (inputCharOption("yn") == 'y')
                {

                    app[aptIndex].patientNumber = 0;
                    printf("\nAppointment record has been removed!\n\n");

                }

                else
                {

                    printf("ERROR: No appointment for this date!\n\n");


                }
            }
        }

        else
        {

            printf("ERROR: Patient record not found!\n\n");


        }
    }


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)

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

int timeSlotAvailable(struct Date date, struct Time time, struct Appointment* app, int maxAppointments)
{
    int t;
    int availSlot = 0;

    for (t = 0; t < maxAppointments; t++)
    {

        if (date.year == app[t].date.year && date.month == app[t].date.month && date.day == app[t].date.day && time.hour == app[t].time.hour && time.min == app[t].time.min)
        {

            availSlot = 1;

        }
    }

    return availSlot;
}


int nextSlotAvailable(struct Appointment* app, int maxAppointments)
{
    int s = 0;
    int available = 0;

    while (available == 0 && s < maxAppointments)
    {

        if (app[s].patientNumber < 1)
        {

            available = 1;

        }
        s++;
    }

    return s;
}

int validAppointment(int patientNumber, struct Date date, struct Appointment* app, int maxAppointments)
{
    int s = 0;
    int t = 0;

    while (s == 0 && s < maxAppointments)
    {

        if ((app[s].patientNumber == patientNumber) && (app[s].date.day == date.day) && (app[s].date.month == date.month) && (app[s].date.year == date.year))
        {

            s = 1;

        }

        s++;
    }

    return s - 1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* patientData, struct Patient patients[], int max)
{
    FILE* file = fopen(patientData, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", patientData);
        return 0;
    }

    int readRecords = 0;
    char line[100]; // Assuming a line in the file won't exceed 100 characters

    while (fgets(line, sizeof(line), file) != NULL && readRecords < max)
    {
        int patientNumber;
        char name[NAME_LEN + 1];
        char phoneDescription[PHONE_DESC_LEN + 1];
        char phoneNumber[PHONE_LEN + 1];

        if (sscanf(line, "%d|%[^|]|%[^|]|%s", &patientNumber, name, phoneDescription, phoneNumber) >= 2)
        {
            patients[readRecords].patientNumber = patientNumber;
            strncpy(patients[readRecords].name, name, NAME_LEN);

            if (strcmp(phoneDescription, "TBD") == 0) {
                strncpy(patients[readRecords].phone.description, "TBD", PHONE_DESC_LEN);
                patients[readRecords].phone.description[PHONE_DESC_LEN] = '\0';
                patients[readRecords].phone.number[0] = '\0';
            }
            else {
                strncpy(patients[readRecords].phone.description, phoneDescription, PHONE_DESC_LEN);
                strncpy(patients[readRecords].phone.number, phoneNumber, PHONE_LEN);
            }

            readRecords++;
        }
    }

    fclose(file);
    return readRecords;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* appointmentData, struct Appointment appoints[], int max)
{
    FILE* file = fopen(appointmentData, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", appointmentData);
        return 0;
    }

    int readRecords = 0;
    char line[100]; // Assuming a line in the file won't exceed 100 characters

    while (fgets(line, sizeof(line), file) != NULL && readRecords < max)
    {
        int patientNumber, year, month, day, hour, min;

        if (sscanf(line, "%d,%d,%d,%d,%d,%d", &patientNumber, &year, &month, &day, &hour, &min) == 6)
        {
            appoints[readRecords].patientNumber = patientNumber;
            appoints[readRecords].date.year = year;
            appoints[readRecords].date.month = month;
            appoints[readRecords].date.day = day;
            appoints[readRecords].time.hour = hour;
            appoints[readRecords].time.min = min;
            readRecords++;
        }
    }

    fclose(file);
    return readRecords;
}