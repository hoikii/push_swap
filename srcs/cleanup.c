/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:49:37 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/29 00:55:46 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

void	free_stack(t_stack *a)
{
	if (a == NULL)
		return ;
	t_item	*head;
	t_item	*it;
	t_item	*tmp;

	head = a->head;
	it = a->head;
	tmp = it;
	while (it != NULL)
	{
		tmp = it;
		it = it->next;
		free(tmp);
		if (it == head)
			break ;
	}
}

int		error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	ft_putstr_fd("Error\n", STDERR);
	return (-1);
}
