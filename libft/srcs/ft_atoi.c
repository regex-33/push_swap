/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:57:42 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/26 11:22:22 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(const char *str)
{
	long long	ps_ng;
	long long	result;

	ps_ng = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		ps_ng *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str - 48);
		else
			return (result * ps_ng);
		str++;
	}
	return (result * ps_ng);
}
