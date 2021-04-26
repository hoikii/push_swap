/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 07:16:57 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/26 09:09:49 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"
#include "get_next_line.h"
#include <math.h>

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
		int mididx = a->size / (double)chunk_cnt * (i + i + 1) / 2;
		chunk_boundary->head->mid = arr[mididx];
	}


//	for (int i=0; i < a->size; i++)
//		printf("%d\n", arr[i]);
	free(arr);

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
