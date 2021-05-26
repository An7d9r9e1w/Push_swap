#include <push_swap.h>

static void	has_next_a(t_stack **a, t_stack **b, t_state *state)
{
	while ((*a)->order == state->next - 1)
	{
		if (get_last(*a)->order == state->next)
		{
			rotate(a, 'a');
			state->next++;
		}
		else if (get_last(*a)->prev->order == state->next)
			swap(a, 'a');
		else if (get_size(*b) && get_last(*b)->order == state->next)
			push(a, b, 'a');
		else
			break ;
	}
}

int	has_remainders(t_stack **a, t_stack **b, t_state *state)
{
	t_stack	*lasta;
	int		flag;

	lasta = get_last(*a);
	flag = lasta->flag;
	if (!flag)
		return (0);
	state->mid = lasta->order;
	while (1)
	{
		has_next_a(a, b, state);
		lasta = get_last(*a);
		if (lasta->order > state->next && lasta->flag == flag)
		{
			if (state->mid < lasta->order)
				state->mid = lasta->order;
			push(b, a, 'b');
		}
		else
			break ;
	}
	return (1);
}

void	stack_a(t_stack **a, t_stack **b, t_state *state)
{
	state->mid = ((state->size - state->next) >> 1) + state->next;
	while (get_size(*b) < state->mid - state->next + 1)
	{
		has_next_a(a, b, state);
		if (state->next > state->size)
			break ;
		state->mid = ((state->size - state->next) >> 1) + state->next;
		if (get_last(*a)->order <= state->mid)
			push(b, a, 'b');
		else
			rotate(a, 'a');
	}
	while (state->next > 1 && (*a)->order > state->next - 1)
		rrotate(a, 'a');
}

void	stack_b(t_stack **a, t_stack **b, t_state *state)
{
	t_stack	*lastb;
	int		count;

	while (get_size(*b) > 3 && ++state->flag)
	{
		state->mid = ((state->mid - state->next) >> 1) + state->next;
		count = (get_size(*b) + 1) >> 1;
		while (get_size(*b) > count && count >= 0)
		{
			lastb = get_last(*b);
			if (lastb->order == state->next || lastb->order > state->mid)
			{
				lastb->flag = state->flag;
				push(a, b, 'a');
				if (lastb->order == state->next)
				{
					count--;
					rotate(a, 'a');
					state->next++;
				}
			}
			else
				rotate(b, 'b');
		}
	}
}

void	stack_b_rem(t_stack **a, t_stack **b, t_state *state)
{
	t_stack	*lasta;
	int		count;

	count = get_size(*b);
	while (count > 0 || get_size(*b))
	{
		lasta = get_last(*a);
		if (lasta->prev->order == state->next)
			swap(a, 'a');
		else if (lasta->order == state->next)
		{
			rotate(a, 'a');
			state->next++;
			count--;
		}
		else if (get_size(*b))
			push(a, b, 'a');
		else
			break ;
	}
}
