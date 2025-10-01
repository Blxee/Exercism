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

void lst_add(list_t *lst, void *value)
{
	if (lst->length == lst->capacity)
	{
		lst->capacity *= 2;
		lst->buffer = realloc(lst->buffer, lst->capacity);
	}
	lst->buffer[lst->length++] = value;
}

void *lst_get(list_t *lst, unsigned int i)
{
	return (lst->buffer[i]);
}

void lst_remove(list_t *lst, void *value)
{
	unsigned int i;
	unsigned int j;
	
	i = 0;
	while (i < lst->length)
	{
		if (lst_get(lst, i) == value)
		{
			lst->length--;
			j = 0;
			while (j < lst->length)
			{
				lst->buffer[j] = lst->buffer[j + 1];
				j++;
			}
			break;
		}
	}
}

void lst_free(list_t **lst)
{
	free((*lst)->buffer);
	free(*lst);
	*lst = NULL;
}
