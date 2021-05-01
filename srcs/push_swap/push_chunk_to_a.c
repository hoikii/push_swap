/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:35:40 by kanlee            #+#    #+#             */
/*   Updated: 2021/05/01 17:33:01 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static void	prepare(t_stack *b, t_stack *b_sorted)
{
	int	*arr;
	int	i;

	ft_memset(b_sorted, 0, sizeof(t_stack));
	arr = malloc(sizeof(int) * b->size);
	sort_a(arr, b);
	i = -1;
	while (++i < b->size)
		stack_add_end(b_sorted, arr[i]);
	b->item_ordered = b_sorted;
	free(arr);
	return ;
}

void		push_chunk_to_a(t_stack *a, t_stack *b)
{
	t_stack	b_sorted;

	prepare(b, &b_sorted);
	while (b->head != NULL)
	{
		find_minmax(b);
		push_minmax_to_a(a, b);
	}
	free_stack(&b_sorted);
}
