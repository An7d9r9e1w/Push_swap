#include <libft.h>

void	out_instr(char *isr_name, char sk_name)
{
	int	len;

	len = ft_strlen(isr_name);
	write(1, isr_name, len);
	write(1, &sk_name, 1);
	write(1, "\n", 1);
}
