#include "react.h"

list_t *lst_create(void)
{
	list_t *lst = malloc(sizeof(list_t));

	lst->length = 0;
	lst->capacity = LIST_INIT_CAP;
	lst->buffer = malloc(LIST_INIT_CAP * sizeof(void *));

	if (lst->buffer == NULL)
	{
		free(lst);
		return (NULL);
	}

	return (lst);
}

unsigned int lst_add(list_t *lst, void *value)
{
	if (lst->length == lst->capacity)
	{
		lst->capacity *= 2;
		lst->buffer = realloc(lst->buffer, lst->capacity);
	}
	lst->buffer[lst->length++] = value;
	return (lst->length - 1);
}

void *lst_get(list_t *lst, unsigned int i)
{
	return (lst->buffer[i]);
}

void *lst_remove(list_t *lst, unsigned int i)
{
	unsigned int j;
	void *value;
	
	value = lst_get(lst, i);
	lst->length--;

	j = i;
	while (j < lst->length)
	{
		lst->buffer[j] = lst->buffer[j + 1];
		j++;
	}

	return (value);
}

void lst_free(list_t **lst)
{
	free((*lst)->buffer);
	free(*lst);
	*lst = NULL;
}

struct reactor *create_reactor(void)
{
	struct reactor *reactor = malloc(sizeof(struct reactor));
	reactor->cells = lst_create();
	return (reactor);
}

void destroy_reactor(struct reactor *reactor)
{
	unsigned int i;
	unsigned int j;
	struct cell *cell;

	i = 0;
	while (i < reactor->cells->length)
	{
		cell = lst_get(reactor->cells, i);
		j = 0;
		while (cell->callbacks && j < cell->callbacks->length)
			free(lst_get(cell->callbacks, j++));
		if (cell->callbacks)
			lst_free(&(cell->callbacks));
		if (cell->children)
			lst_free(&(cell->children));
		i++;
	}

	lst_free(&(reactor->cells));
	free(reactor);
}

int get_cell_value(struct cell *cell)
{
	return (cell->value);
}

void set_cell_value(struct cell *cell, int new_value)
{
	int old_value = cell->value;
	unsigned int i;
	cbnode_t *cbnode;
	
	switch (cell->type)
	{
		case INPUT_CELL:
			cell->value = new_value;
			break;
		case COMPUTE1_CELL:
			cell->value = cell->funcs.comp1(get_cell_value(cell->parents.cell1));
			break;
		case COMPUTE2_CELL:
			cell->value = cell->funcs.comp2(get_cell_value(cell->parents.cell1), get_cell_value(cell->parents.cell2));
			break;
	}

	if (cell->value == old_value)
		return;
	
	i = 0;
	while (cell->children && i < cell->children->length)
	{
		set_cell_value(lst_get(cell->children, i), 0);
		i++;
	}

	i = 0;
	while (cell->callbacks && i < cell->callbacks->length)
	{
		cbnode = lst_get(cell->callbacks, i);
		cbnode->callback(cbnode->cbinfo, cell->value);
		i++;
	}
}

struct cell *create_empty_cell(struct reactor *reactor)
{
	struct cell *cell = malloc(sizeof(struct cell));
	unsigned int i = 0;

	while (i < sizeof(struct cell))
		((char *)cell)[i++] = 0;
	lst_add(reactor->cells, cell);

	return (cell);
}

struct cell *create_input_cell(struct reactor *reactor, int initial_value)
{
	struct cell *cell = create_empty_cell(reactor);

	cell->type = INPUT_CELL;
	cell->value = initial_value;
	return (cell);
}

struct cell *create_compute1_cell(struct reactor *reactor, struct cell *parent_cell, compute1 compute)
{
	struct cell *cell = create_empty_cell(reactor);

	cell->type = COMPUTE1_CELL;
	cell->parents.cell1 = parent_cell;
	cell->funcs.comp1 = compute;
	cell->value = compute(get_cell_value(parent_cell));

	if (parent_cell->children == NULL)
		parent_cell->children = lst_create();
	lst_add(parent_cell->children, cell);

	return (cell);
}

struct cell *create_compute2_cell(struct reactor *reactor, struct cell *parent_cell1,
                                  struct cell *parent_cell2, compute2 compute)
{
	struct cell *cell = create_empty_cell(reactor);

	cell->type = COMPUTE2_CELL;
	cell->parents.cell1 = parent_cell1;
	cell->parents.cell2 = parent_cell2;
	cell->funcs.comp2 = compute;
	cell->value = compute(get_cell_value(parent_cell1), get_cell_value(parent_cell2));

	if (parent_cell1->children == NULL)
		parent_cell1->children = lst_create();
	lst_add(parent_cell1->children, cell);

	if (parent_cell2->children == NULL)
		parent_cell2->children = lst_create();
	lst_add(parent_cell2->children, cell);

	return (cell);
}

callback_id add_callback(struct cell *cell, void *cbinfo, callback callback)
{
	cbnode_t *cbnode = malloc(sizeof(cbnode_t));
	
	if (cell->callbacks == NULL)
		cell->callbacks = lst_create();

	cbnode->callback = callback;
	cbnode->cbinfo = cbinfo;
	cbnode->id = lst_add(cell->callbacks, cbnode);

	return (cbnode->id);
}

void remove_callback(struct cell *cell, callback_id id)
{
	unsigned int i = 0;
	cbnode_t *cbnode;
	
	while (i < cell->callbacks->length)
	{
		cbnode = lst_get(cell->callbacks, i);
		if (id == cbnode->id)
			lst_remove(cell->callbacks, i);
		i++;
	}
}
