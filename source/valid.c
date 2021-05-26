#include <push_swap.h>

int	set_orders(t_stack *root);

static int	has_dubl(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	valid(int len, char **strs)
{
	char	*str;
	int		num;
	int		i;
	char	sign;

	i = -1;
	while (++i < len)
	{
		str = strs[i];
		sign = (*str == '-');
		if (*str == '+' || *str == '-')
			str++;
		if (!*str)
			return (0);
		num = 0;
		while (*str)
		{
			if ((*str < '0' || *str > '9') || num > 214748364
				|| (num == 214748364 && (*str > '8' || (!sign && *str > '7'))))
				return (0);
			num = num * 10 + *str++ - '0';
		}
	}
	return (1);
}

t_stack	*get_valid_stack(int len, char **strs)
{
	t_stack	*root;
	t_stack	*cur;

	if (!valid(len, strs))
		return (0);
	root = create_stack(ft_atoi(*strs++), 0, 0);
	if (!root)
		return (0);
	while (--len)
	{
		cur = create_stack(ft_atoi(*strs++), 0, 0);
		if (!cur || has_dubl(root, cur->value))
		{
			free_stack(&cur);
			free_stack(&root);
			return (0);
		}
		cur->next = root;
		root->prev = cur;
		root = cur;
	}
	if (set_orders(root))
		free_stack(&root);
	return (root);
}
