/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 05:52:08 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/24 20:23:57 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	prn_stack(t_stack st)
{
	t_item *start;
	t_item *it;

	start = st.head;
	it = start;
	while (it != NULL)
	{
		ft_putnbr_fd(it->num, STDOUT);
		ft_putchar_fd('\n', STDOUT);
		it = it->next;
		if (it == start)
			break ;
	}
}

int		is_sorted(t_stack a, t_stack b)
{
	int		n;
	t_item	*tmp;

	if (b.head != NULL)
		return (0);
	tmp = a.head;
	while (tmp->next != a.head)
	{
		n = tmp->num;
		if (n > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
