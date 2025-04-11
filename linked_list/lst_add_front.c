// push a node at the top of the list
// lst : the address of a pointer to the first link of a list.
// new : the address of a pointer to the node to be added to the list.

#include <stdlib.h>
#include <stdio.h>

// struct:
typedef struct	s_list
{
	void			*value;
	struct	s_list	*next;
}				t_list;

void	lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
t_list	*lst_new (void *content)
{
	t_list *new_node = malloc(sizeof(t_list));
	if (!(new_node))
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return(new_node);
}

void	print_list(t_list *list)
{
	t_list *tmp = list;
	while (tmp)
	{
		printf("%d\n", *(int *)(tmp->value));
		tmp = tmp->next;
	}
}
void	free_list(t_list *list)
{
	t_list *tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

int main(void)
{
	int m = 1337, p = 42, r = 21;
	t_list *list = NULL;
	lstadd_front(&list, lst_new(&r));
	lstadd_front(&list, lst_new(&p));
	lstadd_front(&list, lst_new(&m));

	print_list(list);

	free_list(list);
	return (0);
}
