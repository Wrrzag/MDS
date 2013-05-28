#include "mlist.h"

#include <stdlib.h>
#include <string.h>

/**
Struct definition
**/
typedef struct _mnode
{
	struct _mnode *next;
	void *data;
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
MNode *create_node(void*, size_t);

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

void add_element(MList *list, void *element, size_t size)
{
	MNode *node = create_node(element, size);

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

int contains(MList *list, void *element)
{
	MNode *node;

	for(node = list->head; node != NULL; node = node->next)
	{
		if(node->data == element)
		{
			return 1;
		}
	}

	return 0;
}

void *retrieve_element(MList *list, int element)
{
	int i;
	MNode *node = list->head;

	for(i=0; i<element; i++)
	{
		node = node->next;
	}

	return node->data;
}

void delete_element(MList *list, void *data, int (*cmp_funct)(void*, void*))
{
  MNode *node, *prev;

  for(node = prev = list->head; node != NULL; prev = node, node = node->next)
  {
    if((*cmp_funct)(node->data, data))
    {
      if(list->head == node)
      {
        if(node->next != NULL)
        {
          list->head = node->next;
          free(node);
          node = NULL;
        }
        else
        {
          free(node);
          list->head = list->tail = node = NULL;
        }
      }
      else if(list->tail == node)
      {
        list->tail = prev;
        free(node);
        prev->next = node = NULL;
      }
      else
      {
        prev->next = node->next;
        free(node);
        node = NULL;
      }

      list->size--;
      break;
    }
  }
}

void *get_first_element(MList *list)
{
	return list->head ? list->head->data : NULL;
}

int get_size(MList *list)
{
	return list->size;
}

/****/
MNode *create_node(void *element, size_t size)
{
	MNode *node = malloc(sizeof(MNode));
  node->data = malloc(size);
  memcpy(node->data, element, size);
	node->next = NULL;

	return node;
}
