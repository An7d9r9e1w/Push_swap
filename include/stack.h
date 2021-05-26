#ifndef STACK_H
# define STACK_H

typedef struct s_state
{
	int	size;
	int	mid;
	int	next;
	int	flag;
}	t_state;

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
	int				order;
	int				flag;
}	t_stack;

t_stack	*create_stack(int value, int order, int flag);
t_stack	*get_last(t_stack *stack);
int		get_size(t_stack *stack);
void	free_stack(t_stack **stack);
#endif	/*STACK_H*/
