/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:00:40 by jbayonne          #+#    #+#             */
/*   Updated: 2024/12/16 11:44:40 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_ctx *ctx)
{	
	ft_mapfree_fill(ctx->map_t);
	ft_mapfree_fill(ctx->map);
	mlx_destroy_image(ctx->mlx->ptr, ctx->mlx->img);
	mlx_destroy_window(ctx->mlx->ptr, ctx->mlx->win);
	mlx_destroy_display(ctx->mlx->ptr);
	free(ctx->mlx->ptr);
	free(ctx->mlx);
	free(ctx->rgb);
	free(ctx->proj);
	free(ctx);
	exit(0);
	return (0);
}

void	draw_image(t_ctx *ctx)
{
	draw_line_down(ctx);
	draw_line_up(ctx);
	mlx_put_image_to_window(ctx->mlx->ptr, ctx->mlx->win, ctx->mlx->img, 0, 0);
}

void	reload(t_ctx *ctx)
{
	mlx_destroy_image(ctx->mlx->ptr, ctx->mlx->img);
	ctx->mlx->img = mlx_new_image(ctx->mlx->ptr, WIDTH, HEIGHT);
}

void	ft_render(t_ctx *ctx)
{
	draw_image(ctx);
	mlx_hook(ctx->mlx->win, ButtonPress, ButtonPressMask,
		handle_input_mouse, (t_ctx *)ctx);
	mlx_hook(ctx->mlx->win, KeyPress, KeyPressMask, handle_input, (t_ctx *)ctx);
	mlx_hook(ctx->mlx->win, DestroyNotify, StructureNotifyMask, close_win, ctx);
	mlx_loop(ctx->mlx->ptr);
}
