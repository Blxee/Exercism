#include "react.h"

struct reactor *create_reactor(void)
{
	struct reactor *result;

	result = malloc(sizeof(struct reactor));
	result->callbacks = NULL;
	return (result);
}

void destroy_reactor(struct reactor *reactor)
{
	free(reactor);
}

struct cell *create_input_cell(struct reactor *reactor, int initial_value)
{
	struct cell *cell;

	(void)reactor;
	cell = malloc(sizeof(struct cell));
	cell->value = initial_value;
	cell->depend_cell1 = NULL;
	cell->depend_cell2 = NULL;
	return (cell);
}

struct cell *create_compute1_cell(struct reactor *reactor, struct cell *cell, compute1 compute)
{
	struct cell *result;

	result = create_input_cell(reactor, 0);
	result->depend_cell1 = cell;
	result->funcs.compute1 = compute;
	return (result);
}

struct cell *create_compute2_cell(struct reactor *reactor, struct cell *cell1, struct cell *cell2, compute2 compute)
{
	struct cell *cell;

	cell = create_input_cell(reactor, 0);
	cell->depend_cell1 = cell1;
	cell->depend_cell2 = cell2;
	cell->funcs.compute2 = compute;
	return (cell);
}

int get_cell_value(struct cell *cell)
{
	if (cell->depend_cell2)
		return (cell->funcs.compute2(get_cell_value(cell->depend_cell1), get_cell_value(cell->depend_cell2)));
	else if (cell->depend_cell1)
		return (cell->funcs.compute1(get_cell_value(cell->depend_cell1)));
	else 
		return (cell->value);
}

void set_cell_value(struct cell *cell, int new_value)
{
	cell->value = new_value;
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
