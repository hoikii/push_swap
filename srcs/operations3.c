/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:48:24 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/27 19:34:43 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static void rot_direction_check(t_stack *a)
{
	if (a==NULL)
		return ;
	if (a->rotate_reserved > 0)
	{
		if (a->rotate_reserved > a->size / 2)
			a->rotate_reserved = -1 * (a->size - a->rotate_reserved);
	}
	else if (a->rotate_reserved < 0)
	{
		if (a->rotate_reserved * -1 > a->size / 2)
			a->rotate_reserved = (a->size + a->rotate_reserved);
	}
}

static void	prn_rot_single(t_stack *a, int print, char which)
{
	if (a == NULL)
		return ;
	while (a->rotate_reserved != 0)
	{
		if (a->rotate_reserved > 0)
		{
			if (print && (which == 'a'))
				ft_putstr_fd("ra\n", STDOUT);
			if (print && (which == 'b'))
				ft_putstr_fd("rb\n", STDOUT);
			a->rotate_reserved--;
		}
		else
		{
			if (print && (which == 'a'))
				ft_putstr_fd("rra\n", STDOUT);
			if (print && (which == 'b'))
				ft_putstr_fd("rrb\n", STDOUT);
			a->rotate_reserved++;
		}
	}
}

void	prn_rotation(t_stack *a, t_stack *b, int print)
{
//	rot_direction_check(a);
//	rot_direction_check(b);
if (a != NULL && b != NULL)
{
	if (a->rotate_reserved > 0 && b->rotate_reserved > 0)
	{
		while (a->rotate_reserved * b->rotate_reserved != 0)
		{
			if (print)
				ft_putstr_fd("rr\n", STDOUT);
			a->rotate_reserved--;
			b->rotate_reserved--;
		}

	}
	else if (a->rotate_reserved < 0 && b->rotate_reserved < 0)
	{
		while (a->rotate_reserved * b->rotate_reserved != 0)
		{
			if (print)
				ft_putstr_fd("rrr\n", STDOUT);
			a->rotate_reserved++;
			b->rotate_reserved++;
		}
	}
}
	prn_rot_single(a, print, 'a');
	prn_rot_single(b, print, 'b');
}

void	op_rra(t_stack *a)
{
	a->rotate_reserved--;
	if (a->head != NULL)
		a->head = a->head->prev;
}

void	op_rrb(t_stack *b)
{
	b->rotate_reserved--;
	if (b->head != NULL)
		b->head = b->head->prev;
}

void	op_rrr(t_stack *a, t_stack *b)
{
	op_rra(a);
	op_rrb(b);
}
