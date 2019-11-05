#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<conio.h>

struct patient
{
	long ppsNum;
	char firstName[20];
	char lastName[20];
	int yearBorn;
	char gender[10];
	char emailAddress[30];
	char nextOfKin[30];
	int lastAppointmentDay;
	int lastAppointmentMonth;
	int lastAppointmentYear;
	double weight;
	double height;

	//struct patient* NEXT;
};

typedef struct {
	char username[30];
	char password[30];

}logIn;

int checkUser(logIn* user, int spaces);
void addPatient(struct patient* person, int spaces);
void displayAllPatients(struct patient* person, int spaces);
void displayPatient(struct patient* person, int spaces);
void updatePatient(struct patient* person, int spaces);
//void deletePatient(struct patient* person, int spaces);
//void DeleteElementAtStart(struct patient** top);
void orderByLastAppointment(struct patient* person, int spaces);
void reportFilePatientDetails(struct patient* person, int spaces);

void main()
{
	struct patient* patients = NULL;
	logIn* users;
	int usernames = 3;
	int size;
	int option;
	int i;
	int ppsNo;

	users = (logIn*)malloc(usernames * sizeof(logIn));

	printf("Welcome to the hospital database \n");

	checkUser(users, usernames);

	printf("Please enter the size of the hospital \n");
	scanf("%d", &size);

	patients = (struct patient*)malloc(size * sizeof(struct patient));

	// set pps number of all patients to 0
	for (i = 0;i < size;i++) {
		(patients + i)->ppsNum = 0;
	}

	// menu displayed for user
	printf("Menu for Hospital Database \nPlease enter: \n1) Add a patient\n2) Display all patients details \n3) Display patient details \n4) Update a patient details \n5) Delete patient \n6) Generate statistics \n7) Print all patient details into a report file \n8) List all patients in order of their last appointment \nOr -1 to exit\n");
	scanf("%d", &option);

	// options for user displayed unless user inputs -1 to exit
	while (option != -1)
	{
		if (option == 1) {
			addPatient(patients, size);
		}

		else if (option == 2) {
			displayAllPatients(patients, size);
		}

		else if (option == 3) {
			displayPatient(patients, size);
		}

		else if (option == 4) {
			updatePatient(patients, size);
		}
		else if (option == 5) {
			printf("Sorry option not available\n");
			//deletePatient(patients, size);
		}
		else if (option == 6) {
			printf("Sorry option not available\n");
		}
		else if (option == 7) {
			reportFilePatientDetails(patients, size);
		}
		else if (option == 8) {
			orderByLastAppointment(patients, size);
		}
		else {
			printf("Incorrect option - please enter again\n");
		}

		printf("Menu for Hospital Database \nPlease enter: \n1) Add a patient\n2) Display all patients details \n3) Display patient details \n4) Update a patient details \n5) Delete patient \n6) Generate statistics \n7) Print all patient details into a report file \n8) List all patients in order of their last appointment \nOr -1 to exit\n");
		scanf("%d", &option);
	} // while

	// details output to report when program terminated
	reportFilePatientDetails(patients, size);
} // void main()

void addPatient(struct patient* person, int spaces)
{
	int i;
	int j;
	long ppsNo;

	// loops through spaces in hospital to input patient details
	for (i = 0; i < spaces; i++)
	{
		if ((person + i)->ppsNum == 0) {
			printf("Please enter pps number: \n");
			scanf("%ld", &ppsNo);

			// validates pps number entered by user
			for (j = 0;j < i;j++) {
				if ((person + j)->ppsNum == ppsNo) {
					printf("Pps number already taken\n");
					return;
				}
			}

			(person + i)->ppsNum = ppsNo;
			
			printf("Please enter first name: \n");
			scanf("%s", &(person + i)->firstName);
			printf("Please enter last name: \n");
			scanf("%s", &(person + i)->lastName);
			printf("Please enter year born: \n");
			scanf("%d", &(person + i)->yearBorn);
			printf("Please enter gender: \n");
			scanf("%s", &(person + i)->gender);
			printf("Please enter email address: \n");
			scanf("%s", &(person + i)->emailAddress);
			printf("Please enter next of kin's name: \n");
			scanf("%s", &(person + i)->nextOfKin);
			printf("Please enter last appointment (spaces between day, month, year): \n");
			scanf("%d %d %d", &(person + i)->lastAppointmentDay, &(person + i)->lastAppointmentMonth, &(person + i)->lastAppointmentYear);
			printf("Please enter weight: \n");
			scanf("%lf", &(person + i)->weight);
			printf("Please enter height: \n");
			scanf("%lf", &(person + i)->height);
			return;
		}
	} // for

	printf("Hospital is full\n");

} // void addPatient()

