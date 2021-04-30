/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:57:21 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/29 01:05:34 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define FAIL 0
# define SUCCESS 1

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct		s_item {
	struct s_item	*prev;
	struct s_item	*next;
	int				num;
	int				mid;
}					t_item;

typedef struct		s_stack {
	t_item			*head;
	int				size;
	int				min;
	int				max;
	int				rotate_cnt;
}					t_stack;

void	free_stack(t_stack *a);
int		error(t_stack *a, t_stack *b);

int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int a);
void	prn_stack(t_stack st);
int		is_sorted(t_stack a, t_stack b);

int		fill_stack_a(t_stack *a, char **av);
void	push_chunk_to_b(t_stack *a, t_stack *b, t_stack *chunk_boundary);
void	push_chunk_to_a(t_stack *a, t_stack *b);

void	stack_add_top(t_stack *stack, int n);
void	stack_del_top(t_stack *stack);
void	stack_add_end(t_stack *stack, int n);

typedef enum	e_ops {
	ERR = -1,
	DO_SA,
	DO_SB,
	DO_SS,
	DO_PA,
	DO_PB,
	DO_RA,
	DO_RB,
	DO_RR,
	DO_RRA,
	DO_RRB,
	DO_RRR
}				t_ops;

void	op_sa(t_stack *a, int print);
void	op_sb(t_stack *b, int print);
void	op_ss(t_stack *a, t_stack *b, int print);
void	op_pa(t_stack *a, t_stack *b, int print);
void	op_pb(t_stack *a, t_stack *b, int print);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);
void	do_op(t_stack *a, t_stack *b, int opnum, int print);

void	solve_small(t_stack *a, t_stack *b);
void	solve_big(t_stack *a, t_stack *b);
void	find_minmax(t_stack *a);
void	sort_a(int *arr, t_stack *a);
void	prn_rotation(t_stack *a, t_stack *b);

#endif
