#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (stack->head == NULL);
}

int	count_nodes(t_stack *stack)
{
	t_node	*aux;
	int		count;

	if (!stack)
		return (0);
	count = 0;
	aux = stack->head;
	while (aux != NULL)
	{
		count++;
		aux = aux->next;
	}
	return (count);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*aux;
	t_node	*min;

	if (is_empty(stack))
		return (NULL);
	min = stack->head;
	aux = stack->head->next;
	while (aux != NULL)
	{
		if (aux->value < min->value)
			min = aux;
		aux = aux->next;
	}
	return (min);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*aux;
	t_node	*max;

	if (is_empty(stack))
		return (NULL);
	max = stack->head;
	aux = stack->head->next;
	while (aux != NULL)
	{
		if (aux->value > max->value)
			max = aux;
		aux = aux->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int rank)
{
	t_node	*aux;
	int		pos;

	if (!stack)
		return (-1);
	pos = 0;
	aux = stack->head;
	while (aux != NULL)
	{
		if (aux->rank == rank)
			return (pos);
		pos++;
		aux = aux->next;
	}
	return (-1);
}
