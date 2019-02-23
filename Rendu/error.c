/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:50:17 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/30 12:51:13 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	a4dans1pickup(int fd, int ds, int nl, int bnl)
{
	char	buff[1];

	while (read(fd, buff, 1))
	{
		bnl++;
		if (buff[0] == '\n')
		{
			bnl--;
			nl++;
			if ((nl % 5 == 0 && bnl != 0) || (nl % 5 == 4 && ds % 4 != 0)
					|| (nl % 5 != 0 && bnl != 4))
				return (0);
			bnl = 0;
		}
		else if (buff[0] != '.' && buff[0] != '#')
			return (0);
		if (buff[0] == '#')
			ds++;
	}
	if (nl % 5 != 4 || ds % 4 != 0)
		return (0);
	return (1);
}

int			ctoi_l_error(char **av)
{
	int fd;
	int nl;
	int bnl;
	int ds;

	nl = 0;
	bnl = 0;
	ds = 0;
	fd = open(av[1], O_RDONLY);
	if (!a4dans1pickup(fd, ds, nl, bnl))
		return (0);
	return (1);
}

static int	compte_les_lainks(char **tetri, int i, int j)
{
	int cpt;

	cpt = 0;
	if (j != 0 && tetri[i][j - 1] == '#')
		cpt++;
	if (j > 4 && tetri[i][j - 5] == '#')
		cpt++;
	if (j < 20 && tetri[i][j + 1] == '#')
		cpt++;
	if (j < 16 && tetri[i][j + 5] == '#')
		cpt++;
	return (cpt);
}

int			c_pas_zelda(char **tetri)
{
	int i;
	int j;
	int cpt;

	i = 0;
	j = 0;
	while (tetri[i] != 0)
	{
		cpt = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] == '#')
				cpt += compte_les_lainks(tetri, i, j);
			j++;
		}
		if (cpt != 6 && cpt != 8)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

void		ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}
