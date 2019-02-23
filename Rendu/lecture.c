/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:47:10 by gperilla          #+#    #+#             */
/*   Updated: 2017/11/30 12:51:19 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

static void	copier_c_mal(char **dst, char *src, int nb)
{
	int		fd;
	int		i;
	char	buff[22];

	fd = open(src, O_RDONLY);
	i = 0;
	while (i < nb)
	{
		ft_memset(buff, '\n', 21);
		buff[21] = '\0';
		if (!read(fd, buff, 21))
			return ;
		ft_strcpy(dst[i], buff);
		i++;
	}
}

void		faites_place(t_env *env, char **av)
{
	int		fd;
	char	buff[1];

	env->tetri_nbr = 1;
	if (av == NULL)
		return ;
	fd = open(av[1], O_RDONLY);
	while (read(fd, buff, 1))
		if (buff[0] == '\n')
			env->tetri_nbr++;
	close(fd);
	env->tetri_nbr = (env->tetri_nbr / 5);
	env->tetri = (char**)malloc(sizeof(char*) * env->tetri_nbr + 1);
	if (!(env->tetri = (char**)malloc(sizeof(char*) * env->tetri_nbr + 1)))
		ft_error("Allocation Error : Insufficient memory");
	fd = 0;
	while (fd < env->tetri_nbr)
		env->tetri[fd++] = (char*)malloc(sizeof(char) * 22);
	env->tetri[env->tetri_nbr] = 0;
	copier_c_mal((env->tetri), av[1], env->tetri_nbr);
	return ;
}
