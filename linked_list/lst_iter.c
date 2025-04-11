// * apply a fun to all nodes in a list
#include <stdlib.h>
#include <stdio.h>

// Struct for linked list node
typedef struct s_list
{
    void            *value;
    struct s_list    *next;
}                t_list;

//! Function to modify the value of all the linked list
void fun(void *value)
{
    if (value)
        *(int *)value += 32;
}

// Function to apply a function to all nodes in the list
void lst_iter(t_list *lst, void (*fun)(void *))
{
    if (!lst || !fun)
        return ;
    while (lst)
    {
        fun(lst->value);
        lst = lst->next;
    }
}

// Function to create a new node with an allocated integer value
t_list *lst_new(int num)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->value = malloc(sizeof(int)); // Allocate space for integer value
    if (!new_node->value)
    {
        free(new_node);
        return (NULL);
    }
    *(int *)(new_node->value) = num; // Store the integer value
    new_node->next = NULL;
    return (new_node);
}

// Function to print the list
void print_list(t_list *list)
{
    t_list *tmp = list;
    while (tmp)
    {
        printf("%c\n", *(int *)(tmp->value));
        tmp = tmp->next;
    }
}

// Function to free the list
void free_list(t_list *list)
{
    t_list *tmp;
    while (list)
    {
        tmp = list->next;
        free(list->value);
        free(list);
        list = tmp;
    }
}

// Main function
int main(void)
{
    // Create nodes with integer values
    t_list *node_1 = lst_new(65);
    t_list *node_2 = lst_new(66);
    t_list *node_3 = lst_new(67);

    // Link the nodes to form a list
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = NULL;

    printf("Before applying function:\n");
    print_list(node_1);

    // Apply function to modify values
    lst_iter(node_1, fun);

    printf("After applying function:\n");
    print_list(node_1);

    // Free the allocated memory
    free_list(node_1);

    return (0);
}
// struct:

#include <stdlib.h>
#include <stdio.h>

