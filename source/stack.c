#include <stdlib.h>
#include <stack.h>

t_stack	*create_stack(int value, int order, int flag)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->prev = 0;
	stack->next = 0;
	stack->value = value;
	stack->order = order;
	stack->flag = flag;
	return (stack);
}

t_stack	*get_last(t_stack *stack)
{
	if (stack)
		while (stack->next)
			stack = stack->next;
	return (stack);
}

int	get_size(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	free_stack(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*stack = 0;
}
