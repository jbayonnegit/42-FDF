/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:56:36 by jbayonne          #+#    #+#             */
/*   Updated: 2025/01/04 15:45:49 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_str_to_int(int fd, t_coord index, int size, int **map)
{
	static char		**arr;
	char			*s;
	static int		tmp;

	tmp = 1 + tmp;
	if (tmp == 1)
		arr = NULL;
	if (index.x == 0)
	{
		arr = ft_freesplit(arr);
		s = get_next_line(fd);
		arr = ft_split(s, ' ');
		if (!arr)
			return (ft_mapfree_fill(map), 0);
		free(s);
		return (ft_atoi(arr[index.x]));
	}
	if (index.x + index.y == size - 2)
	{
		tmp = ft_atoi(arr[index.x]);
		ft_freesplit(arr);
		return (tmp);
	}
	return (ft_atoi(arr[index.x]));
}

int	map_fill(t_ctx *ctx)
{
	t_coord	index;
	int		fd;
	int		n;

	fd = open(ctx->file, O_RDONLY);
	if (fd < 0)
		return (-1);
	n = 0;
	index.y = 0;
	while (n < ctx->size)
	{
		index.x = -1;
		while (++index.x < ctx->col)
		{
			ctx->map[n][0] = index.x;
			ctx->map[n][1] = index.y;
			ctx->map[n][2] = ft_str_to_int
				(fd, index, ctx->col + ctx->row, ctx->map);
			n++;
		}
		index.y++;
	}
	fill_color(ctx);
	return (close(fd));
}

void	map_transformed(t_ctx *ctx)
{
	int		n;

	n = 0;
	while (n < ctx->size)
	{
		projection_iso(ctx, n);
		ctx->map_t[n][0] = ctx->proj->x;
		ctx->map_t[n][1] = ctx->proj->y;
		n++;
	}
}
