#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Node Stucture */
typedef char list_type;

typedef struct user_data
{
	char name[21];
	char code[9];
	char date_s[11];
	char date_e[11];
	char time_s[6];
	char time_e[6];
	int status;
}User;

typedef struct node
{
	//list_type value;	
	User data;
	struct node *next;
	struct node *prev;
}Node;

typedef struct list
{
	Node *head;
	Node *tail;
}list;

void init_list(list *lst)
{
	lst->head = lst->tail = NULL;
}

int isEmpty(list *lst)
{
	return lst->head == NULL;
}

int length(list *lst)
{
	int length = 0;
	Node *current;

	for (current = lst->head; current != NULL; current = current->next)
		length++;

	return length;
}

//insert link at the first location
void insertFirst(list *lst, User data)
{
	//create a new link
	Node *link = (Node*)malloc(sizeof(Node));
	link->data = data;
	link->next = NULL;
	link->prev = NULL;

	if (isEmpty(lst))
	{
		//make head & tail pointing to link
		lst->head = lst->tail = link;
	}
	else
	{
		//update first prev link
		lst->head->prev = link;
		//point it to old first link
		link->next = lst->head;
		//point first to new first link
		lst->head = link;
	}
}

void insertLast(list *lst, User data)
{
	//create a new link
	Node *link = (Node*)malloc(sizeof(Node));
	link->data = data;
	link->next = NULL;
	link->prev = NULL;

	if (isEmpty(lst))
	{
		//make head & tail pointing to link
		lst->head = lst->tail = link;
	}
	else
	{
		//make link a new last link
		lst->tail->next = link;
		//mark old last node as prev of new link
		link->prev = lst->tail;
		//point last to new last node
		lst->tail = link;
	}
}

/*
//delete first item
int deleteFirst(list *lst)
{
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to first link
		Node *temp = lst->head;
		//if only one link
		if (temp->next == NULL)
		{
			init_list(lst);
		}
		else
		{
			lst->head->next->prev = NULL;
			lst->head = lst->head->next;
		}
		free(temp);
		return 1;
	}
	return 0;
}
/*
//delete link at the last location
int deleteLast(list *lst)
{
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to last link
		Node *temp = lst->tail;
		//if only one link
		if (temp->prev == NULL)
		{
			init_list(lst);
		}
		else
		{
			lst->tail->prev->next = NULL;
			lst->tail = lst->tail->prev;
		}
		free(temp);
		return 1;
	}
	return 0;
}
//delete a link at spesific index
int deleteLink(list *lst, int idx)
{
	if (!isEmpty(lst))
	{
		int i;
		//start from the first link
		Node* current = lst->head;
		//navigate through list
		for (i = 0; i < idx && current != NULL;i++)
			current = current->next;
		if (current == NULL)
			return 0;
		if (current == lst->head)
			return deleteFirst(lst);
		if (current == lst->tail)
			return deleteLast(lst);
		//bypass the current link
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
		return 1;
	}
	return 0;
}
*/

int insertAfter(list *lst, User data, int idx)
{
	if (!isEmpty(lst))
	{
		int i;
		//start from the first link
		Node* current = lst->head;
		Node *newLink = NULL;
		//navigate through list
		for (i = 0; i < idx && current != NULL;i++)
			current = current->next;
		if (current == NULL)
			return 0;
		if (current == lst->tail)
		{
			insertLast(lst, data);
			return 1;
		}
		//create a link
		newLink = (Node*)malloc(sizeof(Node));
		newLink->data = data;
		//assign new link pointers
		newLink->prev = current;
		newLink->next = current->next;
		//chain current and current->next to new link
		current->next->prev = newLink;
		current->next = newLink;
		return 1;
	}
	return 0;
}

