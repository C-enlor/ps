#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*aux;

	if (!stack)
		return (0);
	if (stack->size == 0 || stack->size == 1)
		return (1);
	aux = stack->head;
	while (aux->next != NULL)
	{
		if (aux->value > aux->next->value)
			return (0);
		aux = aux->next;
	}
	return (1);
}