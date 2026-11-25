#include "push_swap.h"

void node_w_content(t_stack *stack, t_node *new_node)
{
    t_node *aux;

    aux = stack->head;
    while (aux->next != NULL)
        aux = aux->next;
    aux->next = new_node;
}

void append_node(t_stack *stack, t_node *new_node)
{
    if (!stack || !new_node)
        return ;
    if (stack->head == NULL)
        stack->head = new_node;
    else
        node_w_content(stack, new_node);
    stack->size++;
}