void displayAllPatients(struct patient* person, int spaces)
{
	int i;

	// displays all current patients details
	for (i = 0;i < spaces;i++)
	{
		if ((person + i)->ppsNum == 0) 
		{
			printf("There is no patient occupying space %d\n", i+1);
		}

		else
		{
			printf("Patient at space %d: \n", i+1);
			printf("PPS Number: %ld \n", (person + i)->ppsNum);
			printf("Full name: %s %s \n", (person + i)->firstName, (person+i)->lastName);
			printf("Year born: %d \n", (person + i)->yearBorn);
			printf("Gender: %s \n", (person + i)->gender);
			printf("Email address: %s \n", (person + i)->emailAddress);
			printf("Next of kin: %s \n", (person + i)->nextOfKin);
			printf("Last appointment date: %d %d %d \n", (person + i)->lastAppointmentDay, (person + i)->lastAppointmentMonth, (person + i)->lastAppointmentYear);
			printf("Weight: %.2lf \n", (person + i)->weight);
			printf("Height: %.2lf \n", (person + i)->height);

		}
	}

} // void displayAllPatients()

void displayPatient(struct patient* person, int spaces)
{
	int i;
	long ppsNo;

	printf("Please enter the pps number of the patient you wish to see: \n");
	scanf("%ld", &ppsNo);

	for (i = 0;i < spaces;i++)
	{
		// displays patients details if their ppsNum is equal to the ppsNum entered by user
		if (ppsNo == (person + i)->ppsNum)
		{
			printf("PPS Number: %ld \n", (person + i)->ppsNum);
			printf("Patient at space %d: \n", i+1);
			printf("Full name: %s %s \n", (person + i)->firstName, (person + i)->lastName);
			printf("Year born: %d \n", (person + i)->yearBorn);
			printf("Gender: %s \n", (person + i)->gender);
			printf("Email address: %s \n", (person + i)->emailAddress);
			printf("Next of kin: %s \n", (person + i)->nextOfKin);
			printf("Last appointment date: %d %d %d \n", (person + i)->lastAppointmentDay, (person + i)->lastAppointmentMonth, (person + i)->lastAppointmentYear);
			printf("Weight: %.3lf \n", (person + i)->weight);
			printf("Height: %.3lf \n", (person + i)->height);
			return;
		}
	}

	if (ppsNo != (person + i)->ppsNum)
	{
		printf("This patient is not at this hospital\n");
	}

} // void displayPatient()

void updatePatient(struct patient* person, int spaces)
{
	int i;
	long ppsNo;

	printf("Please enter the pps number of the patient to update their details: \n");
	scanf("%ld", &ppsNo);

	for (i = 0;i < spaces;i++) 
	{
		// allows user to update patients details if their ppsNum is equal to the ppsNum entered by user
		if (ppsNo == (person + i)->ppsNum) 
		{
			printf("Please update patient: %s %s details: \n", (person + i)->firstName, (person + i)->lastName);
			printf("Please enter first name: \n");
			scanf("%s", &(person + i)->firstName);
			printf("Please enter last name: \n");
			scanf("%s", &(person + i)->lastName);
			printf("Please enter gender: \n");
			scanf("%s", &(person + i)->gender);
			printf("Please enter email address: \n");
			scanf("%s", &(person + i)->emailAddress);
			printf("Please enter next of kin's name: \n");
			scanf("%s", &(person + i)->nextOfKin);
			printf("Please enter last appointment (spaces between day, month, year): \n");
			scanf("%d %d %d", &(person + i)->lastAppointmentDay, &(person + i)->lastAppointmentMonth, &(person + i)->lastAppointmentYear);
			printf("Please enter weight: \n");
			scanf("%lf", &(person + i)->weight);
			printf("Please enter height: \n");
			scanf("%lf", &(person + i)->height);
			return;
		}
	}


	if (ppsNo != (person + i)->ppsNum)
	{
		printf("This patient is not at this hospital\n");
	}

} // void updatePatient()

/*void deletePatient(struct patient* person, int spaces)
{
	int i = 0;
	int ppsNo = 0;
	struct patient* temp;
	struct patient* prev_temp;

	printf("Please enter the pps number of the patient you wish to remove: \n");
	scanf("%d", &ppsNo);

	temp = person;

	for (i = 0;i < spaces-1;i++)
	{
		if (ppsNo == (person + i)->ppsNum) {
			printf("Debug 1\n");
			prev_temp = temp;
			temp = temp->NEXT;
		}
	}

	if (ppsNo != (person + i)->ppsNum)
	{
		printf("This patient is not at this hospital\n");
		return;
	}

	printf("Debug 2\n");

	prev_temp->NEXT = temp->NEXT;

	printf("Debug 3\n");
	free(temp);

	printf("Patient %d has been removed from hospital database\n", ppsNo);

} // void deletePatient()

void DeleteElementAtStart(struct patient** top)
{
	struct patient* temp;

	temp = *top;

	*top = temp->NEXT;

	free(temp);
} //void DeleteElementAtStart()*/

