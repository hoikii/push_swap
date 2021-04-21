/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:43:20 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/21 16:48:43 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../libft/libft.h"
#include "../push_swap.h"

static void free_split(char **str)
{
	int i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
	return ;
}

static void	free_all(t_stack *a, t_stack *b)
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
}

static int error(t_stack *a, t_stack *b)
{
	free_all(a, b);
	ft_putstr_fd("Error\n",STDERR);
	return (-1);
}

void prn_stack(t_stack st)
{
	t_item *start;
	t_item *it;

	start = st.head;
	it = start;
	while (it != NULL)
	{
		printf("%d\n", it->num);
		it = it->next;
		if (it == start)
			break ;
	}
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

static int fill_stack_a(t_stack *a, t_stack *b, char **av)
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
		}
		free_split(str);
	}
	return (SUCCESS);
}

int main(int ac, char **av) {
	t_stack	a;
	t_stack	b;

	printf("checker\n");
	ft_memset(&a, 0, sizeof(t_stack));
	ft_memset(&b, 0, sizeof(t_stack));

	if (ac < 2)
		return (error(&a, &b));
	if (fill_stack_a(&a, &b, av) == FAIL)
		return (error(&a, &b));


	prn_stack(a);
	free_all(&a, &b);
	return 0;
}
