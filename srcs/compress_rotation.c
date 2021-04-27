/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:50:48 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/27 20:28:16 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void rot_direction_check(t_stack *a)
{
	if (a==NULL)
		return ;
	if (a->rotate_cnt > 0)
	{
		if (a->rotate_cnt > a->size / 2)
			a->rotate_cnt = -1 * (a->size - a->rotate_cnt);
	}
	else if (a->rotate_cnt < 0)
	{
		if (a->rotate_cnt * -1 > a->size / 2)
			a->rotate_cnt = (a->size + a->rotate_cnt);
	}
}

static void	prn_rot_single(t_stack *a, int print, char which)
{
	if (a == NULL)
		return ;
	while (a->rotate_cnt != 0)
	{
		if (a->rotate_cnt > 0)
		{
			if (print && (which == 'a'))
				ft_putstr_fd("ra\n", STDOUT);
			if (print && (which == 'b'))
				ft_putstr_fd("rb\n", STDOUT);
			a->rotate_cnt--;
		}
		else
		{
			if (print && (which == 'a'))
				ft_putstr_fd("rra\n", STDOUT);
			if (print && (which == 'b'))
				ft_putstr_fd("rrb\n", STDOUT);
			a->rotate_cnt++;
		}
	}
}

void	prn_rotation(t_stack *a, t_stack *b, int print)
{
//	rot_direction_check(a);
//	rot_direction_check(b);
if (a != NULL && b != NULL)
{
	if (a->rotate_cnt > 0 && b->rotate_cnt > 0)
	{
		while (a->rotate_cnt * b->rotate_cnt != 0)
		{
			if (print)
				ft_putstr_fd("rr\n", STDOUT);
			a->rotate_cnt--;
			b->rotate_cnt--;
		}

	}
	else if (a->rotate_cnt < 0 && b->rotate_cnt < 0)
	{
		while (a->rotate_cnt * b->rotate_cnt != 0)
		{
			if (print)
				ft_putstr_fd("rrr\n", STDOUT);
			a->rotate_cnt++;
			b->rotate_cnt++;
		}
	}
}
	prn_rot_single(a, print, 'a');
	prn_rot_single(b, print, 'b');
}
