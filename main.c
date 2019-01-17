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

void getDateTime(int *day, int *month, int *year, int *hours, int *mins)
{
	/***
	* Handle function: Returns by referfance the current date and time
	***/
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

void main() {
	list *lst = (list *)malloc(sizeof(list));
	init_list(lst);
	int option, srch_action, srch_status;
	char * temp;
	char srch_name[21];

	readAccess(ACCESS_PATH, lst);

	/* Display Menu */
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
		case 1:        // Search for user by its name(s) (press 1) or ststus (2)
			printf("Choose searching by user NAME (1) or STATUS (2): ");
			scanf("%d", &srch_action);
			if (srch_action == 1) {
				printf("Enter the NAME you want to search for: ");
				scanf("%20s", srch_name);
				search(ACCESS_PATH, lst, srch_name, 0);
			}
			else if (srch_action == 2) {
				printf("Enter the STATUS you want to search for: ");
				scanf("%d", &srch_status);
				search(ACCESS_PATH, lst, "", srch_status);
			}
			break;
		case 2:    // add new user
			AddUser(lst);
			print(ACCESS_PATH, lst);
			break;
/*		case 3:    // Insert After
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
*/		default:
			printf("Invalid Option. Please Try again.");
			getch();
		} // End of Switch
	} // End of While
	return(0);


	//newUser = addUser(NULL);
	//printf("%s", newUser->user.name);
	//printf("hi");

	//scanf("%d", &);

	system("pause");
}