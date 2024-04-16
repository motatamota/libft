/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:02:11 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 02:02:11 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	how(long k)
{
	int		l;

	if (k < 0)
		k = -k;
	l = 1;
	while (k >= 10)
	{
		k = k / 10;
		l++;
	}
	return (l);
}

void	set(char *str, long k, int n)
{
	if (k < 10)
	{
		*(str + n) = k + '0';
		return ;
	}
	set(str, k / 10, n - 1);
	*(str + n) = k % 10 + '0';
}

char	*ft_itoa(int n)
{
	int		size;
	long	k;
	char	*str;

	k = n;
	size = how(k);
	if (n < 0)
	{
		k = -k;
		size++;
		str = (char *)malloc(sizeof(char) * (size + 1));
		*str = '-';
		set(str + 1, k, size - 2);
	}
	else
	{
		k = n;
		str = (char *)malloc(sizeof(char) * (size + 1));
		set(str, k, size - 1);
	}
	*(str + size) = '\0';
	return (str);
}
