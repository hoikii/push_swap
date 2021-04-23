/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:48:24 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/24 06:36:34 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	op_pa(t_stack *a, t_stack *b, int print)
{
	int	tmp;

	if (b->head == NULL)
		return ;
	tmp = b->head->num;
	stack_del_top(b);
	stack_add_top(a, tmp);
	if (print)
		ft_putstr_fd("pa\n", STDOUT);
}

void	op_pb(t_stack *a, t_stack *b, int print)
{
	int	tmp;

	if (a->head == NULL)
		return ;
	if (b->head == NULL)
	{
		b->min = INT_MAX;
		b->max = INT_MIN;
	}
	tmp = a->head->num;
	stack_del_top(a);
	stack_add_top(b, tmp);
	if (b->max < b->head->num)
		b->max = b->head->num;
	if (b->min > b->head->num)
		b->min = b->head->num;
	if (print)
		ft_putstr_fd("pb\n", STDOUT);
}

void	op_ra(t_stack *a, int print)
{
	if (a->head != NULL)
		a->head = a->head->next;
	if (print)
		ft_putstr_fd("ra\n", STDOUT);
}

void	op_rb(t_stack *b, int print)
{
	if (b->head != NULL)
		b->head = b->head->next;
	if (print)
		ft_putstr_fd("rb\n", STDOUT);
}

void	op_rr(t_stack *a, t_stack *b, int print)
{
	op_ra(a, 0);
	op_rb(b, 0);
	if (print)
		ft_putstr_fd("rr\n", STDOUT);
}
