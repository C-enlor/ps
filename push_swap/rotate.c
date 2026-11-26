/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarti4 <damarti4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 10:03:20 by damarti4          #+#    #+#             */
/*   Updated: 2026/11/26 10:03:22 by damarti4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->head;
	stack->head = stack->head->next;
	last = stack->head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_stack *a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	moved_a;
	int	moved_b;

	moved_a = rotate(a);
	moved_b = rotate(b);
	if (moved_a || moved_b)
		write(1, "rr\n", 3);
}
