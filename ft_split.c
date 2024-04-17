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
#include <stdio.h>

void	skip(size_t *p, const char *s, char c)
{
	while (*(s + *p) == c && c)
		(*p)++;
}

static int	how(const char *s, char c)
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

static int	set(const char *s, char c, char **box)
{
	size_t	p;
	size_t	ch;

	p = -1;
	ch = 0;
	while (*(s + ++p))
	{
		if (*(s + p) == c)
		{
			*box = ft_strdup(s + ch);
			if (!*box)
				return (0);
			*(*box + p - ch) = '\0';
			skip(&p, s, c);
			ch = p;
			p--;
			box++;
		}
	}
	*box = ft_strdup(s + ch);
	if (*(s + p - 1) != c && !*box)
		return (0);
	if (*(s + p - 1) != c)
		*(*box + p - ch) = '\0';
	return (1);
}

void	splitfree(char **box)
{
	int	n;

	n = 0;
	while (*(box + n))
	{
		free(*(box + n));
		n++;
	}
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
	box = (char **)ft_calloc(sizeof(char *), many + 1);
	if (!box)
		return (0);
	if (!set(s + p, c, box))
	{
		splitfree(box);
		return (0);
	}
	*(box + many) = 0;
	return (box);
}

// #include <stdio.h>
// int main()
// {
// 	char **box;
// 	int	n;

// 	n = 0;
// 	box = ft_split("  tripouille  42  ", ' ');
// 	if (box == 0)
// 		return 0;
// 	while (*(box + n))
// 	{
// 		printf("%s\n", *(box + n));
// 		n++;
// 	}
// }
