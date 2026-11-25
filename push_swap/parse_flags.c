#include "push_swap.h"

int	parse_mode(char *arg, t_mode *mode)
{
	if (ft_strcmp(arg, "--simple") == 0)
		*mode = SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		*mode = MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		*mode = COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		*mode = ADAPTIVE;
	else
		return (0);
	return (1);
}
