/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:59:23 by arowe             #+#    #+#             */
/*   Updated: 2021/10/08 12:59:23 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n'
		|| c == '\t' || c == '\v'
		|| c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int	index;
	int	res;
	int	temp;

	index = 0;
	res = 1;
	temp = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			res *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		if ((temp > temp * 10
				|| temp > (temp * 10) + (str[index] - '0'))
			&& ((temp * 10) + (str[index] - '0')) * -1 != -2147483648)
			return (-1);
		temp *= 10;
		temp += (str[index++] - '0');
	}
	return (temp * res);
}
