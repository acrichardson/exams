typedef struct s_list
{
    int            data;
    struct s_list  *next;
}    t_list;


int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{

}

int main()
{
    t_list list;

    
    
}