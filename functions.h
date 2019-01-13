#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Node Stucture */
typedef char list_type;

typedef struct user_data
{
	char *name[21];
	char *code[9];
	char *date_s[11];
	char *date_e[11];
	char *time_s[6];
	char *time_e[6];
	char *status[2];
}User;

typedef struct node
{
	//list_type value;	
	User data;
	struct node *next;
	struct node *prev;
}Node;


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
Node * insert_bottom(User *data, Node *head) {
	Node *current_node = head;
	Node *new_node;
	while (current_node != NULL && current_node->next != NULL) {
		current_node = current_node->next;
	}

	new_node = (Node *)malloc(sizeof(Node));
	new_node->data = *data;
	new_node->next = (Node *)malloc(sizeof(Node));

	

	if (current_node != NULL) {
		current_node = new_node;
		new_node->prev = current_node;
		current_node = new_node->next;
		current_node = new_node->prev;
		//current_node->next = new_node;
		head = current_node;
	}
	else {
		current_node = new_node;
		new_node->prev = current_node;
		current_node = new_node->next;
		current_node = new_node->prev;
		head = current_node;
	}
	//current_node = current_node->next
	return head;
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