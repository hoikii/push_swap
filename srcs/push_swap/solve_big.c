/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 07:16:57 by kanlee            #+#    #+#             */
/*   Updated: 2021/05/01 20:16:25 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"
#include "get_next_line.h"
#include <math.h>

static int	approx_sqrt(double n)
{
	int i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}

void		prepare(t_stack *a, t_stack *chunk_boundary)
{
	int	*arr;
	int	i;
	int	chunk_cnt;
	int	mididx;

	arr = malloc(sizeof(int) * a->size);
	sort_a(arr, a);
	chunk_cnt = 1;
	if (a->size > 30)
		chunk_cnt = approx_sqrt(a->size / 16.0);
	i = -1;
	while (++i < chunk_cnt)
	{
		stack_add_top(chunk_boundary, arr[a->size / chunk_cnt * i]);
		mididx = a->size / (double)chunk_cnt * (i + i + 1) / 2;
		chunk_boundary->head->mid = arr[mididx];
	}
	free(arr);
}

void		finalize(t_stack *a)
{
	if (a->head == NULL)
		return ;
	find_minmax(a);
	while (a->head->num != a->min)
		do_op(a, NULL, DO_RRA, 1);
	prn_rotation(a, NULL);
}

void		solve_big(t_stack *a, t_stack *b)
{
	t_stack	chunk_boundary;

	ft_memset(&chunk_boundary, 0, sizeof(t_stack));
	prepare(a, &chunk_boundary);
	push_chunk_to_b(a, b, &chunk_boundary);
	free_stack(&chunk_boundary);
	finalize(a);
}
