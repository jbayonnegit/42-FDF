/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <jbayonne@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-05 14:14:18 by jbayonne          #+#    #+#             */
/*   Updated: 2025-01-05 14:14:18 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_to_zero(t_ctx *ctx)
{
	ctx->center = malloc(sizeof(t_map_ct));
	if (!ctx->center)
		return ;
	ctx->center->c_x = 0;
	ctx->center->c_y = 0;
	ctx->center->c_z = 0;
}

void	divide_center(t_ctx *ctx)
{
	ctx->center->c_x /= ctx->size;
	ctx->center->c_y /= ctx->size;
	ctx->center->c_z /= ctx->size;
}

void	find_center(t_ctx *ctx)
{
	int	n;

	center_to_zero(ctx);
	if (!ctx->center)
		return ;
	n = 0;
	while (n < ctx->size)
	{
		ctx->center->c_x = ctx->center->c_x + ctx->map[n][0];
		n++;
	}
	n = 0;
	while (n < ctx->size)
	{
		ctx->center->c_y = ctx->center->c_y + ctx->map[n][1];
		n++;
	}
	n = 0;
	while (n < ctx->size)
	{
		ctx->center->c_z = ctx->center->c_z + ctx->map[n][2];
		n++;
	}
	divide_center(ctx);
}

void	find_center_2d(t_ctx *ctx)
{
	int	n;

	center_to_zero(ctx);
	if (!ctx->center)
		return ;
	n = 0;
	while (n < ctx->size)
	{
		ctx->center->c_x = ctx->center->c_x + ctx->map_t[n][0];
		n++;
	}
	n = 0;
	while (n < ctx->size)
	{
		ctx->center->c_y = ctx->center->c_y + ctx->map_t[n][1];
		n++;
	}
	divide_center(ctx);
}
