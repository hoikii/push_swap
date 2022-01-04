CHECKER_NAME	= checker
CHECKER_SRCS	= srcs/checker/main.c \
				  srcs/gnl/get_next_line.c \
				  srcs/gnl/get_next_line_utils.c
CHECKER_OBJS	= $(CHECKER_SRCS:.c=.o)

PUSHSWAP_NAME	= push_swap
PUSHSWAP_SRCS	= srcs/push_swap/main.c \
				  srcs/push_swap/solve_small.c \
				  srcs/push_swap/solve_big.c \
				  srcs/push_swap/find_minmax.c \
				  srcs/push_swap/get_dist.c \
				  srcs/push_swap/push_chunk_to_b.c \
				  srcs/push_swap/push_chunk_to_a.c \
				  srcs/push_swap/push_to_a_recursive.c
PUSHSWAP_OBJS	= $(PUSHSWAP_SRCS:.c=.o)

SHARED_SRCS		= srcs/stack.c \
				  srcs/cleanup.c \
				  srcs/fill_stack_a.c \
				  srcs/operations.c \
				  srcs/operations2.c \
				  srcs/operations3.c \
				  srcs/utils.c \
				  srcs/compress_rotation.c
SHARED_OBJS		= $(SHARED_SRCS:.c=.o)

HEADERS		= includes
LIBFTDIR	= libft
LIBFTNAME	= ft
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -L$(LIBFTDIR) -l$(LIBFTNAME)
RM			= rm -rf

CCBLUE		= \033[34m
CCBLUE_BOLD	= \033[1;34m
CCEND		= \033[0m

.PHONY: test all cleanlib clean fclean re

all: $(CHECKER_NAME) $(PUSHSWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS) $(SHARED_OBJS)
	@$(MAKE) bonus -C libft
	$(CC) $(CHECKER_OBJS) $(SHARED_OBJS) $(CFLAGS) $(LDFLAGS) -o $(CHECKER_NAME)
	@echo "$(CCBLUE_BOLD) >>> make $(CHECKER_NAME) done!  <<< $(CCEND)"

$(PUSHSWAP_NAME): $(PUSHSWAP_OBJS) $(SHARED_OBJS)
	@$(MAKE) bonus -C libft
	$(CC) $(PUSHSWAP_OBJS) $(SHARED_OBJS) $(CFLAGS) $(LDFLAGS) -o $(PUSHSWAP_NAME)
	@echo "$(CCBLUE_BOLD) >>> make $(PUSHSWAP_NAME) done!  <<< $(CCEND)"

%.o: %.c
	$(CC) -I $(HEADERS) $(CFLAGS) -c $< -o $@

test: CFLAGS += -g3 -fsanitize=address
test: clean all

cleanlib:
	@echo "$(CCBLUE) >>> clean libft <<< $(CCEND)"
	$(MAKE) -C $(LIBFTDIR) fclean

clean:
	@echo "$(CCBLUE) >>> clean main projects object files. <<< $(CCEND)"
	$(RM) $(CHECKER_OBJS) $(PUSHSWAP_OBJS) $(SHARED_OBJS)

fclean: clean cleanlib
	@echo "$(CCBLUE) >>> clean main project's executable. <<< $(CCEND)"
	$(RM) $(CHECKER_NAME) $(PUSHSWAP_NAME)

re: fclean all

