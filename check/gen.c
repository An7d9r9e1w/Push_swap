#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int	*get_rand_set(int len)
{
	int	*arr;
	int	i, j;

	if (!(arr = malloc(sizeof(int) * len)))
		return (0);
	srand(clock());
	arr[0] = 0;
	for (i = 1; i < len; i++)
	{
		j = rand() % i;
		if (j == i)
			arr[i] = i;
		else
		{
			arr[i] = arr[j];
			arr[j] = i;
		}
	}
	return (arr);
}
int	main(int argc, char *argv[])
{
	int	*arr;
	int	len, i;

	if (argc < 2)
		return 1;
	len = atoi(argv[1]);
	if (!(arr = get_rand_set(len)))
		return (1);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	free(arr);
	return 0;
}
