// add the node new at the end of the linked list
#include <stdlib.h>
#include <stdio.h>

// struct:
typedef struct	s_list
{
	void			*value;
	struct	s_list	*next;
}				t_list;

//* helper fun :
t_list	*lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
t_list	*lst_new (void *content)
{
	t_list *new_node = malloc(sizeof(t_list));
	if (!(new_node))
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return(new_node);
}
void	lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
//! fun:
void	lst_add_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		return ((void)(*lst = new));
	t_list *last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
// int main:
int main(void)
{
	int m = 1337, p = 42, r = 21;
	t_list *list = NULL;
	lstadd_front(&list, lst_new(&r));
	lstadd_front(&list, lst_new(&p));
	lstadd_front(&list, lst_new(&m));

	lst_add_back(&list, lst_new(&(int){2025}));

	print_list(list);
	return (0);
}