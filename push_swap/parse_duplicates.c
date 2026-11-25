#include "push_swap.h"

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*aux;

	if (!stack)
		return (0);
	aux = stack->head;
	while (aux != NULL)
	{
		if (aux->value == value)
			return (1);
		aux = aux->next;
	}
	return (0);
}
