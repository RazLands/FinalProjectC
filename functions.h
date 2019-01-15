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
	char status[2];
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

/* Add a new node to the bottom of a list */
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
		current_node->next = *&new_node;
	}
	else {
		*head = new_node;
	}
	
}

int isEmpty(list *lst)
{
	return lst->head == NULL;
}

void insertLast(list *lst, User data)
{
	//create a new link
	Node *link = (Node*)malloc(sizeof(Node));
	Node *current = lst;
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


/* Print all the elements in the linked list */
void print(Node *head) {
	Node *current_node = head;
	while (current_node != NULL) {
		printf("%s ", current_node->data.name);
		printf("%s ", current_node->data.code);
		printf("%d ", current_node->data.status);
		printf("%s ", current_node->data.date_s);
		printf("%s ", current_node->data.date_e);
		printf("%s ", current_node->data.time_s);
		printf("%s ", current_node->data.time_e);
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