/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:43:20 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/24 06:22:26 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"
#include "get_next_line.h"

static int	chk_op(char *line)
{
	if (ft_strequ(line, "sa") == 1)
		return (DO_SA);
	if (ft_strequ(line, "sb") == 1)
		return (DO_SB);
	if (ft_strequ(line, "ss") == 1)
		return (DO_SS);
	if (ft_strequ(line, "pa") == 1)
		return (DO_PA);
	if (ft_strequ(line, "pb") == 1)
		return (DO_PB);
	if (ft_strequ(line, "ra") == 1)
		return (DO_RA);
	if (ft_strequ(line, "rb") == 1)
		return (DO_RB);
	if (ft_strequ(line, "rr") == 1)
		return (DO_RR);
	if (ft_strequ(line, "rra") == 1)
		return (DO_RRA);
	if (ft_strequ(line, "rrb") == 1)
		return (DO_RRB);
	if (ft_strequ(line, "rrr") == 1)
		return (DO_RRR);
	return (ERR);
}

static int	read_line(t_stack *a, t_stack *b)
{
	char	*line;
	int		opnum;

	while (get_next_line(STDIN, &line) > 0)
	{
		opnum = chk_op(line);
		free(line);
		if (opnum == ERR)
			return (FAIL);
		do_op(a, b, opnum, 0);
	}
	free(line);
	return (SUCCESS);
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
	if (read_line(&a, &b) == FAIL)
		return (error(&a, &b));
	if (is_sorted(a, b))
		ft_putstr_fd("OK\n", STDOUT);
	else
		ft_putstr_fd("KO\n", STDOUT);
	free_stacks(&a, &b);
	return (0);
}
