#include "push_swap.h"

static int	count_rank(t_stack *stack, int rank)
{
	t_node	*aux;
	int		count;

	count = 0;
	aux = stack->head;
	while (aux != NULL)
	{
		if (aux->rank == rank)
			count++;
		aux = aux->next;
	}
	return (count);
}

void	assign_ranks(t_stack *stack)
{
	t_node	*x;
	t_node	*y;
	int		smaller;

	if (!stack)
		return ;
	x = stack->head;
	while (x != NULL)
	{
		smaller = 0;
		y = stack->head;
		while (y != NULL)
		{
			if (y->value < x->value)
				smaller++;
			y = y->next;
		}
		x->rank = smaller;
		x = x->next;
	}
}

int	check_ranks(t_stack *stack)
{
	int	r;

	if (!stack)
		return (0);
	r = 0;
	while (r < stack->size)
	{
		if (count_rank(stack, r) != 1)
			return (0);
		r++;
	}
	return (1);
}
