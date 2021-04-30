/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:09:11 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/30 15:18:18 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static int	ft_stacksize(t_stack a)
{
	int		cnt;
	t_item	*tmp;

	cnt = 1;
	tmp = a.head->next;
	while (tmp != a.head)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

int			main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	ft_memset(&a, 0, sizeof(t_stack));
	ft_memset(&b, 0, sizeof(t_stack));
	if (ac < 2)
		return (error(&a, &b));
	if (fill_stack_a(&a, av) == FAIL)
		return (error(&a, &b));
	if (!is_sorted(a, b))
	{
		a.size = ft_stacksize(a);
		if (a.size <= 5)
			solve_small(&a, &b);
		else
			solve_big(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
