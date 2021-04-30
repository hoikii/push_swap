/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 08:34:47 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/29 01:37:25 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(int *arr, t_stack *a)
{
	int		i;
	int		j;
	int		key;
	t_item	*tmp;

	tmp = a->head;
	i = -1;
	while (++i < a->size)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
	}
	i = 0;
	while (++i < a->size)
	{
		key = arr[i];
		j = i;
		while (--j >= 0 && arr[j] > key)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
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
