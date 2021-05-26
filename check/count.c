#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main()
{
	char	buf[1];
	char	str[32];
	int		i = 0;
	int		total = 0;
	int		count = 0;
	int		num;
	int		max = 0;
	int		min	= 0x7fffffff;
	
	while (read(0, buf, 1))
		if (*buf == '\n')
		{
			str[i] = 0;
			i = 0;
			num = atoi(str);
			total += num;
			if (min > num)
				min = num;
			else if (max < num)
				max = num;
			count++;
		}
		else
			str[i++] = *buf;
	printf("\tmin = %d\n", min);
	printf("\tmax = %d\n", max);
	printf("\tmid = %d\n", total / count);
	return 0;
}
