/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_recursive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:21:55 by kanlee            #+#    #+#             */
/*   Updated: 2021/05/01 19:06:35 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static void	rotate_n_to_top(t_stack *a, int n)
{
	t_item	*tmp;
	int		r_cnt;

	tmp = a->head;
	r_cnt = 0;
	while (tmp->num != n)
	{
		r_cnt++;
		tmp = tmp->next;
	}
	if (r_cnt < a->size - r_cnt)
	{
		while (r_cnt-- > 0)
			do_op(NULL, a, DO_RB, 1);
	}
	else
	{
		while (a->size - r_cnt++)
			do_op(NULL, a, DO_RRB, 1);
	}
}

static int	push_min_recursive(t_stack *a, t_stack *b, int min)
{
	int		ret;
	int		nextmin;
	int		min_dist;
	int		nextmin_dist;
	t_item	*idx;

	ret = 1;
	idx = b->item_ordered->head;
	while (idx->num != min)
		idx = idx->next;
	nextmin = idx->next->num;
	min_dist = get_dist(b, b->head->num, min);
	nextmin_dist = get_dist(b, b->head->num, nextmin);
	if (ft_abs(min_dist) + ft_abs(get_dist(b, min, nextmin))
		> ft_abs(nextmin_dist) + ft_abs(get_dist(b, nextmin, min)))
		ret = push_min_recursive(a, b, nextmin) + 1;
	rotate_n_to_top(b, min);
	stack_del_item(b->item_ordered, min);
	do_op(a, b, DO_PA, 1);
	return (ret);
}

static int	push_max_recursive(t_stack *a, t_stack *b, int max, int depth)
{
	int		ret;
	int		prevmax;
	int		max_dist;
	int		prevmax_dist;
	t_item	*idx;

	ret = 1;
	idx = b->item_ordered->head;
	while (idx->num != max)
		idx = idx->next;
	prevmax = idx->prev->num;
	max_dist = get_dist(b, b->head->num, max);
	prevmax_dist = get_dist(b, b->head->num, prevmax);
	if (ft_abs(max_dist) + ft_abs(get_dist(b, max, prevmax))
		> ft_abs(prevmax_dist) + ft_abs(get_dist(b, prevmax, max)))
		ret = push_max_recursive(a, b, prevmax, depth + 1) + 1;
	rotate_n_to_top(b, max);
	stack_del_item(b->item_ordered, max);
	do_op(a, b, DO_PA, 1);
	if (depth >= 3)
		do_op(a, b, DO_RA, 1);
	return (ret);
}

void		push_minmax_to_a(t_stack *a, t_stack *b)
{
	int		max_dist;
	int		min_dist;
	int		depth_cnt;

	max_dist = get_dist(b, b->head->num, b->max);
	min_dist = get_dist(b, b->head->num, b->min);
	if (ft_abs(min_dist) < ft_abs(max_dist))
	{
		depth_cnt = push_min_recursive(a, b, b->min);
		while (depth_cnt--)
			do_op(a, b, DO_RA, 1);
	}
	else
	{
		depth_cnt = push_max_recursive(a, b, b->max, 1);
		if (depth_cnt >= 2)
			do_op(a, b, DO_SA, 1);
		while (depth_cnt-- >= 3)
			do_op(a, b, DO_RRA, 1);
	}
}
