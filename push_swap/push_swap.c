#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_mode	mode;
	int		status;

	if (argc < 2)
		return (0);
	init_stacks(&a, &b);
	status = 0;
	if (!parse_args(argc, argv, &a, &mode))
	{
		write(2, "Error\n", 6);
		status = 1;
	}
	else
		assign_ranks(&a);
	free_stack(&a);
	free_stack(&b);
	return (status);
}
