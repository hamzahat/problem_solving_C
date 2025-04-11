/*
 * Deletes and frees the given node and every successor of the node, 
 * using the function 'del' and 'free'. 
 * Finally, the pointer to the list must be set to NULL.
*/
#include <stdlib.h>
#include <stdio.h>

// struct:
typedef struct s_list
{
    void            *value;
    struct s_list    *next;
}                t_list;

void	lst_clear(t_list **lst, void (*del)(void *))
{
	t_list	*cureent;
	t_list	*tmp;
	if (!lst || !del)
		return ;
	cureent =  *lst;
	while (cureent)
	{
		tmp = cureent;
		cureent = cureent->next;
		free(tmp->value);
		free(tmp);
	}
	*lst = NULL;
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