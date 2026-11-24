#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct  s_node
{
	int     value;
	int     rank;
	struct  s_node  *next;
}   t_node;

typedef struct  s_stack
{
	t_node  *head;
	int     size;
}   t_stack;

t_node  *new_node(int value);
void    append_node(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif