/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:48:41 by gperilla          #+#    #+#             */
/*   Updated: 2017/12/05 15:39:42 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		ft_error("usage: ./fillit tetriminos_file");
	if (!ctoi_l_error(argv))
		ft_error("error");
	faites_place(&env, argv);
	if (!c_pas_zelda(env.tetri))
		ft_error("error");
	ds_to_alpha(&env);
	resolve(&env);
	show_result(env.map);
	return (0);
}
