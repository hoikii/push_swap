/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:48:24 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/24 06:37:03 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	op_rra(t_stack *a, int print)
{
	if (a->head != NULL)
		a->head = a->head->prev;
	if (print)
		ft_putstr_fd("rra\n", STDOUT);
}

void	op_rrb(t_stack *b, int print)
{
	if (b->head != NULL)
		b->head = b->head->prev;
	if (print)
		ft_putstr_fd("rrb\n", STDOUT);
}

void	op_rrr(t_stack *a, t_stack *b, int print)
{
	op_rra(a, 0);
	op_rrb(b, 0);
	if (print)
		ft_putstr_fd("rrr\n", STDOUT);
}
