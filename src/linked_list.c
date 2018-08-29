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
	
	if(head == NULL)
		return;
	
	node * temp = head;
	while(temp != NULL)
	{
		printf("%i\n", temp->data);
		temp = temp->next;
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

void remove_node(node ** head, node ** tail, int value)
{
	node * temp = (*head);
	
	if(head == NULL)
		return;
	if((*head) == NULL)
		return;
	
	while(temp != NULL)
	{
		if(temp->data == value)
		{
			if(temp->next == NULL && temp->prev == NULL)
			{
				free(*head);
				*head = NULL;
			}
			else if(temp->next == NULL)
			{
				(*tail) = temp->prev;
				free(temp);
				(*tail)->next = NULL;
			}
			else if(temp->prev == NULL)
			{
				(*head) = temp->next;
				(*head)->prev = NULL;
				free(temp);
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(temp);
			}
			return;
		}
		temp = temp->next;
	}
}

int main(void)
{
	node * head = NULL;
	node * tail = NULL;
	
	int data[10] = {-67,45,232,6566,6776,732,1121,11,343,4443};
	int size = 10;
	int i = 0;
	
	for(i = 0; i < size; i++)
	{
		insert_at_end(&head, &tail, data[i]);
	}
	
	print_list(head, tail, size);
	for(i = 0; i < size; i++)
	{
		remove_node(&head, &tail, data[i]);
	}
	print_list(head, tail, size);
	free_list(head);
	
	
	return 0;
}