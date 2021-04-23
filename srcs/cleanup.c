/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:49:37 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/24 05:54:20 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

void	free_split(char **str)
{
	int i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
	return ;
}

void	free_stacks(t_stack *a, t_stack *b)
{
#if 1
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
	head = b->head;
	it = b->head;
	tmp = it;
	while (it != NULL)
	{
		tmp = it;
		it = it->next;
		free(tmp);
		if (it == head)
			break ;
	}
#endif
}

int error(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	ft_putstr_fd("Error\n",STDERR);
	return (-1);
}
