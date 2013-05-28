#include <stdlib.h>

typedef struct _mlist MList;
typedef struct _mnode MNode;

MList *create_list();
void delete_list(MList *);
void add_element(MList *, void*, size_t);
void *get_first_element(MList *);
void *retrieve_element(MList *, int);
void delete_element(MList *, void*, int (*)(void*, void*));
int get_size(MList *);
int contains(MList *, void*);
