/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 07:16:57 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/25 14:00:36 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"
#include "get_next_line.h"
#include <math.h>

int g_xxx = 0;
void	sort_a(int *arr, t_stack *a)
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


void	prepare(t_stack *a, t_stack *chunk_boundary)
{
	int	*arr;

	arr = malloc(sizeof(int) * a->size);
	sort_a(arr, a);
	int chunk_cnt = 1;
#if 0
	chunk_cnt = (int)sqrt(a->size / 8);
#else
	if (a->size > 5)
		chunk_cnt = 2;
	if (a->size > 99)
		chunk_cnt = 3;
	if (a->size > 499)
		chunk_cnt = 6;
#endif
	int i = -1;
	while (++i < chunk_cnt)
	{
		stack_add_top(chunk_boundary, arr[a->size / chunk_cnt * i]);
		int mididx = ((a->size / chunk_cnt * i) + (a->size / chunk_cnt * (i+1)))/2;
		chunk_boundary->head->mid = arr[mididx];
	}


//	for (int i=0; i < a->size; i++)
//		printf("%d\n", arr[i]);
	free(arr);

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
int	find_pprevmin(t_stack *a)
{
	int	*arr;
	int ret;

	if (a->size < 3)
		return (a->max);
	arr = malloc(sizeof(int) * a->size);
	sort_a(arr, a);
	ret = arr[2];
	free(arr);
	return (ret);
}
int	find_pprevmax(t_stack *a)
{
	int	*arr;
	int ret;

	if (a->size < 3)
		return (a->max);
	arr = malloc(sizeof(int) * a->size);
	sort_a(arr, a);
	ret = arr[a->size - 3];
	free(arr);
	return (ret);
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
	return (a->size - i);
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


void	push_chunk_to_a(t_stack *a, t_stack *b)
{
	int	mv_cnt_rb;
	int	mv_cnt_rrb;
	t_item	*tmp;
	int mv_cnt_min_rb;
	int	mv_cnt_min_rrb;

	if (b->head == NULL)
		return ;
	while (b->head != NULL)
	{
		find_minmax(b);
		mv_cnt_rb = 0;
		mv_cnt_rrb = 0;
		mv_cnt_min_rb = 0;
		mv_cnt_min_rrb = 0;
		tmp = b->head;
		while (tmp->num != b->max)
		{
			mv_cnt_rb++;
			tmp = tmp->next;
		}
		tmp = b->head;
		while (tmp->num != b->max)
		{
			mv_cnt_rrb++;
			tmp = tmp->prev;
		}
		tmp = b->head;
		while (tmp->num != b->min)
		{
			mv_cnt_min_rb++;
			tmp = tmp->next;
		}
		tmp = b->head;
		while (tmp->num != b->min)
		{
			mv_cnt_min_rrb++;
			tmp = tmp->prev;
		}
		tmp = b->head;

		int aa = (mv_cnt_rb < mv_cnt_rrb) ? mv_cnt_rb : mv_cnt_rrb;
		int bb = (mv_cnt_min_rb < mv_cnt_min_rrb) ? mv_cnt_min_rb : mv_cnt_min_rrb;
		if (aa > bb)
	{
int prevmin_dist = INT_MAX;
prevmin_dist = get_dist(b, find_prevmin(b));
if (b->size >= 5 && get_dist(b, find_pprevmin(b)) < prevmin_dist)
	g_xxx++;
int min_dist = get_dist(b, b->min);
if (b->size < 5 || prevmin_dist + 1 > min_dist)
{
		if (mv_cnt_min_rb < mv_cnt_min_rrb)
		{
			while (mv_cnt_min_rb--)
				do_op(a, b, DO_RB, 1);
		}
		else
		{
			while (mv_cnt_min_rrb--)
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
	}
		else
	{
		int prevmax_dist = INT_MAX;
		prevmax_dist = get_dist(b, find_prevmax(b));
if (b->size >= 5 && get_dist(b, find_pprevmax(b)) < prevmax_dist)
	g_xxx++;
		int max_dist = get_dist(b, b->max);
		if (b->size < 3 || prevmax_dist + 1 > max_dist)
		{
			if (mv_cnt_rb < mv_cnt_rrb)
			{
				while (mv_cnt_rb--)
					do_op(a, b, DO_RB, 1);
			}
			else
			{
				while (mv_cnt_rrb--)
					do_op(a, b, DO_RRB, 1);
			}
			do_op(a, b, DO_PA, 1);
		}
		else
		{
			rotate_n_to_top(b, find_prevmax(b));
			do_op(a, b, DO_PA, 1);
			rotate_n_to_top(b, b->max);
			do_op(a, b, DO_PA, 1);
			do_op(a, b, DO_SA, 1);
		}


	}
	}
}
void	push_chunk_to_b(t_stack *a, t_stack *b, t_stack *chunk_boundary)
{
	long long	chunk_start_prev;
	long long	chunk_start;
	int			rotate_end;
	int			rotate_finished;
	t_item		*tmp;

	chunk_start_prev = (long long)INT_MAX + 1;

	while (chunk_boundary->head != NULL)
	{
	rotate_finished = 0;
		int aa=0, bb=0;
		tmp = a->head;
		while (tmp->num >= chunk_start_prev)
		{
			aa++;
			tmp = tmp->next;
		}
		tmp = a->head->prev;
		while (tmp->num >= chunk_start_prev)
		{
			bb++;
			tmp = tmp->prev;
		}
		int chunk_size = 0;
		chunk_start = chunk_boundary->head->num;
		tmp = a->head->prev;
		while (1)
		{
			tmp = tmp->next;
			if (chunk_start <= tmp->num && tmp->num < chunk_start_prev)
				chunk_size++;
			if (tmp->next == a->head)
				break ;
		}
		
		if (a->size - bb < a->size - aa + chunk_size + a->size - aa - bb)
//		if (chunk_start_prev >= INT_MAX)
//		if (1)
		{
			while (a->head->num >= chunk_start_prev)
				do_op(a, b, DO_RA, 1);
//		printf("chunk start:%lld\n", chunk_start);
		rotate_end = a->head->prev->num;
		while (a->head->num < chunk_start_prev)
		{
			if (a->head->num == rotate_end)
				rotate_finished = 1;
			int chunk_mid = chunk_boundary->head->mid;
			if (a->head->num >= chunk_start)
			{
#if 1
				if (b->head != NULL)
				{
					int this = b->head->num;
					if (b->head->num < chunk_mid)
						do_op(a, b, DO_RB, 1);
				}
#endif
				do_op(a, b, DO_PB, 1);
			}
			else
			{
				if (b->head != NULL && b->head->num < chunk_mid)
					do_op(a, b, DO_RR, 1);
				else
					do_op(a, b, DO_RA, 1);
			}
			if (rotate_finished)
				break ;
		}
		chunk_start_prev = chunk_start;
		stack_del_top(chunk_boundary);
		}
		else
		{
			while (a->head->num >= chunk_start_prev)
				do_op(a, b, DO_RRA, 1);

		rotate_end = a->head->next->num;
		while (a->head->num < chunk_start_prev)
		{
//			if (a->head->num == rotate_end)
//				rotate_finished = 1;
			int chunk_mid = chunk_boundary->head->mid;
			if (a->head->num >= chunk_start)
			{
#if 1
				if (b->head != NULL)
				{
					int this = b->head->num;
					if (b->head->num < chunk_mid)
						do_op(a, b, DO_RB, 1);
				}
#endif
				do_op(a, b, DO_PB, 1);
				do_op(a, b, DO_RRA, 1);
			}
			else
			{
				if (b->head != NULL && b->head->num >= chunk_mid)
					do_op(a, b, DO_RRR, 1);
				else
					do_op(a, b, DO_RRA, 1);
			}
//			if (rotate_finished)
//				break ;
		}
		while (a->head->num != rotate_end)
			do_op(a, b, DO_RA, 1);
		chunk_start_prev = chunk_start;
		stack_del_top(chunk_boundary);
		}
				push_chunk_to_a(a, b);


				
	}

	return;
}







void	finalize(t_stack *a)
{
	if (a->head == NULL)
		return ;
	find_minmax(a);
	while (a->head->num != a->min)
		do_op(a, NULL, DO_RRA, 1);
}

void	solve_big(t_stack *a, t_stack *b)
{
	t_stack	chunk_boundary;

	ft_memset(&chunk_boundary, 0, sizeof(t_stack));
		prepare(a, &chunk_boundary);
		push_chunk_to_b(a, b, &chunk_boundary);
		finalize(a);
printf("gxxx=%d\n",g_xxx);
}

