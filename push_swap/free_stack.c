#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*aux;

	if (!stack)
		return ;
	while (stack->head != NULL)
	{
		aux = stack->head->next;
		free(stack->head);
		stack->head = aux;
		stack->size--;
	}
}