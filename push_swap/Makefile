NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= push_swap.c init_stacks.c new_node.c append_node.c free_stack.c \
		  is_sorten.c utils.c parse_flags.c parse_number.c \
		  parse_duplicates.c parse_args.c stack_queries.c disorder.c rank.c \
		  swap.c push.c rotate.c reverse_rotate.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test_ps

re: fclean all

TEST_SRCS = $(filter-out push_swap.c, $(SRCS)) tests/test_stages.c

test: $(TEST_SRCS) push_swap.h
	$(CC) $(CFLAGS) -g -fsanitize=address,undefined $(TEST_SRCS) -o test_ps
	./test_ps

.PHONY: all clean fclean re test
