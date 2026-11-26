/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarti4 <damarti4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 10:02:07 by damarti4          #+#    #+#             */
/*   Updated: 2026/11/26 10:02:12 by damarti4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <unistd.h>

static int	push(t_stack *src, t_stack *dst)
{
	t_node	*node_to_move;

	if (!src || !dst || src->size == 0)
		return (0);
	node_to_move = src->head;
	src->head = src->head->next;
	node_to_move->next = dst->head;
	dst->head = node_to_move;
	src->size--;
	dst->size++;
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(a, b))
		write(1, "pb\n", 3);
}
