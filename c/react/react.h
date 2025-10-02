#ifndef REACT_H
#define REACT_H

#include <stdlib.h>

#define LIST_INIT_CAP (8)

typedef struct {
	void **buffer;
	unsigned int capacity;
	unsigned int length;
} list_t;

typedef int (*compute1)(int);
typedef int (*compute2)(int, int);

typedef void (*callback)(void *, int);
typedef int callback_id;

struct reactor {
	list_t *cells;
};

typedef enum {
	INPUT_CELL,
	COMPUTE1_CELL,
	COMPUTE2_CELL,
} cell_type_t;

typedef struct {
	callback callback;
	callback_id id;
	void *cbinfo;
} cbnode_t;

struct cell {
	cell_type_t type;
	int value;
	struct {
		struct cell *cell1;
		struct cell *cell2;
	} parents;
	union {
		compute1 comp1;		
		compute2 comp2;		
	} funcs;
	list_t *children;
	list_t *callbacks;
};

struct reactor *create_reactor(void);
// destroy_reactor should free all cells created under that reactor.
void destroy_reactor(struct reactor *);

struct cell *create_empty_cell(struct reactor *);
struct cell *create_input_cell(struct reactor *, int initial_value);
struct cell *create_compute1_cell(struct reactor *, struct cell *, compute1);
struct cell *create_compute2_cell(struct reactor *, struct cell *,
                                  struct cell *, compute2);

int get_cell_value(struct cell *);
void set_cell_value(struct cell *, int new_value);

// The callback should be called with the same void * given in add_callback.
callback_id add_callback(struct cell *, void *, callback);
void remove_callback(struct cell *, callback_id);

list_t *lst_create(void);
unsigned int lst_add(list_t *lst, void *value);
void *lst_get(list_t *lst, unsigned int i);
void *lst_remove(list_t *lst, unsigned int i);
void lst_free(list_t **lst);

#endif
