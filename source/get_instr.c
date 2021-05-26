#include <push_swap.h>

int		has_remainders(t_stack **a, t_stack **b, t_state *state);
void	stack_a(t_stack **a, t_stack **b, t_state *state);
void	stack_b(t_stack **a, t_stack **b, t_state *state);
void	stack_b_rem(t_stack **a, t_stack **b, t_state *state);

static void	rotate_a(t_stack **a, int value, int size)
{
	t_stack	*cur;
	void	(*instr)(t_stack **, char);
	int		i;
	int		min;
	int		path;

	min = 2;
	i = 1;
	cur = *a;
	while (cur->next)
	{
		path = (i > 2) * (size - i) + (i <= 2) * (-i);
		if (cur->order <= value && path & 1)
			min = path;
		cur = cur->next;
		i++;
	}
	instr = &rotate;
	if (min < 0)
	{
		instr = &rrotate;
		min = -min;
	}
	while (min--)
		(*instr)(a, 'a');
}

static void	push_b(t_stack **a, t_stack **b, int size)
{
	int		value;

	value = size - 3;
	while (size > 3)
	{
		if (get_last(*a)->order <= value)
		{
			push(b, a, 'b');
			size--;
		}
		else
			rotate_a(a, value, size);
	}
}

static void	merge_instrs(t_stack **a, t_stack **b,
	void (*instr)(t_stack **, char), char name)
{
	if (*b && (*b)->order == 2)
	{
		(*instr)(a, name);
		(*instr)(b, 0);
	}
	else
		(*instr)(a, 'a');
}

static void	get_spec_instr(t_stack **a, t_stack **b, int size)
{
	t_stack	*last;

	push_b(a, b, size);
	size -= 3;
	last = get_last(*a);
	while (last->order != 1 + size || (*a)->next->order != 2 + size)
	{
		if (last->order == 1 + size || (last->order == 2 + size
				&& (*a)->next->order == 1 + size))
			merge_instrs(a, b, &swap, 's');
		else if (last->order == 3 + size)
			merge_instrs(a, b, &rotate, 'r');
		else
			rrotate(a, 'a');
		last = get_last(*a);
	}
	while (get_size(*b))
		push(a, b, 'a');
	if (get_last(*a)->order != 1)
		swap(a, 'a');
}

void	get_instr(t_stack **root)
{
	t_stack	*a;
	t_stack	*b;
	t_state	state;

	a = *root;
	b = 0;
	state.size = get_size(a);
	if (state.size <= 5)
		get_spec_instr(&a, &b, state.size);
	else
	{
		state.flag = 0;
		state.next = 1;
		while (state.next <= state.size)
		{
			if (!has_remainders(&a, &b, &state))
				stack_a(&a, &b, &state);
			stack_b(&a, &b, &state);
			stack_b_rem(&a, &b, &state);
		}
	}
	*root = a;
}
