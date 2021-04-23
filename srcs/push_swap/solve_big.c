/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 07:16:57 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/24 07:26:34 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"
#include "get_next_line.h"
#include <math.h>

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
	chunk_cnt = (int)(sqrt(a->size) / 2);
#else
	if (a->size > 5)
		chunk_cnt = 2;
	if (a->size > 99)
		chunk_cnt = 4;
	if (a->size > 499)
		chunk_cnt = 8;
#endif
	int i = -1;
	while (++i < chunk_cnt)
		stack_add_top(chunk_boundary, arr[a->size / chunk_cnt * i]);


//	for (int i=0; i < a->size; i++)
//		printf("%d\n", arr[i]);
	free(arr);

}
void	find_minmax(t_stack *a)
{
	t_item *tmp;

	a->min = INT_MAX;
	a->max = INT_MIN;
	tmp = a->head;
	while (1)
	{
		if (a->min > tmp->num)
			a->min = tmp->num;
		if (a->max < tmp->num)
			a->max = tmp->num;
		tmp = tmp->next;
		if (tmp == a->head)
			break ;
	}
	return ;
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

		if (aa <= bb)
	{
		if (mv_cnt_rb == 0)
			do_op(a, b, DO_PA, 1);
		else if (mv_cnt_rb < mv_cnt_rrb)
		{
			while (mv_cnt_rb--)
				do_op(a, b, DO_RB, 1);
			do_op(a, b, DO_PA, 1);
		}
		else
		{
			while (mv_cnt_rrb--)
				do_op(a, b, DO_RRB, 1);
			do_op(a, b, DO_PA, 1);
		}
	}
		else
	{
		if (mv_cnt_min_rb == 0)
			do_op(a, b, DO_PA, 1);
		else if (mv_cnt_min_rb < mv_cnt_min_rrb)
		{
			while (mv_cnt_min_rb--)
				do_op(a, b, DO_RB, 1);
			do_op(a, b, DO_PA, 1);
		}
		else
		{
			while (mv_cnt_min_rrb--)
				do_op(a, b, DO_RRB, 1);
			do_op(a, b, DO_PA, 1);
		}
		do_op(a, b, DO_RA, 1);
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
		bb = a->size - aa;
		if (aa < bb)
		{
			while (a->head->num >= chunk_start_prev)
				do_op(a, b, DO_RA, 1);
		}
		else
		{
			while (bb--)
				do_op(a, b, DO_RRA, 1);
		}
		chunk_start = chunk_boundary->head->num;
//		printf("chunk start:%lld\n", chunk_start);
		rotate_end = a->head->prev->num;
		while (a->head->num < chunk_start_prev)
		{
			if (a->head->num == rotate_end)
				rotate_finished = 1;
			if (a->head->num >= chunk_start)
				do_op(a, b, DO_PB, 1);
			else
			{
//				if (b->head != NULL && b->head->next->num > b->head->num)
//					do_op(a, b, DO_RR, 1);
//				else
					do_op(a, b, DO_RA, 1);
			}
			if (rotate_finished)
				break ;
		}
		chunk_start_prev = chunk_start;
		stack_del_top(chunk_boundary);
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
}

