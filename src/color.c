/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <jbayonne@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-05 17:23:55 by jbayonne          #+#    #+#             */
/*   Updated: 2025-01-05 17:23:55 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ssize_t	get_color(t_ctx *ctx, int x)
{
	static char	**arr;
	char		*s;

	if (x == 0)
	{
		s = get_next_line(ctx->fd);
		arr = ft_split(s, ' ');
		free(s);
		if (!arr)
			return (-1);
	}
	if (!arr)
		return (-1);
	if (str_color_detect(arr[x]) && x != ctx->col - 1)
		return (ft_atoi_base(str_tolower(hex_extract(arr[x])),
				"0123456789abcdef", ctx, x));
	else if (!str_color_detect(arr[x]) && x != ctx->col - 1)
		return (-1);
	if (x == ctx->col - 1)
		return (end_of_line(arr, x, ctx, s));
	return (ft_atoi_base(arr[x], "0123456789abcdef", ctx, x));
}

void	fill_color(t_ctx *ctx)
{
	int	n;
	int	x;

	find_coma(ctx);
	n = 0;
	ctx->fd = open(ctx->file, O_RDONLY);
	if (!ctx->fd)
		ctx->is_color = -1;
	if (ctx->is_color > 0)
	{
		while (n < ctx->size)
		{
			x = 0;
			while (x < ctx->col)
			{
				ctx->map[n][3] = get_color(ctx, x);
				n++;
				x++;
			}
		}
	}
	else if (ctx->is_color < 0)
		no_color(ctx);
	close(ctx->fd);
}

unsigned int	color_shift(t_rgb *rgb)
{
	unsigned int	tmp;

	rgb->color = rgb->r;
	rgb->color <<= 16;
	tmp = rgb->g;
	tmp <<= 8;
	rgb->color = rgb->color | tmp;
	tmp = rgb->b;
	rgb->color = rgb->color | tmp;
	return (rgb->color);
}

unsigned int	gradient(t_ctx *ctx, int n)
{
	if (ctx->is_color < 0)
		ctx->rgb->color = color_shift(ctx->rgb);
	else
		ctx->rgb->color = ctx->map[n][3];
	return (ctx->rgb->color);
}
