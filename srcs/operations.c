/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:48:24 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/20 18:21:30 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	op_sa(t_stack *a)
{
	int	tmp;

	if (a->head == NULL)
		return ;
	tmp = a->head->next->num;
	a->head->next->num = a->head->num;
	a->head->num = tmp;
}

void	op_sb(t_stack *b)
{
	int	tmp;

	if (b->head == NULL)
		return ;
	tmp = b->head->next->num;
	b->head->next->num = b->head->num;
	b->head->num = tmp;
}

void	op_ss(t_stack *a, t_stack *b)
{
	op_sa(a);
	op_sb(b);
}

void	op_pa(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->head == NULL)
		return ;
	tmp = b->head->num;
	stack_del_top(b);
	stack_add_top(a, tmp);
}

void	op_pb(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->head == NULL)
		return ;
	tmp = a->head->num;
	stack_del_top(a);
	stack_add_top(b, tmp);
}

void	op_ra(t_stack *a)
{
	if (a->head != NULL)
		a->head = a->head->next;
}

void	op_rb(t_stack *b)
{
	if (b->head != NULL)
		b->head = b->head->next;
}

void	op_rr(t_stack *a, t_stack *b)
{
	op_ra(a);
	op_rb(b);
}

void	op_rra(t_stack *a)
{
	if (a->head != NULL)
		a->head = a->head->prev;
}

void	op_rrb(t_stack *b)
{
	if (b->head != NULL)
		b->head = b->head->prev;
}

void	op_rrr(t_stack *a, t_stack *b)
{
	op_rra(a);
	op_rrb(b);
}
