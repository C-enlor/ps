#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!is_digit(str[i]))
		return (0);
	while (is_digit(str[i]))
		i++;
	return (str[i] == '\0' || is_sep(str[i]));
}

int	parse_int_checked(const char *str, int *out)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (is_digit(str[i]))
	{
		res = res * 10 + (str[i++] - '0');
		if (res > (long)INT_MAX + 1)
			return (0);
	}
	res = res * sign;
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	*out = (int)res;
	return (1);
}
