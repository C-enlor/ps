#include "../push_swap.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Programa SOLO de pruebas (make test). No forma parte de push_swap. */

static int	g_ok = 0;
static int	g_fail = 0;

static void	check(int cond, const char *name)
{
	if (cond)
		g_ok++;
	else
	{
		g_fail++;
		fprintf(stderr, "FALLA: %s\n", name);
	}
}

/* herramienta de depuracion: muestra A y B por stderr */
static void	print_stack(const char *name, t_stack *s, int ranks)
{
	t_node	*aux;

	fprintf(stderr, "[%s] size=%d: ", name, s->size);
	aux = s->head;
	while (aux != NULL)
	{
		if (ranks)
			fprintf(stderr, "%d(r%d) -> ", aux->value, aux->rank);
		else
			fprintf(stderr, "%d -> ", aux->value);
		aux = aux->next;
	}
	fprintf(stderr, "NULL\n");
}

static void	build(t_stack *s, int *v, int n)
{
	int	i;

	s->head = NULL;
	s->size = 0;
	i = 0;
	while (i < n)
		append_node(s, new_node(v[i++]));
}

static void	to_str(t_stack *s, char *out, int ranks)
{
	t_node	*aux;
	char	tmp[32];

	out[0] = '\0';
	aux = s->head;
	while (aux != NULL)
	{
		sprintf(tmp, "%d", ranks ? aux->rank : aux->value);
		strcat(out, tmp);
		if (aux->next)
			strcat(out, " ");
		aux = aux->next;
	}
}

static void	stage1(void)
{
	t_stack	a;
	t_stack	empty;
	char	buf[128];
	int		v[] = {4, 8, 2};

	build(&a, v, 3);
	to_str(&a, buf, 0);
	check(strcmp(buf, "4 8 2") == 0, "E1 recorrido 4 8 2");
	check(a.size == 3 && count_nodes(&a) == 3, "E1 size == nodos recorridos");
	check(find_min(&a)->value == 2, "E1 find_min");
	check(find_max(&a)->value == 8, "E1 find_max");
	assign_ranks(&a);
	check(get_position(&a, 0) == 2 && get_position(&a, 2) == 1, "E1 get_position");
	check(get_position(&a, 9) == -1, "E1 get_position inexistente");
	free_stack(&a);
	check(a.head == NULL && a.size == 0, "E1 free deja pila vacia");
	init_stacks(&empty, &a);
	check(is_empty(&empty) && find_min(&empty) == NULL, "E1 pila vacia");
	free_stack(&empty);
	build(&a, v, 1);
	check(!is_empty(&a) && is_sorted(&a), "E1 un nodo");
	free_stack(&a);
}

static void	disorder_case(int *v, int n, double expected, const char *name)
{
	t_stack	s;

	build(&s, v, n);
	check(fabs(compute_disorder(&s) - expected) < 1e-9, name);
	free_stack(&s);
}

static void	stage4(void)
{
	int	a1[] = {1, 2, 3, 4};
	int	a2[] = {3, 1, 2};
	int	a3[] = {4, 3, 2, 1};
	int	a4[] = {2, 1, 3, 4};
	int	a5[] = {7};

	disorder_case(a1, 4, 0.0, "E4 [1 2 3 4] = 0");
	disorder_case(a2, 3, 2.0 / 3.0, "E4 [3 1 2] = 2/3");
	disorder_case(a3, 4, 1.0, "E4 [4 3 2 1] = 1");
	disorder_case(a4, 4, 1.0 / 6.0, "E4 [2 1 3 4] = 1/6");
	disorder_case(a5, 1, 0.0, "E4 un nodo = 0");
	disorder_case(a5, 0, 0.0, "E4 vacia = 0");
}

static void	rank_case(int *v, int n, const char *expected, const char *name)
{
	t_stack	s;
	char	vals[128];
	char	before[128];
	char	buf[128];

	build(&s, v, n);
	to_str(&s, before, 0);
	assign_ranks(&s);
	to_str(&s, buf, 1);
	check(strcmp(buf, expected) == 0, name);
	to_str(&s, vals, 0);
	check(strcmp(before, vals) == 0, "E5 los valores no cambian");
	check(check_ranks(&s), "E5 rangos son 0..n-1 sin huecos");
	free_stack(&s);
}

static void	stage5(void)
{
	int		a1[] = {50, 10, 30};
	int		a2[] = {40, -9, 7, 22};
	int		a3[] = {INT_MAX, 0, INT_MIN, -1};
	int		a4[] = {1, 2, 3, 4};
	t_stack	s;

	rank_case(a1, 3, "2 0 1", "E5 [50 10 30] -> [2 0 1]");
	rank_case(a2, 4, "3 0 1 2", "E5 [40 -9 7 22] -> [3 0 1 2]");
	rank_case(a3, 4, "3 2 0 1", "E5 extremos de int");
	rank_case(a4, 4, "0 1 2 3", "E5 ya ordenada -> rangos ascendentes");
	build(&s, a4, 4);
	assign_ranks(&s);
	s.head->rank = 3;
	check(!check_ranks(&s), "E5 check_ranks detecta repetido");
	print_stack("A", &s, 1);
	free_stack(&s);
}

int	main(void)
{
	stage1();
	stage4();
	stage5();
	printf("tests OK: %d | FALLOS: %d\n", g_ok, g_fail);
	return (g_fail != 0);
}
