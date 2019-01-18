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
	list *srch_list = (list *)malloc(sizeof(list));
	int option, action, srch_status, result;
	char *temp = (char*)malloc(sizeof(char));;
	char *updt_name = (char*)malloc(sizeof(char));
	char srch_name[21], srch_code[9];

	init_list(lst);
	init_list(srch_list);
	readAccess(ACCESS_PATH, lst);

	/* Display Menu */
	while (1) {
		printf("\n *************\n");
		printf("\n *  Linked list operations:        *\n");
		printf("\n *  1. SEARCH USER/STATUS   *\n");
		printf("\n *  2. ADD NEW USER    *\n");
		printf("\n *  3.      *\n");
		printf("\n *  4.     *\n");
		printf("\n *  5.            *\n");
		printf("\n *  6. Quit                        *\n");
		printf("\n *************\n");
		printf("\n Choose an option [1-5]. Exit [6]: ");
		if (scanf("%d", &option) != 1) {
			printf(" *Error: Invalid input. Try again.\n");
			scanf("%s", &temp); //clear input buffer
			continue;
		}
		switch (option) {
		
		// Search for user by its name(s) (type 1) or ststus (type 2)
		case 1:  {      
			printf("Choose searching by user NAME (1) or STATUS (2) or CODE (3): ");
			scanf("%d", &action);

			// Search a user by user NAME
			if (action == 1) {
				printf("Enter the NAME you want to search for: ");
				scanf("%20s", srch_name);
				srch_list = search(ACCESS_PATH, lst, srch_name, 0, "");
				print(ACCESS_PATH, srch_list);
			}

			// Search a user by user STATUS
			else if (action == 2) {
				printf("Enter the STATUS you want to search for: ");
				scanf("%d", &srch_status);
				srch_list = search(ACCESS_PATH, lst, "", srch_status, "");
				print(ACCESS_PATH, srch_list);
			}

			// Search a user by user CODE
			else if (action == 3) {
				printf("Enter the CODE you want to search for: ");
				scanf("%8s", &srch_code);
				srch_list = search(ACCESS_PATH, lst, "", 0, srch_code);
				print(ACCESS_PATH, srch_list);
			}
			break;
		}
		
		// add new user
		case 2: {   
			AddUser(lst);
			writeToFile(ACCESS_PATH, lst);
			print(ACCESS_PATH, lst);
			break;
		}

		// Update user's permissions
		case 3: {
			printf("Type '1' (name) or '2' (code) to choose which user to update. Type '3' to see current users list: ");
			scanf("%d", &action);

			// Print the current users list to the console
			if (action == 3) {
				print(ACCESS_PATH, lst);
				//getch();
				printf("Type '1' (name) or '2' (code) to choose which user to update: ");
				scanf("%d", &action);
			}

			// Update user by its user NAME
			if (action == 1) {
				printf("Enter a user NAME to update: ");
				scanf("%s", srch_name);

				printf("Choose which paramet to update: STATUS (1), TIME RANGE (2): ");
				scanf("%d", &action);

				// Find user by its NAME and update his permissions status 
				if (action == 1) {
					printf("Enter the new status permission for user %s: ", srch_name);
					scanf("%d", &srch_status);
					updateUser(ACCESS_PATH, lst, srch_name, srch_status, "");
				}

				// Find user by its NAME and update user's date and time range permission
				if (action == 2) {
					updateUser(ACCESS_PATH, lst, srch_name, 0, "");
				}
			}

			// Update user by its user CODE
			else if (action == 2) {
				printf("Enter a user CODE to update: ");
				scanf("%s", srch_code);
				printf("Choose which paramet to update: STATUS (1), TIME RANGE (2): ");

				// Find user by its NAME and update his permissions status 
				if (scanf("%d", &action) == 1) {
					printf("Enter the new status permission for user %s: ", srch_name);
					scanf("%d", &srch_status);
					updateUser(ACCESS_PATH, lst, "", srch_status, srch_code);
				}
				// Find user by its NAME and update user's date and time range permission
				if (scanf("%d", &action) == 2) {
					updateUser(ACCESS_PATH, lst, "", 0, srch_code);
				}
			}



			break;
		}

/*		case 4:    // Insert Before
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
			break;*/
		case 6:  // Exit
			return(0);
			break;
		default:
			printf("Invalid Option. Please Try again.");
			getch();
		} // End of Switch
	} // End of While
	return(0);

	//system("pause");
}