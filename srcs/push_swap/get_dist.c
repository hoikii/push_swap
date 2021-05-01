/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:23:34 by kanlee            #+#    #+#             */
/*   Updated: 2021/05/01 18:53:51 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_dist(t_stack *a, int from, int to)
{
	t_item	*tmp;
	int		i;

	tmp = a->head;
	while (tmp->num != from)
		tmp = tmp->next;
	i = 0;
	while (tmp->num != to)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < a->size - i)
		return (i);
	return (i - a->size);
}
