/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <jbayonne@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 14:05:41 by jbayonne          #+#    #+#             */
/*   Updated: 2024-12-17 14:05:41 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adjust_y(t_ctx *ctx, int deltaY, int tmp)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		if (tmp < HEIGHT / 2)
			ctx->map_t[n][1] = ctx->map_t[n][1] + deltaY;
		if (tmp > HEIGHT / 2)
			ctx->map_t[n][1] = ctx->map_t[n][1] - deltaY;
		n++;
	}
}

void	adjust_x(t_ctx *ctx, int deltaX, int tmp)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		if (tmp < WIDTH / 2)
			ctx->map_t[n][0] = ctx->map_t[n][0] + deltaX;
		if (tmp > WIDTH / 2)
			ctx->map_t[n][0] = ctx->map_t[n][0] - deltaX;
		n++;
	}
}

void	center_x(t_ctx *ctx)
{
	int	k;
	int	tmp;

	tmp = ctx->center->c_x;
	k = 0;
	if (ctx->center->c_x < WIDTH / 2)
	{
		while (ctx->center->c_x <= WIDTH / 2)
		{
			ctx->center->c_x++;
			k++;
		}
	}
	else
	{
		while (ctx->center->c_x >= WIDTH / 4)
		{
			ctx->center->c_x--;
			k++;
		}
	}
	adjust_x(ctx, k, tmp);
}

void	center_y(t_ctx *ctx)
{
	int	k;
	int	tmp;

	tmp = ctx->center->c_y;
	k = 0;
	if (ctx->center->c_y < HEIGHT / 2)
	{
		while (ctx->center->c_y <= HEIGHT / 2)
		{
			ctx->center->c_y++;
			k++;
		}
	}
	else
	{
		while (ctx->center->c_y >= HEIGHT / 2)
		{
			ctx->center->c_y--;
			k++;
		}
	}
	adjust_y(ctx, k, tmp);
}

void	middle(t_ctx *ctx)
{
	find_center_2d(ctx);
	center_x(ctx);
	center_y(ctx);
	free(ctx->center);
	reload(ctx);
	draw_image(ctx);
}
