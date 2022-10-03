/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:15:16 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/07 19:12:49 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	contador;

	contador = 0;
	if (n == 0)
		return (0);
	while (s2[contador] && s1[contador]
		&& s1[contador] == s2[contador] && contador + 1 < n)
		contador++;
	return (((unsigned char *)s1)[contador] - ((unsigned char *)s2)[contador]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double	double_atoi(const char *str)
{
	int		i;
	double	j;
	double	sum;
	double	temp;

	i = 0;
	j = 1;
	temp = 0.1;
	if (str[i] == '-' && str[i++] == '-')
		j = -1;
	else if (str[i] == '+')
		i++;
	sum = 0.0;
	while (str[i] > 47 && str[i] < 58 && str[i] != '.')
		sum = (sum * 10) + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		sum += ((str[i] - 48) * temp);
		temp /= 10;
		i++;
	}
	return (sum * j);
}
