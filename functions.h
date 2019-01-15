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
	struct Node *next;
	struct Node *prev;
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
	//Node *current = lst;
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
int insertAfter(list *lst, User data, int idx)
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








/* Add a new node to the top of a list
Node * insert_top(User data, Node *head) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
	return head;
}
*/

/* Add a new node to the bottom of a list
void insert_bottom(User data, Node **head) {
	Node *current_node = *head;
	Node *new_node;
	while (current_node != NULL && current_node->next != NULL) {
		current_node = current_node->next;
	}
	new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	if (current_node != NULL) {
		new_node->prev = current_node;
		current_node->next = new_node;
	}
	else {
		*head = new_node;
	}
}
/* Add a new node after an element in the list
Node * insert_after(int num, int prev_num, Node *head) {
	Node *current_node = head;
	Node *new_node;
	while (current_node->data != prev_num) {
		current_node = current_node->next;
	}
	new_node = (Node *)malloc(sizeof(Node));
	new_node->data = num;
	new_node->next = current_node->next;
	current_node->next = new_node;
	return head;
}
/* Add a new node before an element in the list
Node * insert_before(int num, int next_num, Node *head) {
	Node *current_node = head;
	Node *new_node;
	while (&current_node->next->data != next_num) {
		current_node = current_node->next;
	}
	new_node = (Node *)malloc(sizeof(Node));
	new_node->data = num;
	new_node->next = current_node->next;
	current_node->next = new_node;
	return head;
}*/