/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:51:54 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/27 18:56:12 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static void	free_split(char **str)
{
	int i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
	return ;
}

static int	chk_dups(t_stack *a, int n)
{
	t_item *it;

	if (a->head == NULL)
		return (SUCCESS);
	if (a->head->num == n)
		return (FAIL);
	it = a->head->next;
	while (it != a->head)
	{
		if (it->num == n)
			return (FAIL);
		it = it->next;
	}
	return (SUCCESS);
}

int			fill_stack_a(t_stack *a, char **av)
{
	int		i;
	int		j;
	int		n;
	char	**str;

	i = 0;
	while (av[++i] != NULL)
	{
		j = -1;
		str = ft_split(av[i], ' ');
		while (str[++j] != NULL)
		{
			if (ft_atoi(str[j], &n) < 0 || (chk_dups(a, n) == FAIL))
			{
				free_split(str);
				return (FAIL);
			}
			stack_add_end(a, n);
			a->size++;
		}
		free_split(str);
	}
	return (SUCCESS);
}
