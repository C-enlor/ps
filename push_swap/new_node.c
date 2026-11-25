#include "push_swap.h"

t_node  *new_node(int value)
{
	t_node  *node;

	node = malloc(1 * sizeof(t_node));
	if(!node)
		return (NULL);
	node->value = value;
	node->rank =  -1;
	node->next = NULL;
	return(node);
}