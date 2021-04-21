/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:54:52 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/19 18:16:12 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	is_space(char ch)
{
	return (ch == '\t' || ch == '\n' || ch == ' '
		|| ch == '\v' || ch == '\r' || ch == '\f');
}

int			ft_atoi(const char *nptr, int *n)
{
	int			sign;
	long long	result;

	while (is_space(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	result = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		result = result * 10 + (*nptr++ - '0');
		if (sign * result > INT_MAX)
			return (-1);
		else if (sign * result < INT_MIN)
			return (-1);
	}
	*n = sign * result;
	return (1);
}
