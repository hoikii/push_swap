/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:35:40 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/26 09:52:17 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static void	sort_a(int *arr, t_stack *a)
{
	int	i;
	int	j;
	t_item	*tmp;
	
	tmp = a->head;
	i = -1;
	while (++i < a->size)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
	}
	for (int i = 1; i < a->size; i++)
	{
		int key = arr[i];
		for (j = i-1; j >=0 && arr[j] > key; j--)
			arr[j+1] = arr[j];
		arr[j+1] = key;
	}
}
int	find_prevmax(t_stack *a)
{
	int	*arr;
	int ret;

	if (a->size == 1)
		return (a->max);
	arr = malloc(sizeof(int) * a->size);
	sort_a(arr, a);
	ret = arr[a->size - 2];
	free(arr);
	return (ret);
}

int	find_prevmin(t_stack *a)
{
	int	*arr;
	int ret;

	if (a->size == 1)
		return (a->max);
	arr = malloc(sizeof(int) * a->size);
	sort_a(arr, a);
	ret = arr[1];
	free(arr);
	return (ret);
}

static void	prepare(t_stack *b, t_stack *b_sorted)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * b->size);
	sort_a(arr, b);
	i = -1;
	while (++i < b->size)
		stack_add_end(b_sorted, arr[i]);
	free(arr);
	return ;
}


int	get_dist(t_stack *a, int n)
{
	t_item	*tmp;
	int		i;
	
	tmp = a->head;
	i = 0;
	while (tmp->num != n)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < a->size - i)
		return (i);
	return (i - a->size);
}

void	rotate_n_to_top(t_stack *a, int n)
{
	t_item	*tmp;
	int		r_cnt;
	int		rr_cnt;

	tmp = a->head;
	r_cnt = 0;
	while (tmp->num != n)
	{
		r_cnt++;
		tmp = tmp->next;
	}
	rr_cnt = a->size - r_cnt;
	if (r_cnt < rr_cnt)
	{
		while (r_cnt--)
			do_op(NULL, a, DO_RB, 1);
	}
	else
	{
		while (rr_cnt--)
			do_op(NULL, a, DO_RRB, 1);
	}
}
static void del_item(t_stack *b_sorted, int num)
{
	while (b_sorted->head->num != num)
		b_sorted->head = b_sorted->head->next;
	stack_del_top(b_sorted);
}

int		push_min_to_a(t_stack *a, t_stack *b, int min, t_stack *b_sorted)
{
	int next_min;
	int min_dist;
	int nextmin_dist;
	t_item	*idx;
	int	ret;

	ret = 1;
	idx = b_sorted->head;
	while (idx->num != min)
		idx = idx->next;
	min_dist = get_dist(b, min);
	next_min = idx->next->num;
	nextmin_dist = get_dist(b, next_min);
#if 1
	if (ft_abs(nextmin_dist) < ft_abs(min_dist) && nextmin_dist * min_dist >= 0)
		ret = push_min_to_a(a, b, next_min, b_sorted) + 1;
	while (b->head->num != min)
	{
		if (min_dist > 0)
			do_op(a, b, DO_RB, 1);
		else
			do_op(a, b, DO_RRB, 1);
	}
	del_item(b_sorted, b->head->num);
	do_op(a, b, DO_PA, 1);
	return (ret);
#else
	if (b->size < 5 || ft_abs(nextmin_dist) + 1 > ft_abs(min_dist))
	{
		if (min_dist > 0)
		{
			while (min_dist--)
				do_op(a, b, DO_RB, 1);
		}
		else 
		{
			while (min_dist++ < 0)
				do_op(a, b, DO_RRB, 1);
		}
		do_op(a, b, DO_PA, 1);
		do_op(a, b, DO_RA, 1);
	}
	else
	{
		rotate_n_to_top(b, find_prevmin(b));
		do_op(a, b, DO_PA, 1);
		rotate_n_to_top(b, b->min);
		do_op(a, b, DO_PA, 1);
		do_op(a, b, DO_RA, 1);
		do_op(a, b, DO_RA, 1);
	}
#endif
}

int		push_max_to_a(t_stack *a, t_stack *b, int max, int depth, t_stack *b_sorted)
{
	int		ret;
	int prevmax;
	int max_dist;
	int prevmax_dist;
	t_item	*idx;

	ret = 1;
	idx = b_sorted->head;
	while (idx->num != max)
		idx = idx->next;
	max_dist = get_dist(b, max);
	prevmax = idx->prev->num;
	prevmax_dist = get_dist(b, prevmax);

#if 1
	if (ft_abs(prevmax_dist) + 1 < ft_abs(max_dist) && prevmax_dist * max_dist >= 0)
		ret = push_max_to_a(a, b, prevmax, depth + 1, b_sorted) + 1;
	while (b->head->num != max)
	{
		if (max_dist > 0)
			do_op(a, b, DO_RB, 1);
		else
			do_op(a, b, DO_RRB, 1);
	}
	del_item(b_sorted, b->head->num);
	do_op(a, b, DO_PA, 1);
	if (depth >= 3)
		do_op(a, b, DO_RA, 1);
	return (ret);
#else
		if (b->size < 3 || ft_abs(prevmax_dist) + 1 > ft_abs(max_dist))
		{
			if (max_dist > 0)
			{
				while (max_dist--)
					do_op(a, b, DO_RB, 1);
			}
			else
			{
				while (max_dist++ < 0)
					do_op(a, b, DO_RRB, 1);
			}
		del_item(b_sorted, b->head->num);
			do_op(a, b, DO_PA, 1);
		}
		else
		{
			rotate_n_to_top(b, find_prevmax(b));
		del_item(b_sorted, b->head->num);
			do_op(a, b, DO_PA, 1);
			rotate_n_to_top(b, b->max);
		del_item(b_sorted, b->head->num);
			do_op(a, b, DO_PA, 1);
			do_op(a, b, DO_SA, 1);
		}
#endif

	ret = 1;
	return (ret);
}

void	push_chunk_to_a(t_stack *a, t_stack *b)
{
	int		max_dist;
	int		min_dist;
	t_stack	b_sorted;
	int		depth_cnt;

	ft_memset(&b_sorted, 0, sizeof(t_stack));
		prepare(b, &b_sorted);
	while (b->head != NULL)
	{
		find_minmax(b);
		max_dist = get_dist(b, b->max);
		min_dist = get_dist(b, b->min);
		int flag = (b->size > 5) ? 3 : 1;
		if (ft_abs(min_dist) + flag < ft_abs(max_dist))
		{
			depth_cnt = push_min_to_a(a, b, b->min, &b_sorted);
			while (depth_cnt--)
				do_op(a, b, DO_RA, 1);
		}
		else
		{
			depth_cnt = push_max_to_a(a, b, b->max, 1, &b_sorted);
			if (depth_cnt >= 2)
				do_op(a, b, DO_SA, 1);
			while (depth_cnt-- >= 3)
				do_op(a, b, DO_RRA, 1);
		}
	}
}

