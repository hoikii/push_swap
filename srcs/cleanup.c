/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:49:37 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/24 06:31:44 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static void	free_stack(t_stack *a)
{
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

void		free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

int			error(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	ft_putstr_fd("Error\n", STDERR);
	return (-1);
}
