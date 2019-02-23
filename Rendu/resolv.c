/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:05:36 by gperilla          #+#    #+#             */
/*   Updated: 2017/11/30 12:51:41 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	useless_fct_for_get_25(int *gy, int *iy, int *gx, int *jx)
{
	*gy = *iy;
	*gx = *jx;
}

static void	place_piece(int x, int y, char *piece, char **map)
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
		{
			if (piece[iy * 5 + jx] != '.' && piece[iy * 5 + jx] != '\n')
			{
				if (!flag)
				{
					useless_fct_for_get_25(&gy, &iy, &gx, &jx);
					flag = 1;
				}
				map[y + (iy - gy)][x + (jx - gx)] = piece[iy * 5 + jx];
			}
		}
	}
}

static void	remove_piece(int x, int y, char *piece, char **map)
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
		{
			if (piece[iy * 5 + jx] != '.' && piece[iy * 5 + jx] != '\n')
			{
				if (!flag)
				{
					useless_fct_for_get_25(&gy, &iy, &gx, &jx);
					flag = 1;
				}
				map[y + (iy - gy)][x + (jx - gx)] = '.';
			}
		}
	}
}

static int	next_piece(t_env *env, int size, int nb_piece)
{
	int x;
	int y;

	if (nb_piece == env->tetri_nbr)
		return (1);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (check_pos(x, y, env->tetri[nb_piece], env))
			{
				place_piece(x, y, env->tetri[nb_piece], env->map);
				if (next_piece(env, size, (nb_piece + 1)))
					return (1);
				remove_piece(x, y, env->tetri[nb_piece], env->map);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int			resolve(t_env *env)
{
	int solved;

	env->size_m = size_map(env->tetri_nbr);
	solved = 0;
	while (!solved)
	{
		env->map = reset_map(env->map, env->size_m);
		solved = next_piece(env, env->size_m, 0);
		env->size_m++;
	}
	return (1);
}
