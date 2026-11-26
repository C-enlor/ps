/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarti4 <damarti4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 10:02:50 by damarti4          #+#    #+#             */
/*   Updated: 2026/11/26 10:02:51 by damarti4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"
#include <unistd.h>

static int	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	moved_a;
	int	moved_b;

	moved_a = swap(a);
	moved_b = swap(b);
	if (moved_a || moved_b)
		write(1, "ss\n", 3);
}
