CHECKER_NAME	= checker
CHECKER_SRCS	= srcs/checker/main.c \
				  srcs/gnl/get_next_line.c \
				  srcs/gnl/get_next_line_utils.c
CHECKER_OBJS	= $(CHECKER_SRCS:.c=.o)

PUSHSWAP_NAME	= push_swap
PUSHSWAP_SRCS	= srcs/push_swap/main.c
PUSHSWAP_OBJS	= $(PUSHSWAP_SRCS:.c=.o)

SHARED_SRCS		= srcs/stack.c \
				  srcs/cleanup.c \
				  srcs/fill_stack_a.c \
				  srcs/operations.c \
				  srcs/utils.c
SHARED_OBJS		= $(SHARED_SRCS:.c=.o)

HEADERS		= includes
LIBFTDIR	= libft
LIBFTNAME	= ft
CC			= gcc
###############################
###############################
# CFLAGS		= -Wall -Wextra -Werror
CFLAGS		= -Wall -Wextra
# #############################
# ##############################
LDFLAGS		= -L$(LIBFTDIR) -l$(LIBFTNAME) -lm
RM			= rm -rf

CCBLUE		= \033[34m
CCBLUE_BOLD	= \033[1;34m
CCEND		= \033[0m

.PHONY: test all bonus cleanlib clean fclean re

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

bonus: CFLAGS += -DBONUS -D THREADS_CNT=$(shell getconf _NPROCESSORS_ONLN)
bonus: clean all

test: CFLAGS += -g3 -fsanitize=address
test: all

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

