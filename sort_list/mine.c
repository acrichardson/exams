typedef struct s_list
{
    int            data;
    struct s_list  *next;
}    t_list;

// t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
// {

// }

// #include "list.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Create a new node
t_list  *create_node(int data)
{
    t_list  *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

// Add node to front of list
void    add_front(t_list **list, t_list *new_node)
{
    if (new_node)
    {
        new_node->next = *list;
        *list = new_node;
    }
}

// Add node to back of list
void    add_back(t_list **list, t_list *new_node)
{
    t_list  *current;

    if (!*list)
    {
        *list = new_node;
        return;
    }
    current = *list;
    while (current->next)
        current = current->next;
    current->next = new_node;
}

// Get the size of the list
int     list_size(t_list *list)
{
    int     count;
    t_list  *current;

    count = 0;
    current = list;
    while (current)
    {
        count++;
        current = current->next;
    }
    return (count);
}

// Print the list (for debugging)
void    print_list(t_list *list)
{
    t_list  *current;
    char    c;

    current = list;
    while (current)
    {
        // Simple integer printing (you might want to use ft_putnbr instead)
        if (current->data >= 0 && current->data <= 9)
        {
            c = current->data + '0';
            write(1, &c, 1);
        }
        write(1, " ", 1);
        current = current->next;
    }
    write(1, "\n", 1);
}

// Free the entire list
void    free_list(t_list *list)
{
    t_list  *temp;

    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}

// #include "list.h"
// #include <stdio.h>

// Example comparison function
int ascending(int a, int b)
{
    return (a <= b);
}



t_list    *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list    *i;
    t_list    *j;
    int        temp;
    
    if (!lst)
        return (NULL);
    
    i = lst;
    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (cmp(i->data, j->data) == 0)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return (lst);
}


int main()
{
    t_list *list = NULL;
    
    // Create and populate a list
    add_back(&list, create_node(5));
    add_back(&list, create_node(2));
    add_back(&list, create_node(8));
    add_back(&list, create_node(1));
    
    printf("Before sort: ");
    print_list(list);
    
    // Sort the list
    list = sort_list(list, &ascending);
    
    printf("After sort: ");
    print_list(list);
    
    free_list(list);
    return 0;
}