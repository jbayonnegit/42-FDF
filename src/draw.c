/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:06:24 by jbayonne          #+#    #+#             */
/*   Updated: 2025/01/04 15:47:16 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Dans line_less_one et line_bigger_one on a notre parametre de decision p.
	on obtient p en derivant l'expression d1 - d2. 

Draw line a pour role de calculer le delta entre x1/x0 et y0/y1. 

En comparant delta(X) et delta(Y), on deduit la pente du vecteur.

Donc on sait que y = ax + b ou  x = delta(x)/delta(y)

Donc si delta(X) > delta(Y) la pente 'a' du vecteur est inferieur a 45 degre : 
a < 1, donc x augmente a chaque iteration. 

A l'inverse si delta(Y) > delta (X) y augemnte a chaque iteration.
 */

int	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (!(x > WIDTH || y > HEIGHT || x < 0 || y < 0))
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		return (0);
	}
	return (-1);
}

void	a_less_than_one(t_coord *p0, t_coord *delta, t_ctx *ctx, int n)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(delta->y) - abs(delta->x);
	while (i++ < abs(delta->x))
	{
		if (delta->x > 0)
			p0->x++;
		else
			p0->x--;
		if (p < 0)
			p = p + (2 * abs(delta->y));
		else
		{
			if (delta->y >= 0)
				p0->y++;
			else
				p0->y--;
			p = p + 2 * abs(delta->y) - 2 * abs(delta->x);
		}
		my_mlx_pixel_put(ctx->mlx, p0->x, p0->y, gradient(ctx, n));
	}
}

void	a_bigger_than_one(t_coord *p0, t_coord *delta, t_ctx *ctx, int n)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(delta->x) - abs(delta->y);
	while (i++ < abs(delta->y))
	{
		if (delta->y > 0)
			p0->y++;
		else
			p0->y--;
		if (p < 0)
			p = p + 2 * abs(delta->x);
		else
		{
			if (delta->x >= 0)
				p0->x++;
			else
				p0->x--;
			p = p + 2 * abs(delta->x) - 2 * abs(delta->y);
		}
		my_mlx_pixel_put(ctx->mlx, p0->x, p0->y, gradient(ctx, n));
	}
}

void	draw_line_down(t_ctx *ctx)
{
	t_coord	p0;
	t_coord	p1;
	int		n;
	t_coord	delta;

	n = 0;
	while (n + 1 < ctx->size)
	{
		p0.x = ctx->map_t[n][0];
		p0.y = ctx->map_t[n][1];
		p1.x = ctx->map_t[n + 1][0];
		p1.y = ctx->map_t[n + 1][1];
		delta.x = p1.x - p0.x;
		delta.y = p1.y - p0.y;
		if (abs(delta.x) > abs(delta.y))
			a_less_than_one(&p0, &delta, ctx, n);
		else
			a_bigger_than_one(&p0, &delta, ctx, n);
		n++;
		if ((n + 1) % ctx->col == 0)
			n ++;
	}
}

void	draw_line_up(t_ctx *ctx)
{
	t_coord	p0;
	t_coord	p1;
	int		n;
	t_coord	delta;

	n = 0;
	while (n + ctx->col < ctx->size)
	{
		p1.x = ctx->map_t[n][0];
		p1.y = ctx->map_t[n][1];
		p0.x = ctx->map_t[n + ctx->col][0];
		p0.y = ctx->map_t[n + ctx->col][1];
		delta.x = p1.x - p0.x;
		delta.y = p1.y - p0.y;
		if (abs(delta.x) > abs(delta.y))
			a_less_than_one(&p0, &delta, ctx, n);
		else
			a_bigger_than_one(&p0, &delta, ctx, n);
		n++;
	}
}
