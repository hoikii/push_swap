/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:57:21 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/22 01:25:55 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define FAIL 0
# define SUCCESS 1

typedef struct		 s_item {
	struct s_item	*prev;
	struct s_item	*next;
	int				num;
}					t_item;

typedef struct	s_stack {
	t_item		*head;
	int			size;
	int			min;
	int			max;
}				t_stack;

void	free_split(char **str);
void	free_stacks(t_stack *a, t_stack *b);
int		fill_stack_a(t_stack *a, char **av);

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

void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

#endif
