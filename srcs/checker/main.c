/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:43:20 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/22 00:56:55 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"
#include "get_next_line.h"

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

int chk_op(char *line)
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

void	do_op(t_stack *a, t_stack *b, int opnum)
{
	if (opnum == DO_SA)
		return (op_sa(a));
	if (opnum == DO_SB)
		return (op_sb(b));
	if (opnum == DO_SS)
		return (op_ss(a, b));
	if (opnum == DO_PA)
		return (op_pa(a, b));
	if (opnum == DO_PB)
		return (op_pb(a, b));
	if (opnum == DO_RA)
		return (op_ra(a));
	if (opnum == DO_RB)
		return (op_rb(b));
	if (opnum == DO_RR)
		return (op_rr(a, b));
	if (opnum == DO_RRA)
		return (op_rra(a));
	if (opnum == DO_RRB)
		return (op_rrb(b));
	if (opnum == DO_RRR)
		return (op_rrr(a, b));
}

int	is_sorted(t_stack a, t_stack b)
{
	int		n;
	t_item	*tmp;

	if (b.head != NULL)
		return (0);
	tmp = a.head;
	n = tmp->num;
	while (tmp->next != a.head)
	{
		if (n > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int main(int ac, char **av) {
	t_stack	a;
	t_stack	b;
	char	*line;
	int	opnum;

	ft_memset(&a, 0, sizeof(t_stack));
	ft_memset(&b, 0, sizeof(t_stack));
	if (ac < 2)
		return (error(&a, &b));
	if (fill_stack_a(&a, av) == FAIL)
		return (error(&a, &b));
	while (get_next_line(STDIN, &line) > 0)
	{
		opnum = chk_op(line);
		free(line);
		if (opnum == ERR)
			return (error(&a, &b));
		do_op(&a, &b, opnum);
	}
	free(line);
	if (is_sorted(a, b))
		ft_putstr_fd("OK\n", STDOUT);
	else
		ft_putstr_fd("KO\n", STDOUT);
	free_stacks(&a, &b);
	return (0);
}
