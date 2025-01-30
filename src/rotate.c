/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <jbayonne@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-04 15:28:56 by jbayonne          #+#    #+#             */
/*   Updated: 2025-01-04 15:28:56 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void	turn_right(t_ctx *ctx)
{
	int	n;
	int	tmp;

	n = 0;
	find_center(ctx);
	if (!ctx->center)
		return ;
	while (n < ctx->size)
	{
		tmp = ctx->map[n][0];
		ctx->map[n][0] = ctx->center->c_x + (tmp - ctx->center->c_x)
			* cos(M_PI / 2) - (ctx->map[n][1] - ctx->center->c_y)
			* sin(M_PI / 2);
		ctx->map[n][1] = ctx->center->c_y + (tmp - ctx->center->c_x)
			* sin(M_PI / 2) + (ctx->map[n][1] - ctx->center->c_y)
			* sin(M_PI / 2);
		n++;
	}
	free(ctx->center);
	map_transformed(ctx);
	middle(ctx);
	reload(ctx);
	draw_image(ctx);
}
