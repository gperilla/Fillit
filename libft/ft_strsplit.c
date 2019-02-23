/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:26:20 by gperilla          #+#    #+#             */
/*   Updated: 2017/11/13 10:56:28 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strsplit_wordcount(char const *str, char c)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			cpt++;
		i++;
	}
	return (cpt);
}

static int	ft_strsplit_lettercount(char const *str, char c, int nb)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			word++;
		if (word == nb)
		{
			word = 0;
			while (str[i] != c && str[i] != '\0')
			{
				word++;
				i++;
			}
			return (word);
		}
		i++;
	}
	return (0);
}

static char	*ft_strsplit_writeword(char *dst, char const *src, char c, int nb)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (src[i])
	{
		if (src[i] != c && (i == 0 || src[i - 1] == c))
			word++;
		if (word == nb)
		{
			word = 0;
			while (src[i] != c && src[i] != '\0')
			{
				dst[word++] = src[i];
				i++;
			}
			dst[word] = '\0';
			return (dst);
		}
		i++;
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char*) *
		ft_strsplit_wordcount(s, c) + 1)))
		return (NULL);
	i = 0;
	while (i < ft_strsplit_wordcount(s, c))
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) *
			ft_strsplit_lettercount(s, c, i + 1))))
			return (NULL);
		tab[i] = ft_strsplit_writeword(tab[i], s, c, i + 1);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