void orderByLastAppointment(struct patient* person, int spaces)
{
	int i, j;
	struct patient temp;
	bool swapped = false;

	printf("In order of their last appointment\n");

	// bubble sort algorithm for sorting appointment dates
	for (i = 0;i < spaces - 1;i++)
	{
		swapped = false;

		for (j = 0; j < spaces - 1 - i;j++) 
		{
			if ((person + j)->lastAppointmentYear < (person + j + 1)->lastAppointmentYear)
			{
				temp = person[j];
				person[j] = person[j + 1];
				person[j + 1] = temp;

				swapped = true;
			}
			else if ((person + j)->lastAppointmentMonth < (person + j + 1)->lastAppointmentMonth)
			{
				temp = person[j];
				person[j] = person[j + 1];
				person[j + 1] = temp;

				swapped = true;
			}
			else if ((person + j)->lastAppointmentDay < (person + j + 1)->lastAppointmentDay)
			{
				temp = person[j];
				person[j] = person[j + 1];
				person[j + 1] = temp;

				swapped = true;
			}
		} // for j
		
	} // for i

	// outputs patient details in order of their last appointments
	for (i = 0;i < spaces;i++)
	{
		if ((person + i)->ppsNum == 0) {
			printf("No patient at space %d \n", i + 1);
		}
		else {
			printf("PPS Number: %ld \n", (person + i)->ppsNum);
			printf("Full name: %s %s \n", (person + i)->firstName, (person + i)->lastName);
			printf("Year born: %d \n", (person + i)->yearBorn);
			printf("Gender: %s \n", (person + i)->gender);
			printf("Email address: %s \n", (person + i)->emailAddress);
			printf("Next of kin: %s \n", (person + i)->nextOfKin);
			printf("Last appointment date: %d %d %d \n", (person + i)->lastAppointmentDay, (person + i)->lastAppointmentMonth, (person + i)->lastAppointmentYear);
			printf("Weight: %.2lf \n", (person + i)->weight);
			printf("Height: %.2lf \n", (person + i)->height);
		}

	} // for output details

} // void orderByLastAppointment

int checkUser(logIn* user, int spaces)
{
	FILE* usernameFile;

	int i = 0;
	char usernameEntered[30];
	char passwordEntered[30];
	char ch;
	int numInput = 0;
	int tries = 0;

	printf("Please enter username: \n");
	scanf("%s", usernameEntered);

	printf("Please enter password: \n");

	// replaces letters of password entered with *
	while (i <= 30) 
	{
		passwordEntered[i] = getch();
		ch = passwordEntered[i];
		// if user hits return, exit while loop
		if (ch == 13) {
			break;
		}
		// if user hits backspace, delete letter
		else if (ch == 8) {
			passwordEntered[i--];
			printf("%s", "\b \b");
		}
		// else print asterisk instead of letter
		else {
			printf("*");
			i++;
		}
	}

	passwordEntered[i] = '\0';
	i = 0;
	printf("\n");

	usernameFile = fopen("logInDetails.txt", "r");

	if (usernameFile == NULL) 
	{
		printf("File for log in details could not be opened\n");
	}
	else 
	{
		while (!feof(usernameFile))
		{
			numInput = fscanf(usernameFile, "%s %s", (user)->username, (user)->password);
			if (numInput == 2)
			{
				// compare usernames and passwords
				if (strcmp((user)->username, usernameEntered) == 0 && strcmp((user)->password, passwordEntered) == 0) {
					printf("Log in details are correct\n");
					return;
				}
			} // if numInput

		} // while
		printf("Log in details incorrect\n");
		exit(0); // exits programme if log in details are incorrect
		
	} // else

	return 0;
} // int checkUser()

void reportFilePatientDetails(struct patient* person, int spaces)
{
	FILE* patientDetails;
	int i;

	patientDetails = fopen("patient.txt", "w");

	// prints all patient details to patient.txt
	for (i = 0;i < spaces;i++)
	{
		if ((person + i)->ppsNum == 0)
		{
			fprintf(patientDetails, "There is no patient occupying space %d\n", i + 1);
		}
		else
		{
			fprintf(patientDetails, "Patient at space %d: \n", i + 1);
			fprintf(patientDetails, "PPS Number: %ld \n", (person + i)->ppsNum);
			fprintf(patientDetails, "Full name: %s %s \n", (person + i)->firstName, (person + i)->lastName);
			fprintf(patientDetails, "Year born: %d \n", (person + i)->yearBorn);
			fprintf(patientDetails, "Gender: %s \n", (person + i)->gender);
			fprintf(patientDetails, "Email address: %s \n", (person + i)->emailAddress);
			fprintf(patientDetails, "Next of kin: %s \n", (person + i)->nextOfKin);
			fprintf(patientDetails, "Last appointment date: %d %d %d \n", (person + i)->lastAppointmentDay, (person + i)->lastAppointmentMonth, (person + i)->lastAppointmentYear);
			fprintf(patientDetails, "Weight: %.2lf \n", (person + i)->weight);
			fprintf(patientDetails, "Height: %.2lf \n", (person + i)->height);

		}
	}
	fclose(patientDetails);

	printf("All patient details have been reported to the patient.txt file\n");
} // void reportFilePatientDetails()