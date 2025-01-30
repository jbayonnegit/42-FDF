/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:42:43 by jbayonne          #+#    #+#             */
/*   Updated: 2024/12/11 20:14:48 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	**map_t_init(int size)
{
	int	**map_t;
	int	i;

	i = 0;
	map_t = malloc(sizeof(int *) * (size + 1));
	if (!map_t)
		return (0);
	while (i < size)
	{
		map_t[i] = malloc(sizeof(int) * 3);
		if (!map_t[i])
		{
			ft_mapfree_init(map_t, i);
			return (0);
		}
		map_t[i][2] = 0;
		i++;
	}
	map_t[size] = 0;
	return (map_t);
}

int	**map_init(int size)
{
	int	**map;
	int	i;

	i = 0;
	map = malloc(sizeof(int *) * (size + 1));
	if (!map)
		return (0);
	while (i < size)
	{
		map[i] = malloc(sizeof(int) * 5);
		if (!map[i])
		{
			ft_mapfree_init(map, i);
			return (0);
		}
		map[i][4] = 0;
		i++;
	}
	map[size] = 0;
	return (map);
}
