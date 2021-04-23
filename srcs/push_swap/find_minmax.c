/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 08:34:47 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/24 08:35:07 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
