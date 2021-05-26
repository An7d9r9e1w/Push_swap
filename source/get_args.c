#include <libft.h>

static t_list	*get_elems(char **arrs)
{
	t_list	*root;
	t_list	*list;
	int		i;

	if (!arrs)
		return (0);
	root = ft_lstnew(0);
	if (!root)
		return (0);
	list = root;
	i = -1;
	while (arrs[++i] && list)
	{
		list->next = ft_lstnew(arrs[i]);
		list = list->next;
	}
	if (!list)
		ft_lstclear(&root->next, &free);
	while (!list && i >= 0)
		free(arrs[i--]);
	free(arrs);
	list = root;
	root = root->next;
	free(list);
	return (root);
}

static t_list	*get_list(int argc, char *argv[])
{
	t_list	*root;
	t_list	*list;

	root = ft_lstnew(0);
	if (!root)
		return (0);
	list = root;
	while (argc-- > 0 && list)
	{
		list->next = get_elems(ft_split(*argv++, ' '));
		list = ft_lstlast(list->next);
	}
	if (!list)
		ft_lstclear(&root->next, &free);
	list = root;
	root = root->next;
	free(list);
	return (root);
}

char	**get_args(int argc, char *argv[])
{
	t_list	*list;
	t_list	*cur;
	char	**strs;
	int		i;

	list = get_list(argc, argv);
	if (!list)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (strs)
	{
		cur = list;
		i = 0;
		while (cur)
		{
			strs[i++] = (char *)cur->content;
			cur->content = 0;
			cur = cur->next;
		}
		strs[i] = 0;
	}
	ft_lstclear(&list, &free);
	return (strs);
}
