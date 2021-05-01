/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:48:24 by kanlee            #+#    #+#             */
/*   Updated: 2021/05/01 19:07:02 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	op_sa(t_stack *a, int print)
{
	int	tmp;

	if (a->head == NULL)
		return ;
	if (print && a->rotate_cnt != 0)
		prn_rotation(a, NULL);
	tmp = a->head->next->num;
	a->head->next->num = a->head->num;
	a->head->num = tmp;
	if (print)
		ft_putstr_fd("sa\n", STDOUT);
}

void	op_sb(t_stack *b, int print)
{
	int	tmp;

	if (b->head == NULL)
		return ;
	if (print && b->rotate_cnt != 0)
		prn_rotation(NULL, b);
	tmp = b->head->next->num;
	b->head->next->num = b->head->num;
	b->head->num = tmp;
	if (print)
		ft_putstr_fd("sb\n", STDOUT);
}

void	op_ss(t_stack *a, t_stack *b, int print)
{
	if (print && (a->rotate_cnt != 0 || b->rotate_cnt != 0))
		prn_rotation(a, b);
	op_sa(a, 0);
	op_sb(b, 0);
	if (print)
		ft_putstr_fd("ss\n", STDOUT);
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
		return (op_ra(a));
	if (opnum == DO_RB)
		return (op_rb(b));
	if (opnum == DO_RR)
		return (op_rr(a, b));
	if (opnum == DO_RRA)
		return (op_rra(a));
	if (opnum == DO_RRB)
		return (op_rrb(b));
	if (opnum == DO_RRR)
		return (op_rrr(a, b));
}
