typedef struct _mlist MList;

MList *create_list();
void delete_list(MList *);
void add_element(MList *, void*);
void *get_first_element(MList *);
void *retrieve_element(MList *, int);
int get_size(MList *);
int contains(MList *, void*);
