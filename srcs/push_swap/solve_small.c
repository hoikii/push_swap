/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 07:15:41 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/24 08:38:03 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_2(t_stack *a, t_stack *b)
{
	if (a->head->num > a->head->next->num)
		do_op(a, b, DO_SA, 1);
}

static void	solve_3(t_stack *a, t_stack *b)
{
	find_minmax(a);
	if (a->max == a->head->num)
		do_op(a, b, DO_RA, 1);
	else if (a->max == a->head->next->num)
		do_op(a, b, DO_RRA, 1);
	if (a->head->num > a->head->next->num)
		do_op(a, b, DO_SA, 1);
}

static void	solve_4(t_stack *a, t_stack *b)
{
	find_minmax(a);
	if (a->min == a->head->prev->num)
		do_op(a, b, DO_RRA, 1);
	else
	{
		while (a->head->num != a->min)
			do_op(a, b, DO_RA, 1);
	}
	do_op(a, b, DO_PB, 1);
	solve_3(a, b);
	do_op(a, b, DO_PA, 1);
}

static void	solve_5(t_stack *a, t_stack *b)
{
	find_minmax(a);
	if (a->min == a->head->prev->num || a->min == a->head->prev->prev->num)
	{
		while (a->head->num != a->min)
			do_op(a, b, DO_RRA, 1);
	}
	else
	{
		while (a->head->num != a->min)
			do_op(a, b, DO_RA, 1);
	}
	do_op(a, b, DO_PB, 1);
	solve_4(a, b);
	do_op(a, b, DO_PA, 1);
}

void		solve_small(t_stack *a, t_stack *b)
{
	if (a->size <= 2)
		solve_2(a, b);
	else if (a->size <= 3)
		solve_3(a, b);
	else if (a->size <= 4)
		solve_4(a, b);
	else if (a->size <= 5)
		solve_5(a, b);
	else
		solve_big(a, b);
	return ;
}
