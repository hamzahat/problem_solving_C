// creat a new node
#include <stdlib.h>
#include <stdio.h>

// struct:
typedef struct	s_list
{
	void			*value;
	struct	s_list	*next;
}				t_list;

// lst_new fun:
t_list	*lst_new(void *content)
{
	t_list *tmp = malloc(sizeof(t_list));
	if (!(tmp))
		return (NULL);
	tmp->value = content;
	tmp->next = NULL;
	return(tmp);
}

// int main :
int main (void)
{
	int a = 1337;
	t_list *head = lst_new(&a);
	if(!(head))
		return (1);
	printf("%d\n", *(int*)(head->value));
	free(head);
}
