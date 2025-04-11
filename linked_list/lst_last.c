// make a fun that return a pointer to the last node in the linkede list.
#include <stdlib.h>
#include <stdio.h>

// struct:
typedef struct	s_list
{
	void			*value;
	struct	s_list	*next;
}				t_list;

// fun:
t_list	*lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*lst_new(void *content)
{
	t_list *tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->value = content;
	tmp->next = NULL;
	return(tmp);
}

// int main:
int main (void)
{
	t_list *list = NULL;
	t_list *node_1 = lst_new(&(int){21});
	t_list *node_2 = lst_new(&(int){42});
	t_list *node_3 = lst_new(&(int){1337});

	list = node_1;
	node_1->next = node_2;
	node_2->next = node_3;

	t_list *result = lst_last(list);
	printf("%d\n", *(int *)(result->value));
	return (0);
}