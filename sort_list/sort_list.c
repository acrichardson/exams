#include <list.h>
#include <unistd.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int tmp;
	t_list *head;

	head = tmp;
	while (lst != NULL && lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	return (head);
}

#include "list.h"

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

