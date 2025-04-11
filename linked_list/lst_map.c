// * creat a new list from source.
#include <stdlib.h>
#include <stdio.h>

// struct:
typedef struct s_list
{
    void            *value;
    struct s_list    *next;
}                t_list;

// helper fun:
t_list	*lst_new(void *content)
{
	t_list *tmp = malloc(sizeof(t_list));
	if (!(tmp))
		return (NULL);
	tmp->value = content;
	tmp->next = NULL;
	return(tmp);
}
void	lst_clear(t_list **lst)
{
	t_list	*tmp;
	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
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

// ! fun:
t_list	*lst_map(t_list *lst, void *(*f)(void *))
{
	t_list *new_lst;
	t_list *new_node;

	if (!lst)
		return NULL;
	new_lst = NULL;
	while (lst)
	{
		if (f)
			new_node = lst_new(f(lst->value));
		else
			new_node = lst_new(lst->value);
		if (!new_node)
		{
			lst_clear(&new_lst);
			return (NULL);
		}
		lst_add_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
