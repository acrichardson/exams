#ifndef LIST_H
# define LIST_H

// Define the structure for a linked list node
typedef struct s_list
{
    int            data;
    struct s_list  *next;
}    t_list;

// Function prototypes that would commonly be used with lists

// The sort function prototype
t_list   *sort_list(t_list *lst, int (*cmp)(int, int));

#endif