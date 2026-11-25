#include "push_swap.h"

long	count_inversions(t_stack *stack)
{
	t_node	*left;
	t_node	*right;
	long	inversions;

	if (!stack)
		return (0);
	inversions = 0;
	left = stack->head;
	while (left != NULL)
	{
		right = left->next;
		while (right != NULL)
		{
			if (left->value > right->value)
				inversions++;
			right = right->next;
		}
		left = left->next;
	}
	return (inversions);
}

double	compute_disorder(t_stack *stack)
{
	long	pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	pairs = (long)stack->size * (stack->size - 1) / 2;
	return ((double)count_inversions(stack) / (double)pairs);
}
