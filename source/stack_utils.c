#include <push_swap.h>

int	is_sort(t_stack *a)
{
	while (a->next)
	{
		if (a->order != a->next->order + 1)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*get_stack(int argc, char *argv[])
{
	t_stack	*a;
	char	**arrs;
	int		len;

	a = 0;
	arrs = get_args(argc - 1, argv + 1);
	if (arrs)
	{
		len = 0;
		while (arrs[len])
			len++;
		a = get_valid_stack(len, arrs);
		while (--len >= 0)
			free(arrs[len]);
		free(arrs);
	}
	return (a);
}