int insertBefore(list *lst, User data, int idx)
{
	if (!isEmpty(lst))
	{
		int i;
		//start from the first link
		Node* current = lst->head;
		Node* newLink = NULL;
		//navigate through list
		for (i = 0; i < idx && current != NULL;i++)
			current = current->next;
		if (current == NULL)
			return 0;
		if (current == lst->head)
		{
			insertFirst(lst, data);
			return 1;
		}
		//create a link
		newLink = (Node*)malloc(sizeof(Node));
		newLink->data = data;
		//assign new link pointers
		newLink->next = current;
		newLink->prev = current->prev;
		//chain current and current->prev to new link
		current->prev->next = newLink;
		current->prev = newLink;
		return 1;
	}
	return 0;
}
/* Print all the elements in the linked list */

void print(list *lst) { //Node *head) {
	Node *current_node = lst->head;
	while (current_node != NULL) {
		printf("%s ", current_node->data.name);
		printf("%s ", current_node->data.code);
		printf("%d ", current_node->data.status);
		printf("%s ", current_node->data.date_s);
		printf("%s ", current_node->data.date_e);
		printf("%s ", current_node->data.time_s);
		printf("%s ", current_node->data.time_e);
		printf("\n");
		current_node = current_node->next;
	}
}

void readAccess(char *path, list *lst) // Node *head) // 
{
	/***
	* Handle function: get's the path of the access file, and print all users information.
	* You may change it according to your needs.
	***/
	FILE *fp;
	char temp[70], name[21], code[9], date_s[11], date_e[11], time_s[6], time_e[6];
	int status;

	User d;

	fp = fopen(path, "rb"); //Reads all the data from the file and put it in fp
	if (!fp)
	{
		printf("File not found!\n");
		return;
	}

	fgets(temp, 70, fp); //Cuts off the first line (headlines) from fp

	while (fscanf(fp, "%20s %8s %1d %10s %10s %5s %5s %5d", name, code, &status, date_s, date_e, time_s, time_e) != EOF)
	{
		strcpy(d.name, name);
		strcpy(d.code, code);
		d.status = status;
		strcpy(d.date_s, date_s);
		strcpy(d.date_e, date_e);
		strcpy(d.time_s, time_s);
		strcpy(d.time_e, time_e);

		//insert_bottom(d, &head);
		insertLast(lst, d);

	}
	print(lst);
	fclose(fp);
	return lst;
	//return lst;
}

void AddUser(list *new)
{
	int status, count, check;
	User data;
	Node *newuser = (Node*)malloc(sizeof(Node));
	Node *cmpuser = new->head;
	printf("Enter user name: ");
	scanf("%s", newuser->data.name);
	printf("Enter user code: ");
	scanf("%s", newuser->data.code);
	printf("Enter user entrance status: ");
	scanf("%d", &status);
	newuser->data.status = status;
	printf("Enter user permission start date: ");
	scanf("%s", newuser->data.date_s);
	printf("Enter user permission end date: ");
	scanf("%s", newuser->data.date_e);
	printf("Enter user permission start time: ");
	scanf("%s", newuser->data.time_s);
	printf("Enter user permission start time: ");
	scanf("%s", newuser->data.time_e);
	count = check = 0;
	while (cmpuser != NULL)
	{
		if (strcmp(cmpuser->data.code, newuser->data.code) > 0) {
			insertBefore(new, newuser->data, count);
			check = 1;
			break;
		}
		count++;
		cmpuser = cmpuser->next;
	}
	if (check == 0)
		insertLast(new, newuser->data);
}

void search(list *lst, char *name, int status) {
	Node *current_node = lst->head;
	list *srch_list = (list *)malloc(sizeof(list));
	init_list(srch_list);

	if (isEmpty(lst)) {
		return;
	}

	while (current_node != NULL) {
		if (strcmp(current_node->data.name,name) == 0 || current_node->data.status == status)
			insertLast(srch_list, current_node->data);
		current_node = current_node->next;
	}
	print(srch_list);
	return srch_list;
}

int countLines(FILE *fp)
{
	//FILE *f = fopen(filename, "r");
	int c;
	int count = 0;
	if (!fp)
		return -1;
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n')
			count++;
	fclose(fp);
	return count;
}