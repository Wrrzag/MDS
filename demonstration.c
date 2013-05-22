#include "mlist.h"

#include <stdio.h>

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

	int j;
	for(i=0; i<10; i++)
	{
		j = retrieve_element(list, i);
		printf("Node in list: %d\n", j);
	}

	j=retrieve_element(list, 1);

	printf("Deleting list\n");
	delete_list(list);
	printf("List deleted\n");

	return 0;
}
