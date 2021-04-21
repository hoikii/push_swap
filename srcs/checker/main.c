/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:43:20 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/21 22:06:38 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../libft/libft.h"
#include "../push_swap.h"

static int error(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
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

int main(int ac, char **av) {
	t_stack	a;
	t_stack	b;

	printf("checker\n");
	ft_memset(&a, 0, sizeof(t_stack));
	ft_memset(&b, 0, sizeof(t_stack));

	if (ac < 2)
		return (error(&a, &b));
	if (fill_stack_a(&a, av) == FAIL)
		return (error(&a, &b));



	prn_stack(a);
	free_stacks(&a, &b);
	return 0;
}
