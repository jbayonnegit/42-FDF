/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:35:59 by jbayonne          #+#    #+#             */
/*   Updated: 2024/12/04 14:41:43 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_gnl(int fd, char *s)
{
	while (s)
	{
		s = get_next_line(fd);
		free(s);
	}
}

int	ft_mapfree_init(int **map, int i)
{
	while (i != -1)
	{
		free(map[i]);
		i--;
	}
	free(map);
	map = 0;
	return (-1);
}

int	ft_mapfree_fill(int **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i])
		{
			if (map[i] != NULL)
			{
				free(map[i]);
				map[i] = NULL;
				i++;
			}
		}
		free(map);
	}
	map = 0;
	return (-1);
}

char	**ft_freesplit(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
		{
			if (arr[i] != NULL)
			{
				free(arr[i]);
				i++;
			}
		}
		free(arr);
		return (NULL);
	}
	else
		return (arr);
}

void	ctx_free(t_ctx	*ctx)
{
	ft_mapfree_fill(ctx->map);
	ft_mapfree_fill(ctx->map_t);
	free(ctx->proj);
	free(ctx);
	ctx = NULL;
}
