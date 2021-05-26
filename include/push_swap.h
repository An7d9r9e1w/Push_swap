#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stack.h>

# define ERROR_MSG "Error\n"

char	**get_args(int argc, char *argv[]);
t_stack	*get_stack(int argc, char *argv[]);
t_stack	*get_valid_stack(int len, char **strs);
int		is_sort(t_stack *a);

void	get_instr(t_stack **root);
void	swap(t_stack **stack, char sk_name);
void	push(t_stack **dst, t_stack **src, char sk_name);
void	rotate(t_stack **stack, char sk_name);
void	rrotate(t_stack **stack, char sk_name);
#endif	/*PUSH_SWAP_H*/
