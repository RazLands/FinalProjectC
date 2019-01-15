#include <stdio.h>
#include <time.h>
#include "functions.h"

#define ACCESS_PATH "access.txt"
/***
* This is the path where the access file is located.
* When you submit the program make sure this path match to: "c:\\temp\\access.txt"
***/

#define LOG_PATH "log.txt"
/***
* This is the path where the log file is located.
* Open this file and append new records into it.
* When you submit the program make sure this path match to: "c:\\temp\\log.txt"
***/

void readAccess(char *path, Node *head) //list *lst); // 
/***
* Handle function: get's the path of the access file, and print all users information.
* You may change it according to your needs.
***/

void getDateTime(int *day, int *month, int *year, int *hours, int *mins);
/***
* Handle function: Returns by referfance the current date and time
***/


void readAccess(char *path, Node *head) //list *lst) // 
{
	FILE *fp;
	char temp[70], name[21], code[9], status[2], date_s[11], date_e[11], time_s[6], time_e[6];
	User d;
	
	fp = fopen(path, "rb"); //Reads all the data from the file and put it in fp
	if (!fp)
	{
		printf("File not found!\n");
		return;
	}

	fgets(temp, 70, fp); //Cuts off the first line (headlines) from fp

	while (fscanf(fp, "%20s %8s %1s %10s %10s %5s %5s %5d", name, code, status, date_s, date_e, time_s, time_e) != EOF)
	{
		strcpy(d.name, name);
		strcpy(d.code, code);
		strcpy(d.status, status);
		strcpy(d.date_s, date_s);
		strcpy(d.date_e, date_e);
		strcpy(d.time_s, time_s);
		strcpy(d.time_e, time_e);
	
		printf(
			"First Print:\nname: %s, code: %s, status: %s, date_s: %s, date_e: %s, time_s: %s, time_e: %s\n", 
			d.name,
			d.code,
			d.status,
			d.date_s,
			d.date_e,
			d.time_s,
			d.time_e		
		);

		insert_bottom(d, &head);
		//insertLast(lst, d);
		
	}

	fclose(fp);
	return head;
	//return lst;
}


void getDateTime(int *day, int *month, int *year, int *hours, int *mins)
{
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	*day = timeinfo->tm_mday;
	*month = timeinfo->tm_mon + 1;
	*year = timeinfo->tm_year + 1900;
	*hours = timeinfo->tm_hour;
	*mins = timeinfo->tm_min;
}

/*
node *addUser(node *user) {
	printf("Enter Name And Code: ");
	char input[16];
	fgets(input, 15, stdin);

	node *newUser = malloc(sizeof(node));
	sscanf(input, "%s %s", newUser->user.name, newUser->user.code);
	printf("Added:%s Code:%s\n\n", newUser->user.name, newUser->user.code);
	newUser->next = NULL;
	if (user != NULL) {
		user->next = newUser;
	}

	return newUser;
}*/


void main() {

	Node *head = (Node *)malloc(sizeof(Node));
	head = NULL;
	//list *lst = (list *)malloc(sizeof(list));
	//lst->head = NULL;
	//lst->tail = NULL;
	int option;
	char * temp;

	readAccess(ACCESS_PATH, head);
	//readAccess(ACCESS_PATH, lst);



	/* Display Menu
	while (1) {

		printf("\n *************\n");
		printf("\n *  Linked list operations:        *\n");
		printf("\n *  1. Insert at the top of list   *\n");
		printf("\n *  2. Insert at bottom of list    *\n");
		printf("\n *  3. Insert after an element     *\n");
		printf("\n *  4. Insert before an element    *\n");
		printf("\n *  5. Show all elements           *\n");
		printf("\n *  6. Quit                        *\n");
		printf("\n *************\n");
		printf("\n Choose an option [1-5] : ");
		if (scanf("%d", &option) != 1) {
			printf(" *Error: Invalid input. Try again.\n");
			scanf("%s", &temp); //clear input buffer
			continue;
		}

		switch (option) {
		case 1:        // Add to top
			printf(" Enter a number to insert : ");
			if (scanf("%d", &num) != 1) {
				printf(" *Error: Invalid input.\n");
				scanf("%s", &temp);   //clear input buffer
				continue;
			}
			head = insert_top(num, head);
			printf("Number %d added to the top of the list", num);
			printf("\nPress any key to continue...");
			getch();
			break;

		case 2:    // add to bottom
			printf(" Enter a number to insert : ");
			if (scanf("%d", &num) != 1) {
				printf(" *Error: Invalid input. \n");
				scanf("%s", &temp);
				continue;
			}
			head = insert_bottom(num, head);
			printf("%d added to the bottom of the list", num);
			printf("\nPress any key to continue...");
			getch();
			break;

		case 3:    // Insert After
			printf(" Enter a number to insert : ");
			if (scanf("%d", &num) != 1) {
				printf(" *Error: Invalid input.\n");
				scanf("%s", &temp);
				continue;
			}

			printf(" After which number do you want to insert : ");
			if (scanf("%d", &prev_num) != 1) {
				printf(" *Error: Invalid input.\n");
				scanf("%s", &temp);
				continue;
			}
			if (head != NULL) {
				head = insert_after(num, prev_num, head);
				printf("%d is inserted after %d", num, prev_num);
			}
			else {
				printf("The list is empty", num, prev_num);
			}
			printf("\nPress any key to continue...");
			getch();
			break;

		case 4:    // Insert Before
			printf(" Enter a number to insert : ");
			if (scanf("%d", &num) != 1) {
				printf(" *Error: Invalid input. \n");
				scanf("%s", &temp);
				continue;
			}

			printf(" Before which number do you want to insert : ");
			if (scanf("%d", &prev_num) != 1) {
				printf(" *Error: Invalid input.\n");
				scanf("%s", &temp);
				continue;
			}

			if (head != NULL) {
				head = insert_before(num, prev_num, head);
				printf("Number %d inserted before %d", num, prev_num);
			}
			else {
				printf("The list is empty", num, prev_num);
			}
			printf("\nPress any key to continue...");
			getch();
			break;

		case 5: // Show all elements
			printf("\nElements in the list: \n [ ");
			print(head);
			printf("]\n\nPress any key to continue...");
			getch();
			break;

		case 6:  // Exit
			return(0);
			break;

		default:
			printf("Invalid Option. Please Try again.");
			getch();

		} // End of Switch
	} // End of While

	return(0);
	*/
	

	//newUser = addUser(NULL);
	//printf("%s", newUser->user.name);
	//printf("hi");

	//scanf("%d", &);

	//print(head);



	//system("pause");
}