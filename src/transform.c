/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:52:26 by jbayonne          #+#    #+#             */
/*   Updated: 2025/01/04 15:46:45 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_up(t_ctx *ctx)
{
	ctx->zoom += 2;
	map_transformed(ctx);
	reload(ctx);
	draw_image(ctx);
}

void	scale_down(t_ctx *ctx)
{
	ctx->zoom -= 2;
	if (ctx->zoom < 0)
		ctx->zoom = 0;
	map_transformed(ctx);
	reload(ctx);
	draw_image(ctx);
}

void	strech_up(t_ctx *ctx)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		if (ctx->map[n][2] + 1 == 0)
			ctx->map[n][2] += 2;
		else if (ctx->map[n][2] != 0)
			ctx->map[n][2] += 1;
		n++;
	}
	map_transformed(ctx);
	middle(ctx);
	reload(ctx);
	draw_image(ctx);
}

void	strech_down(t_ctx *ctx)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		if (ctx->map[n][2] - 1 == 0)
			ctx->map[n][2] -= 2;
		else if (ctx->map[n][2] != 0)
			ctx->map[n][2] -= 1;
		n++;
	}
	map_transformed(ctx);
	middle(ctx);
	reload(ctx);
	draw_image(ctx);
}

void	projection_iso(t_ctx *ctx, int n)
{
	int	tmp;

	tmp = ctx->map[n][0];
	ctx->proj->x = (tmp - ctx->map[n][1]) * cos(M_PI / 6) * ctx->zoom;
	ctx->proj->y = (tmp + ctx->map[n][1]) * sin(M_PI / 6)
		* ctx->zoom - ctx->map[n][2] * ctx->zoom;
}
