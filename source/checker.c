#include <push_swap.h>
#include <get_next_line.h>

static int	exec_instr_next(t_stack **a, t_stack **b, char *instr)
{
	int	error;

	error = 0;
	if (!ft_strncmp(instr, "rr", 3))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (!ft_strncmp(instr, "rra", 3))
		rrotate(a, 0);
	else if (!ft_strncmp(instr, "rrb", 3))
		rrotate(b, 0);
	else if (!ft_strncmp(instr, "rrr", 3))
	{
		rrotate(a, 0);
		rrotate(b, 0);
	}
	else
		error = 1;
	return (error);
}

static int	exec_instr(t_stack **a, t_stack **b, char *instr)
{
	int	error;

	if (ft_strlen(instr) > 3)
		return (1);
	error = 0;
	if (!ft_strncmp(instr, "sa", 3))
		swap(a, 0);
	else if (!ft_strncmp(instr, "sb", 3))
		swap(b, 0);
	else if (!ft_strncmp(instr, "ss", 3))
	{
		swap(a, 0);
		swap(b, 0);
	}
	else if (!ft_strncmp(instr, "pa", 3))
		push(a, b, 0);
	else if (!ft_strncmp(instr, "pb", 3))
		push(b, a, 0);
	else if (!ft_strncmp(instr, "ra", 3))
		rotate(a, 0);
	else if (!ft_strncmp(instr, "rb", 3))
		rotate(b, 0);
	else
		error = exec_instr_next(a, b, instr);
	return (error);
}

static int	read_instrs(t_stack **a)
{
	t_stack	*b;
	char	*instr;
	int		cnt;

	cnt = 1;
	b = 0;
	while (cnt > 0)
	{
		cnt = get_next_line(0, &instr);
		if (cnt < 1)
			break ;
		if (exec_instr(a, &b, instr))
			cnt = -1;
		free(instr);
	}
	free_stack(&b);
	if (!cnt)
		free(instr);
	return (cnt < 0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		size;

	if (argc < 2)
		return (1);
	a = get_stack(argc, argv);
	size = get_size(a);
	if (a)
	{
		if (read_instrs(&a))
			write(2, ERROR_MSG, sizeof(ERROR_MSG));
		else if (get_size(a) != size || !is_sort(a))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	else
		write(2, ERROR_MSG, sizeof(ERROR_MSG));
	free_stack(&a);
	return (0);
}
