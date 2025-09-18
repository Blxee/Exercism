#include "react.h"

struct reactor *create_reactor(void)
{
	struct reactor *result;

	result = malloc(sizeof(struct reactor));
	return (result);
}

void destroy_reactor(struct reactor *reactor)
{
	free(reactor);
}

struct cell *create_input_cell(struct reactor *reactor, int initial_value)
{
	(void)reactor;
	(void)initial_value;
	return (NULL);
}
struct cell *create_compute1_cell(struct reactor *reactor, struct cell *cell, compute1 compute)
{
	(void)reactor;
	(void)cell;
	(void)compute;
	return (NULL);
}
struct cell *create_compute2_cell(struct reactor *reactor, struct cell *cell1, struct cell *cell2, compute2 compute)
{
	(void)reactor;
	(void)cell1;
	(void)cell2;
	(void)compute;
	return (NULL);
}

int get_cell_value(struct cell *cell)
{
	(void)cell;
	return (0);
}
void set_cell_value(struct cell *cell, int new_value)
{
	(void)cell;
	(void)new_value;
}

// The callback should be called with the same void * given in add_callback.
callback_id add_callback(struct cell *cell, void *func, callback call)
{
	(void)cell;
	(void)func;
	(void)call;
	return (0);
}
void remove_callback(struct cell *cell, callback_id id)
{
	(void)cell;
	(void)id;
}
