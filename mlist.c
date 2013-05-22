#include "mlist.h"

#include <stdlib.h>

/**
Struct definition
**/
typedef struct _mnode
{
	struct _mnode *next;
	//void *info;
	int info;
} MNode;

typedef struct _mlist
{
	MNode *head;
	MNode *tail;
	int size;
} MList;

/**
Private methods declaration
**/
MNode *create_node(int);

/**
List handling methods
**/
MList *create_list()
{
	MList *new_list = malloc(sizeof(MList));
	new_list->size = 0;
	new_list->head = new_list->tail = NULL;

	return new_list;
}

void delete_list(MList *list)
{
	free(list);
}

void add_element(MList *list, int element)
{
	int i;
	MNode *node = create_node(element);

	if(list->head == NULL)
	{
		list->head = list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}

	list->size++;
}

int contains(MList *list, int element)
{
	MNode *node;

	for(node = list->head; node != NULL; node = node->next)
	{
		if(node->info == element)
		{
			return 1;
		}
	}

	return 0;
}

int retrieve_element(MList *list, int element)
{
	int i;
	MNode *node = list->head;

	for(i=0; i<element; i++)
	{
		node = node->next;
	}

	return node->info;
}

int get_first_element(MList *list)
{
	return list->head->info;
}

int get_size(MList *list)
{
	return list->size;
}

/****/
MNode *create_node(int element)
{
	MNode *node = malloc(sizeof(MNode));
	node->info = element;
	node->next = NULL;

	return node;
}
