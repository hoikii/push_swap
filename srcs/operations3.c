/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:48:24 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/27 20:27:43 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	op_rra(t_stack *a)
{
	a->rotate_cnt--;
	if (a->head != NULL)
		a->head = a->head->prev;
}

void	op_rrb(t_stack *b)
{
	b->rotate_cnt--;
	if (b->head != NULL)
		b->head = b->head->prev;
}

void	op_rrr(t_stack *a, t_stack *b)
{
	op_rra(a);
	op_rrb(b);
}
