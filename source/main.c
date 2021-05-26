#include <push_swap.h>

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (argc < 2)
		return (1);
	a = get_stack(argc, argv);
	if (!a)
		write(2, ERROR_MSG, sizeof(ERROR_MSG));
	if (a && !is_sort(a))
		get_instr(&a);
	free_stack(&a);
	return (0);
}
