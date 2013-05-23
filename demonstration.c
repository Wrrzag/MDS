#include "mlist.h"

#include <stdio.h>

void print_list(MList *list)
{
	int i, j;
	int size = get_size(list);
	for(i=0; i<size; i++)
	{
		j = retrieve_element(list, (void *)i);
		printf("Node %d in list: %d\n", i, j);
	}
}

int main(void)
{
	printf("Creating list\n");
	MList *list = create_list();
	printf("List created\n");

	printf("Adding elements\n");
	int i;
	for(i=0; i<10; i++)
	{
		add_element(list, i);
	}
	printf("Elements added\n");

	int list_size = get_size(list);
	printf("List size: %d\n", list_size);

	int first_elem = get_first_element(list);
	printf("First element: %d\n", first_elem);

	print_list(list);

	if(contains(list, 3))
	{
		printf("the list contains the number 3\n");
	}
	else
	{
		printf("the list does not contain the number 3\n");
	}
	if(!contains(list, -3))
	{
		printf("the list does not contain the number -3\n");
	}

	printf("Deleting list\n");
	delete_list(list);
	printf("List deleted\n");

	return 0;
}
