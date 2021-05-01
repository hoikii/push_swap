/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:28:02 by kanlee            #+#    #+#             */
/*   Updated: 2021/05/01 13:23:30 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	stack_add_top(t_stack *stack, int n)
{
	t_item	*tmp;

	tmp = (t_item *)malloc(sizeof(t_item));
	if (tmp != NULL)
	{
		tmp->num = n;
		if (stack->head == NULL)
		{
			stack->head = tmp;
			tmp->next = tmp;
			tmp->prev = tmp;
			return ;
		}
		tmp->next = stack->head;
		tmp->prev = stack->head->prev;
		tmp->prev->next = tmp;
		stack->head->prev = tmp;
		stack->head = tmp;
	}
	return ;
}

void	stack_add_end(t_stack *stack, int n)
{
	t_item	*tmp;

	if (stack->head == NULL)
	{
		stack_add_top(stack, n);
		return ;
	}
	tmp = (t_item *)malloc(sizeof(t_item));
	if (tmp != NULL)
	{
		tmp->num = n;
		tmp->next = stack->head;
		tmp->prev = stack->head->prev;
		stack->head->prev->next = tmp;
		stack->head->prev = tmp;
	}
	return ;
}

void	stack_del_top(t_stack *stack)
{
	t_item	*tmp;

	if (stack->head == NULL)
		return ;
	if (stack->head->next == stack->head)
	{
		free(stack->head);
		stack->head = NULL;
	}
	else
	{
		tmp = stack->head;
		stack->head->prev->next = stack->head->next;
		stack->head->next->prev = stack->head->prev;
		stack->head = stack->head->next;
		free(tmp);
	}
}

void	stack_del_item(t_s
