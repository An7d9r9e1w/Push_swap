#include <stack.h>
#include <stdlib.h>

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	tmp;

	pivot = arr[(low + high) >> 1];
	while (1)
	{
		while (arr[low] < pivot)
			low++;
		while (arr[high] > pivot)
			high--;
		if (low >= high)
			return (high);
		tmp = arr[low];
		arr[low] = arr[high];
		arr[high] = tmp;
		low++;
		high--;
	}
}

static void	quicksort(int *arr, int low, int high)
{
	int	p;

	if (low < high)
	{
		p = partition(arr, low, high);
		quicksort(arr, low, p);
		quicksort(arr, p + 1, high);
	}
}

static int	binary_search(int item, int *arr, int high)
{
	int	i;
	int	low;

	low = 0;
	high--;
	while (low < high)
	{
		i = ((high - low) >> 1) + low;
		if (item == arr[i])
			return (i);
		if (item < arr[i])
			high = i - 1;
		else
			low = i + 1;
	}
	if (arr[high] == item)
		return (high);
	return (-1);
}

int	set_orders(t_stack *root)
{
	t_stack	*tmp;
	int		*arr;
	int		len;
	int		i;

	len = get_size(root);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (1);
	tmp = root;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	quicksort(arr, 0, len - 1);
	tmp = root;
	while (tmp)
	{
		tmp->order = binary_search(tmp->value, arr, len) + 1;
		tmp = tmp->next;
	}
	free(arr);
	return (0);
}
