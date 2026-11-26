#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

typedef enum e_mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_mode;

/* stacks */
t_node	*new_node(int value);
void	append_node(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
void	init_stacks(t_stack *a, t_stack *b);

/* consultas */
int		is_empty(t_stack *stack);
int		count_nodes(t_stack *stack);
t_node	*find_min(t_stack *stack);
t_node	*find_max(t_stack *stack);
int		get_position(t_stack *stack, int rank);

/* operaciones internas (modifican la lista, NO imprimen) - sin programar */
void	swap_nodes(t_stack *stack);
void	push_node(t_stack *from, t_stack *to);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

/* operaciones publicas (llaman a la interna e imprimen) - sin programar */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* desorden y rangos */
long	count_inversions(t_stack *stack);
double	compute_disorder(t_stack *stack);
void	assign_ranks(t_stack *stack);
int		check_ranks(t_stack *stack);

/* parser */
int		parse_args(int argc, char **argv, t_stack *a, t_mode *mode);
int		parse_mode(char *arg, t_mode *mode);
int		is_valid_number(const char *str);
int		parse_int_checked(const char *str, int *out);
int		has_duplicate(t_stack *stack, int value);

/* utils */
int		ft_strcmp(const char *s1, const char *s2);
int		is_digit(char c);
int		is_sep(char c);

/* movements*/
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

#endif
