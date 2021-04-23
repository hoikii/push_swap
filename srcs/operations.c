/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:48:24 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/23 13:28:35 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "libft.h"

void	op_sa(t_stack *a, int print)
{
	int	tmp;

	if (a->head == NULL)
		return ;
	tmp = a->head->next->num;
	a->head->next->num = a->head->num;
	a->head->num = tmp;
	if (print)
		ft_putstr_fd("sa\n",STDOUT);
}

void	op_sb(t_stack *b, int print)
{
	int	tmp;

	if (b->head == NULL)
		return ;
	tmp = b->head->next->num;
	b->head->next->num = b->head->num;
	b->head->num = tmp;
	if (print)
		ft_putstr_fd("sb\n",STDOUT);
}

void	op_ss(t_stack *a, t_stack *b, int print)
{
	op_sa(a, 0);
	op_sb(b, 0);
	if (print)
		ft_putstr_fd("ss\n",STDOUT);
}

void	op_pa(t_stack *a, t_stack *b, int print)
{
	int	tmp;

	if (b->head == NULL)
		return ;
	tmp = b->head->num;
	stack_del_top(b);
	stack_add_top(a, tmp);
	if (print)
		ft_putstr_fd("pa\n",STDOUT);
}

void	op_pb(t_stack *a, t_stack *b, int print)
{
	int	tmp;

	if (a->head == NULL)
		return ;
	if (b->head == NULL)
	{
		b->min = INT_MAX;
		b->max = INT_MIN;
	}
	tmp = a->head->num;
	stack_del_top(a);
	stack_add_top(b, tmp);
	if (b->max < b->head->num)
		b->max = b->head->num;
	if (b->min > b->head->num)
		b->min = b->head->num;
	if (print)
		ft_putstr_fd("pb\n",STDOUT);
}

void	op_ra(t_stack *a, int print)
{
	if (a->head != NULL)
		a->head = a->head->next;
	if (print)
		ft_putstr_fd("ra\n",STDOUT);
}

void	op_rb(t_stack *b, int print)
{
	if (b->head != NULL)
		b->head = b->head->next;
	if (print)
		ft_putstr_fd("rb\n",STDOUT);
}

void	op_rr(t_stack *a, t_stack *b, int print)
{
	op_ra(a, 0);
	op_rb(b, 0);
	if (print)
		ft_putstr_fd("rr\n",STDOUT);
}

void	op_rra(t_stack *a, int print)
{
	if (a->head != NULL)
		a->head = a->head->prev;
	if (print)
		ft_putstr_fd("rra\n",STDOUT);
}

void	op_rrb(t_stack *b, int print)
{
	if (b->head != NULL)
		b->head = b->head->prev;
	if (print)
		ft_putstr_fd("rrb\n",STDOUT);
}

void	op_rrr(t_stack *a, t_stack *b, int print)
{
	op_rra(a, 0);
	op_rrb(b, 0);
	if (print)
		ft_putstr_fd("rrr\n",STDOUT);
}


void	do_op(t_stack *a, t_stack *b, int opnum, int print)
{
	if (opnum == DO_SA)
		return (op_sa(a, print));
	if (opnum == DO_SB)
		return (op_sb(b, print));
	if (opnum == DO_SS)
		return (op_ss(a, b, print));
	if (opnum == DO_PA)
		return (op_pa(a, b, print));
	if (opnum == DO_PB)
		return (op_pb(a, b, print));
	if (opnum == DO_RA)
		return (op_ra(a, print));
	if (opnum == DO_RB)
		return (op_rb(b, print));
	if (opnum == DO_RR)
		return (op_rr(a, b, print));
	if (opnum == DO_RRA)
		return (op_rra(a, print));
	if (opnum == DO_RRB)
		return (op_rrb(b, print));
	if (opnum == DO_RRR)
		return (op_rrr(a, b, print));
}

