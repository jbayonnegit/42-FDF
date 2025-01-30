/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <jbayonne@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-16 12:42:08 by jbayonne          #+#    #+#             */
/*   Updated: 2024-12-16 12:42:08 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_mlx(t_ctx *ctx)
{
	t_data	*mlx;

	mlx = malloc(sizeof(t_data));
	if (!mlx)
		return ;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
		free(mlx);
		ctx_free(ctx);
		return ;
	}
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "FDF - Jbayonne");
	if (!mlx->win)
	{
		free(mlx->ptr);
		free(mlx);
		ctx_free(ctx);
		return ;
	}
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	ctx->mlx = mlx;
}

t_ctx	*ctx_init(char *file)
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		return (NULL);
	ctx->proj = malloc(sizeof(t_coord));
	if (!ctx->proj)
		return (free(ctx), NULL);
	ctx->proj->x = 0;
	ctx->proj->y = 0;
	ctx->zoom = 50;
	ctx->file = file;
	ctx->row = ft_count_line(ctx->file);
	ctx->col = line_size(ctx->file);
	ctx->size = ctx->row * ctx->col;
	ctx->map = map_init(ctx->size);
	if (!ctx->map)
		return (NULL);
	if (map_fill(ctx) == -1)
		return (NULL);
	ctx->map_t = map_t_init(ctx->size);
	if (!ctx->map_t)
		return (NULL);
	map_transformed(ctx);
	return (set_mlx(ctx), ctx);
}

int	ctx_init_bis(t_ctx *ctx)
{
	ctx->rgb = malloc(sizeof(t_rgb));
	if (!ctx->rgb)
	{
		free(ctx->mlx->ptr);
		free(ctx->mlx);
		ctx_free(ctx);
		return (-1);
	}
	ctx->rgb->r = 0xFF;
	ctx->rgb->g = 0xFF;
	ctx->rgb->b = 0xFF;
	ctx->rgb->color = 0x00;
	return (0);
}

int	check_ctx(t_ctx *ctx)
{
	if (!ctx)
		return (-1);
	if (!ctx->map)
	{
		free(ctx->proj);
		free(ctx);
		ctx = NULL;
		return (-1);
	}
	if (!ctx->map_t)
	{
		ft_mapfree_fill(ctx->map);
		free(ctx->proj);
		free(ctx);
		return (-1);
	}
	if (!ctx->mlx)
	{
		ctx_free(ctx);
		return (-1);
	}
	return (0);
}
