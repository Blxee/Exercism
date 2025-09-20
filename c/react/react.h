#ifndef REACT_H
#define REACT_H

#include <stdlib.h>

typedef void (*callback)(void *, int);
typedef int callback_id;

typedef int (*compute1)(int);
typedef int (*compute2)(int, int);

struct call_node {
	callback func;
	callback_id id;
	void *data;
	struct call_node *next;
};

struct cell {
	int value;
	struct call_node *call_node;
	struct cell *depend_cell1;
	struct cell *depend_cell2;
	union {
		compute1 compute1;
		compute2 compute2;
	} funcs;
	struct cell *next;
};

struct reactor {
	callback *callbacks;
	struct cell *head;
};

struct reactor *create_reactor(void);
// destroy_reactor should free all cells created under that reactor.
void destroy_reactor(struct reactor *);

struct cell *create_input_cell(struct reactor *, int initial_value);
struct cell *create_compute1_cell(struct reactor *, struct cell *, compute1);
struct cell *create_compute2_cell(struct reactor *, struct cell *,
                                  struct cell *, compute2);

int get_cell_value(struct cell *);
void set_cell_value(struct cell *, int new_value);

// The callback should be called with the same void * given in add_callback.
callback_id add_callback(struct cell *, void *, callback);
void remove_callback(struct cell *, callback_id);

#endif
