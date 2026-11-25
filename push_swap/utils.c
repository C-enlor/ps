#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sep(char c)
{
	return (c == ' ' || c == '\t');
}
