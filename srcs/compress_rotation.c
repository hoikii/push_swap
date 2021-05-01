/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:50:48 by kanlee            #+#    #+#             */
/*   Updated: 2021/05/01 19:34:30 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	rot_direction_check(t_stack *a)
{
	if (a == NULL)
		return ;
	if (a->rotate_cnt > 0)
	{
		if (a->rotate_cnt > a->size - a->rotate_cnt)
			a->rotate_cnt = -1 * (a->size - a->rotate_cnt);
	}
	else if (a->rotate_cnt < 0)
	{
		if (0 - a->rotate_cnt > a->size + a->rotate_cnt)
			a->rotate_cnt = a->size + a->rotate_cnt;
	}
}

static void	prn_rotation_single(t_stack *a, char which)
{
	if (a == NULL)
		return ;
	while (a->rotate_cnt != 0)
	{
		if (a->rotate_cnt > 0)
		{
			if (which == 'a')
				ft_putstr_fd("ra\n", STDOUT);
			if (which == 'b')
				ft_putstr_fd("rb\n", STDOUT);
			a->rotate_cnt--;
		}
		else
		{
			if (which == 'a')
				ft_putstr_fd("rra\n", STDOUT);
			if (which == 'b')
				ft_putstr_fd("rrb\n", STDOUT);
			a->rotate_cnt++;
		}
	}
}

static void	prn_rotation_both(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL)
		return ;
	while (a->rotate_cnt > 0 && b->rotate_cnt > 0)
	{
		ft_putstr_fd("rr\n", STDOUT);
		a->rotate_cnt--;
		b->rotate_cnt--;
	}
	while (a->rotate_cnt < 0 && b->rotate_cnt < 0)
	{
		ft_putstr_fd("rrr\n", STDOUT);
		a->rotate_cnt++;
		b->rotate_cnt++;
	}
}

void		prn_rotation(t_stack *a, t_stack *b)
{
	rot_direction_check(a);
	rot_direction_check(b);
	prn_rotation_both(a, b);
	prn_rotation_single(a, 'a');
	prn_rotation_single(b, 'b');
}
