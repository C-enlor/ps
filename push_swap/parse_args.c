#include "push_swap.h"

static int	add_token(t_stack *a, char *str)
{
	int		value;
	t_node	*node;

	if (!is_valid_number(str) || !parse_int_checked(str, &value))
		return (0);
	if (has_duplicate(a, value))
		return (0);
	node = new_node(value);
	if (!node)
		return (0);
	append_node(a, node);
	return (1);
}

static int	add_argument(t_stack *a, char *arg)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (arg[i] != '\0')
	{
		while (is_sep(arg[i]))
			i++;
		if (arg[i] == '\0')
			break ;
		if (!add_token(a, &arg[i]))
			return (0);
		found++;
		while (arg[i] != '\0' && !is_sep(arg[i]))
			i++;
	}
	return (found > 0);
}

int	parse_args(int argc, char **argv, t_stack *a, t_mode *mode)
{
	int	i;

	*mode = ADAPTIVE;
	i = 1;
	if (argc > 1 && parse_mode(argv[1], mode))
		i = 2;
	while (i < argc)
	{
		if (!add_argument(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
