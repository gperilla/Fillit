/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:04:19 by tbauer            #+#    #+#             */
/*   Updated: 2017/11/30 12:51:55 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		size_map(int nb)
{
	int unefoissurdeux;
	int incr;
	int cpt;
	int ans;

	unefoissurdeux = 0;
	incr = 1;
	cpt = 0;
	ans = 2;
	while (nb--)
	{
		if (cpt == incr)
		{
			cpt = 0;
			ans++;
			if (unefoissurdeux++ == 1)
			{
				unefoissurdeux = 0;
				incr++;
			}
		}
		cpt++;
	}
	return (ans);
}
