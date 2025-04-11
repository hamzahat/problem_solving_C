/*
 * make a fun that:
 * takes as a parameter a node and frees the memory of 
 * the node's content using the function 'del' given as 
 * a parameter and free the node.
 * the memory of 'next' must not be freed.

 ! this function implementation just deletes a node, 
 ! does not handle next ptrs, rewiring properly the list ! Duty to the caller.
*/
#include <stdlib.h>
#include <stdio.h>

// struct:
typedef struct s_list
{
    void            *value;
    struct s_list    *next;
}                t_list;

//! fun: Free node content and node itself:
void    lst_del_one(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
        return ;
    del(lst->value);
    free(lst);
}

// Create new list node:
t_list    *lst_new(void *content)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->value = content;
    new_node->next = NULL;
    return (new_node);
}

// Free allocated memory for integer:
void    delet_int(void *ptr)
{
    free(ptr);
}

// Print linked list:
void    print_list(t_list *list)
{
    t_list *tmp = list;
    while (tmp)
    {
        printf("%d\n", *(int *)(tmp->value));
        tmp = tmp->next;
    }
}

// int main:
int main(void)
{
    t_list *list = NULL;

    // Allocate memory for integers
    int *val_1 = malloc(sizeof(int));
    int *val_2 = malloc(sizeof(int));
    int *val_3 = malloc(sizeof(int));
    *val_1 = 21;
    *val_2 = 42;
    *val_3 = 1337;

    // Create nodes
    t_list *node_1 = lst_new(val_1);
    t_list *node_2 = lst_new(val_2);
    t_list *node_3 = lst_new(val_3);

    // Link nodes
    list = node_1;
    node_1->next = node_2;
    node_2->next = node_3;

    printf("Before deletion:\n");
    print_list(list);

    // Delete node_3 safely
    lst_del_one(node_3, delet_int);

    printf("After deletion:\n");
    print_list(list); // node_3 is gone, but the rest should print

    // Free remaining nodes
    lst_del_one(node_2, delet_int);
    lst_del_one(node_1, delet_int);

    return (0);
}