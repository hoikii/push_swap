/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:28:30 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/27 12:29:35 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static void	reset_start_position(t_stack *a, t_stack *b, long long edge)
{
	t_item	*tmp;
	int		skip_top;

	skip_top = 0;
	tmp = a->head;
	while (tmp->num >= edge)
	{
		skip_top++;
		tmp = tmp->next;
	}
	if (2 * skip_top < a->size)
	{
		while (skip_top-- > 0)
			do_op(a, b, DO_RA, 1);
	}
	else
	{
		while (a->size - skip_top++ > 0)
			do_op(a, b, DO_RRA, 1);
	}
}

static void	push_or_rotate(t_stack *a, t_stack *b, t_stack *chunk_boundary)
{
	int	chunk_mid;
	int	chunk_start;

	chunk_mid = chunk_boundary->head->mid;
	chunk_start = chunk_boundary->head->num;
	if (a->head->num >= chunk_start)
	{
		if (a->head->num >= chunk_mid)
			{
				while (b->head != NULL && (b->head->num < chunk_mid) && (b->max >= chunk_mid))
					do_op(a, b, DO_RB, 1);
			}
		do_op(a, b, DO_PB, 1);
	}
	else
	{
		if (b->head != NULL && b->head->num < chunk_mid)
			do_op(a, b, DO_RR, 1);
		else
			do_op(a, b, DO_RA, 1);
	}
}

void		push_chunk_to_b(t_stack *a, t_stack *b, t_stack *chunk_boundary)
{
	long long	chunk_start_prev;
	int			rotate_end;
	int			finished;

	chunk_start_prev = (long long)INT_MAX + 1;
	while (chunk_boundary->head != NULL)
	{
		finished = 0;
		reset_start_position(a, b, chunk_start_prev);
		rotate_end = a->head->prev->num;
		while (!finished && a->head->num < chunk_start_prev)
		{
			if (a->head->num == rotate_end)
				finished = 1;
			push_or_rotate(a, b, chunk_boundary);
		}
		chunk_start_prev = chunk_boundary->head->num;
		stack_del_top(chunk_boundary);
		push_chunk_to_a(a, b);
	}
	return ;
}
