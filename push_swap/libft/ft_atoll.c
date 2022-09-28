/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:54:01 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 14:53:09 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

long long	ft_atoll(const char *str)
{
	long long	ret;
	long long	sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (ret >= 9223372036854775807 && sign == -1)
			return (-1);
		if (ret > 9223372036854775807 && sign == 1)
			return (0);
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (ret * sign);
}
