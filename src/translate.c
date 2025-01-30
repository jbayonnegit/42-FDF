/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <jbayonne@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-04 14:13:44 by jbayonne          #+#    #+#             */
/*   Updated: 2025/01/04 16:02:06 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_right(t_ctx *ctx)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		ctx->map_t[n][0] += 5;
		n++;
	}
	reload(ctx);
	draw_image(ctx);
}

void	translate_left(t_ctx *ctx)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		ctx->map_t[n][0] -= 5;
		n++;
	}
	reload(ctx);
	draw_image(ctx);
}

void	translate_up(t_ctx *ctx)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		ctx->map_t[n][1] -= 5;
		n++;
	}
	reload(ctx);
	draw_image(ctx);
}

void	translate_down(t_ctx *ctx)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		ctx->map_t[n][1] += 5;
		n++;
	}
	reload(ctx);
	draw_image(ctx);
}

void	plat(t_ctx *ctx)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		if (ctx->map[n][2] + 1 == 0)
			ctx->map[n][2] -= 2;
		if (ctx->map[n][2] - 1 == 0)
			ctx->map[n][2] += 2;
		if (ctx->map[n][2] > 0)
			ctx->map[n][2] -= 1;
		else if (ctx->map[n][2] < 0)
			ctx->map[n][2] += 1;
		n++;
	}
	map_transformed(ctx);
	middle(ctx);
	reload(ctx);
	draw_image(ctx);
}
