#include "mlist.h"

#include <stdio.h>

void print_list(MList *list)
{
	int i;
	int size = get_size(list);
  float *j;
	for(i=0; i<size; i++)
	{
		j = retrieve_element(list, i);
		printf("Node %d in list: %f\n", i, *j);
	}
}

int main(void)
{
	printf("Creating list\n");
	MList *list = create_list();
	printf("List created\n");

	printf("Adding elements\n");
	float i;
	for(i=0; i<10.0; i++)
	{
		add_element(list, &i, sizeof(float));
	}
	printf("Elements added\n");

	int list_size = get_size(list);
	printf("List size: %d\n", list_size);

	float *first_elem = get_first_element(list);
	printf("First element: %f\n", *first_elem);

	print_list(list);

	printf("Deleting list\n");
	delete_list(list);
	printf("List deleted\n");

	return 0;
}
