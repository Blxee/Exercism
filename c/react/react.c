#include "react.h"

struct reactor *create_reactor(void)
{
	struct reactor *reactor;

	reactor = malloc(sizeof(struct reactor));
	reactor->callbacks = NULL;
	reactor->head = NULL;
	return (reactor);
}

void destroy_reactor(struct reactor *reactor)
{
	struct cell *cell;
	struct cell *next_cell;
	struct call_node *call;
	struct call_node *next_call;

	cell = reactor->head;
	while (cell)
	{
		call = cell->call_node;
		while (call)
		{
			next_call = call->next;
			free(call);
			call = next_call;
		}
		next_cell = cell->next;
		free(cell);
		cell = next_cell;
	}
	free(reactor);
}

struct cell *create_input_cell(struct reactor *reactor, int initial_value)
{
	struct cell **cell;

	cell = &reactor->head;
	while (*cell)
		cell = &(*cell)->next;
	*cell = malloc(sizeof(struct cell));
	(*cell)->value = initial_value;
	(*cell)->call_node = NULL;
	(*cell)->depend_cell1 = NULL;
	(*cell)->depend_cell2 = NULL;
	(*cell)->next = NULL;
	return (*cell);
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

// The callback should be called with the same void * given in add_callback.
int get_cell_value(struct cell *cell)
{
	int value;
	struct call_node **call;

	if (cell->depend_cell2)
		value = cell->funcs.compute2(get_cell_value(cell->depend_cell1), get_cell_value(cell->depend_cell2));
	else if (cell->depend_cell1)
		value = cell->funcs.compute1(get_cell_value(cell->depend_cell1));
	else 
		value = cell->value;
	call = &cell->call_node;
	while (*call)
	{
		call = &(*call)->next;
		(*call)->func((*call)->data, value);
	}
	return (value);
}

void set_cell_value(struct cell *cell, int new_value)
{
	cell->value = new_value;
}

callback_id add_callback(struct cell *cell, void *data, callback func)
{
	struct call_node **current;
	callback_id id = 0;

	current = &cell->call_node;
	while (*current)
	{
		id = (*current)->id;
		current = &(*current)->next;
	}
	*current = malloc(sizeof(struct call_node));
	id++;
	(*current)->func = func;
	(*current)->id = id + 1;
	(*current)->data = data;
	return (id);
}

void remove_callback(struct cell *cell, callback_id id)
{
	struct call_node **call;

	call = &cell->call_node;
	while (*call)
	{
		if ((*call)->id == id)
		{
			*call = (*call)->next;
			return ;
		}
		call = &(*call)->next;
	}
}
