#include <push_swap.h>

void	out_instr(char *isr_name, char sk_name);

static t_stack	*pop(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->next)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = 0;
		tmp->prev = 0;
	}
	else
	{
		tmp = *stack;
		*stack = 0;
	}
	return (tmp);
}

void	rrotate(t_stack **stack, char sk_name)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = get_last(*stack);
	tmp->prev->next = tmp;
	if (sk_name > 31 && sk_name < 127)
		out_instr("rr", sk_name);
}

void	rotate(t_stack **stack, char sk_name)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = pop(stack);
	(*stack)->next = tmp;
	tmp->prev = *stack;
	if (sk_name > 31 && sk_name < 127)
		out_instr("r", sk_name);
}

void	push(t_stack **dst, t_stack **src, char sk_name)
{
	t_stack	*tmp;

	if (!src || !dst || !*src)
		return ;
	if (*dst)
	{
		tmp = get_last(*dst);
		tmp->next = pop(src);
		tmp->next->prev = tmp;
	}
	else
		*dst = pop(src);
	if (sk_name > 31 && sk_name < 127)
		out_instr("p", sk_name);
}

void	swap(t_stack **stack, char sk_name)
{
	t_stack	*cur;
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if ((*stack)->next->next)
	{
		cur = get_last(*stack)->prev->prev;
		tmp = cur->next;
		cur->next = tmp->next;
		cur->next->next = tmp;
		cur->next->prev = cur;
		tmp->prev = cur->next;
	}
	else
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = 0;
		(*stack)->next = tmp;
		tmp->prev = *stack;
	}
	tmp->next = 0;
	if (sk_name > 31 && sk_name < 127)
		out_instr("s", sk_name);
}
