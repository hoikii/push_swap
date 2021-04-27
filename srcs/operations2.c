/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:48:24 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/27 20:27:08 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	op_pa(t_stack *a, t_stack *b, int print)
{
	int	tmp;

	if (b->head == NULL)
		return ;
	if (print && (a->rotate_cnt != 0 || b->rotate_cnt != 0))
		prn_rotation(a, b, print);
	tmp = b->head->num;
	stack_del_top(b);
	stack_add_top(a, tmp);
	b->size--;
	a->size++;
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
		b->size = 0;
	}
	if (print && (a->rotate_cnt != 0 || b->rotate_cnt != 0))
		prn_rotation(a, b, print);
	tmp = a->head->num;
	stack_del_top(a);
	stack_add_top(b, tmp);
	if (b->max < b->head->num)
		b->max = b->head->num;
	if (b->min > b->head->num)
		b->min = b->head->num;
	b->size++;
	a->size--;
	if (print)
		ft_putstr_fd("pb\n", STDOUT);
}

void	op_ra(t_stack *a)
{
	a->rotate_cnt++;
	if (a->head != NULL)
		a->head = a->head->next;
}

void	op_rb(t_stack *b)
{
	b->rotate_cnt++;
	if (b->head != NULL)
		b->head = b->head->next;
}

void	op_rr(t_stack *a, t_stack *b)
{
	op_ra(a);
	op_rb(b);
}
