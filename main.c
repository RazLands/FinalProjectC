#include <stdio.h>
#include <time.h>
#include "functions.h"

#define ACCESS_PATH "access.txt"
/***
* This is the path where the access file is located.
* When you submit the program make sure this path match to: "access.txt"
***/
#define REAQUESTS_PATH "requests.txt"
/***
* This is the path where the requests file is located.
* When you submit the program make sure this path match to: "requests.txt"
***/
#define LOG_PATH "log.txt"
/***
* This is the path where the log file is located.
* When you submit the program make sure this path match to: "log.txt"
***/

void main() {
	list *accs_lst = (list *)malloc(sizeof(list));
	list *srch_list = (list*)malloc(sizeof(list));
	list *log_lst = (list*)malloc(sizeof(list));
	list *rqst_lst = (list*)malloc(sizeof(list));
	int option, action, srch_status;
	// *temp;
	char *updt_name = (char*)malloc(sizeof(char));
	char srch_name[21], srch_code[9];

	init_list(accs_lst);
	init_list(srch_list);
	init_list(log_lst);
	init_list(rqst_lst);
	readAccess(ACCESS_PATH, accs_lst);
	//print(ACCESS_PATH, accs_lst);
	readRequsts(REAQUESTS_PATH, rqst_lst);
	//print(REAQUESTS_PATH, rqst_lst);
	writeToLogFile(LOG_PATH, log_lst);

	checkRequest(accs_lst, rqst_lst);
	/* Display Menu */
	while (1) {
		// Operations menu
		{
			printf("\n *  *  *  *  *  *  *  *  *  *  *  *  *\n");
			printf("\n *  Operations menu                  *\n");
			printf("\n *  1. Search for user               *\n");
			printf("\n *  2. Add new user                  *\n");
			printf("\n *  3. Update user permissions       *\n");
			printf("\n *  4. Print log file                *\n");
			printf("\n *  5. Print user list (acsess.txt)  *\n");
			printf("\n *  6. Check security system         *\n");
			printf("\n *  7. Quit                          *\n");
			printf("\n *  *  *  *  *  *  *  *  *  *  *  *  *\n");
			printf("\n Please select your action [1-6]. Exit [7]:");
		}
		/*if (scanf("%d", &option) != 1) {
			printf(" *Error: Invalid input. Try again.\n");
			scanf("%s", &temp); //clear input buffer
			continue;
		}*/
		scanf("%d", &option);
		switch (option) {

			// Search for user by its name(s) (1) or ststus (2) or code (3)
		case 1: {
			printf("Choose searching by user NAME (1) or STATUS (2) or CODE (3): ");
			scanf("%d", &action);

			// Search a user by user NAME
			if (action == 1) {
				printf("Enter the NAME you want to search for: ");
				scanf("%20s", srch_name);
				srch_list = search(accs_lst, srch_name, 0, "");
				print(ACCESS_PATH, srch_list);
			}

			// Search a user by user STATUS
			else if (action == 2) {
				printf("Enter the STATUS you want to search for: ");
				scanf("%d", &srch_status);
				srch_list = search(accs_lst, "", srch_status, "");
				print(ACCESS_PATH, srch_list);
			}

			// Search a user by user CODE
			else if (action == 3) {
				printf("Enter the CODE you want to search for: ");
				scanf("%8s", &srch_code);
				srch_list = search(accs_lst, "", 0, srch_code);
				print(ACCESS_PATH, srch_list);
			}
			break;
		}

				// add new user
		case 2: {
			AddUser(accs_lst);
			writeToFile(ACCESS_PATH, accs_lst);
			print(ACCESS_PATH, accs_lst);

			break;
		}

				// Update user's permissions
		case 3: {
			printf("Type '1' (name) or '2' (code) to choose which user to update. Type '3' to see current users list: ");
			scanf("%d", &action);

			// Print the current users list to the console
			if (action == 3) {
				print(ACCESS_PATH, accs_lst);
				//getch();
				printf("Type '1' (name) or '2' (code) to choose which user to update: ");
				scanf("%d", &action);
			}

			// Update user by its user NAME
			if (action == 1) {
				printf("Enter a user NAME to update: ");
				scanf("%s", srch_name);

				printf("Choose which paramet to update: STATUS (1), TIME RANGE (2): ");
				scanf("%d", &option);

				// Find user by its NAME and update his permissions status 
				if (option == 1) {
					printf("Enter the new status permission for user %s: ", srch_name);
					scanf("%d", &srch_status);
					updateUser(ACCESS_PATH, accs_lst, srch_name, srch_status, "");
				}

				// Find user by its NAME and update user's date and time range permission
				if (option == 2) {
					updateUser(ACCESS_PATH, accs_lst, srch_name, 0, "");
				}
			}

			// Update user by its user CODE
			else if (action == 2) {
				printf("Enter a user CODE to update: ");
				scanf("%s", srch_code);
				printf("Choose which paramet to update: STATUS (1), TIME RANGE (2): ");
				scanf("%d", &option);

				// Find user by its NAME and update his permissions status 
				if (option == 1) {
					printf("Enter the new status permission for user code %s: ", srch_code);
					scanf("%d", &srch_status);
					updateUser(ACCESS_PATH, accs_lst, "", srch_status, srch_code);
				}
				// Find user by its NAME and update user's date and time range permission
				if (option == 2) {
					updateUser(ACCESS_PATH, accs_lst, "", 0, srch_code);
				}
			}

			break;
		}

				// Print log file to the console
		case 4: {
			print(LOG_PATH, log_lst);
			break;
		}

				// Print access file to the console
		case 5: {
			print(ACCESS_PATH, accs_lst);
			break;
		}

		case 6: {
			return(0);
			break;
		}

				// Exit program
		case 7: {// Exit
			free(accs_lst);
			free(srch_list);
			free(rqst_lst);
			free(log_lst);
			free(updt_name);
			return(0);
			break;
		}
		default:
			printf("Invalid Option. Please Try again.");
			getch();
		} // End of Switch
	} // End of While
	return(0);

	system("pause");
}