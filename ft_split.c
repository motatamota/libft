/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:26:27 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:27 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	skip(size_t *p, const char *s, char c)
{
	while (*(s + *p) == c && c)
		(*p)++;
}

int	how(const char *s, char c)
{
	size_t	n;
	int		count;

	n = 0;
	count = 1;
	while (*(s + n))
	{
		if (*(s + n) == c)
		{
			skip(&n, s, c);
			if (*(s + n))
				count++;
			n--;
		}
		n++;
	}
	return (count);
}

void	set_str(size_t p, char **box, const char *s)
{
	size_t	q;
	char	*str;

	str = (char *)malloc(sizeof(char) * (p + 1));
	q = 0;
	while (q < p && *(s + q))
	{
		*(str + q) = *(s + q);
		q++;
	}
	*(str + q) = '\0';
	*box = str;
}

void	set(const char *s, char c, char **box)
{
	size_t	p;
	size_t	ch;

	p = 0;
	ch = 0;
	while (*(s + p))
	{
		if (*(s + p) == c)
		{
			set_str(p - ch, box, s + ch);
			skip(&p, s, c);
			ch = p;
			p--;
			box++;
		}
		p++;
	}
	if (*(s + p - 1) != c)
		set_str(p - ch, box, s + ch);
}

char	**ft_split(char const *s, char c)
{
	size_t	p;
	int		many;
	char	**box;

	if (s == 0)
		return (0);
	p = 0;
	skip(&p, s, c);
	if (*(s + p) == 0)
	{
		box = (char **)malloc(1);
		*box = 0;
		return (box);
	}
	many = how(s + p, c);
	box = (char **)malloc(sizeof(char *) * (many + 1));
	set(s + p, c, box);
	*(box + many) = 0;
	return (box);
}

// int main()
// {
// 	char **box;
// 	int	n;

// 	n = 0;
// 	box = ft_split("", 0);
// 	if (box == 0)
// 		return 0;
// 	while (*(box + n))
// 	{
// 		printf("%s\n", *(box + n));
// 		n++;
// 	}
// }
