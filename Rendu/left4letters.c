/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left4letters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:58:26 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/30 12:51:24 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ds_to_alpha(t_env *env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (env->tetri[i])
	{
		j = 0;
		while (env->tetri[i][j])
		{
			if (env->tetri[i][j] == '#')
				env->tetri[i][j] = ('A' + i);
			j++;
		}
		i++;
	}
}

static void	useless_fct_for_get_25(int *gy, int *iy, int *gx, int *jx)
{
	*gy = *iy;
	*gx = *jx;
}

int			check_pos(int x, int y, char *piece, t_env *env)
{
	int iy;
	int jx;
	int flag;
	int gx;
	int gy;

	iy = -1;
	flag = 0;
	while (++iy < 4)
	{
		jx = -1;
		while (++jx < 5)
			if (piece[iy * 5 + jx] != '.' && piece[iy * 5 + jx] != '\n')
			{
				if (!flag++)
					useless_fct_for_get_25(&gy, &iy, &gx, &jx);
				if ((y + (iy - gy)) >= env->size_m || (x + (jx - gx)) >=
						env->size_m || ((y + iy - gy)) < 0 || (x + (jx - gx))
						< 0 || env->map[y + (iy - gy)][x + (jx - gx)] != '.')
					return (0);
			}
	}
	return (1);
}
