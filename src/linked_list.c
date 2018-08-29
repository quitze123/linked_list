#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
	struct node * prev;
	
}node;

void insert_at_front(node ** head, node ** tail, int value)
{
	node * new_node = NULL;
	if(head == NULL || tail == NULL)
	{
		return;
	}
	
	new_node = calloc(1, sizeof(node));
	
	if(new_node == NULL)
	{
		perror("calloc(...) failed");
		exit(EXIT_FAILURE);
	}
	
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	if(*head == NULL)
	{
		(*head) = new_node;
		(*tail) = new_node;
	}
	else
	{
		(*head)->prev = new_node;
		new_node->next = *head;
		*head = new_node;
	}
	
}

void insert_at_end(node ** head, node ** tail, int value)
{
	node * new_node = NULL;
	node * temp = NULL;
	
	if(head == NULL || tail == NULL)
	{
		return;
	}
	
	new_node = calloc(1, sizeof(node));
	
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	if(*head == NULL)
	{
		(*head) = new_node;
		(*tail) = new_node;
	}
	else
	{
		(*tail)->next = new_node;
		new_node->prev = (*tail);
		(*tail) = new_node;
	}
}

void print_list(node * head, node * tail, int size)
{
	int i = 0;
	node * temp = head;
	while(temp != NULL)
	{
		printf("%i\n", temp->data);
		temp = temp->next;
	}
	
	temp = tail;
	while(temp != NULL)
	{
		printf("%i\n", temp->data);
		temp = temp->prev;	
	}
}

void free_list(node * head)
{
	node * temp = head;
	while(head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

int main(void)
{
	node * head = NULL;
	node * tail = NULL;
	
	int data[10] = {1,45,232,6566,6776,732,1121,11,343,4443};
	int size = 10;
	int i = 0;
	
	for(i = 0; i < size; i++)
	{
		insert_at_end(&head, &tail, data[i]);
	}
	
	print_list(head, tail, size);
	free_list(head);
	
	
	return 0;
}