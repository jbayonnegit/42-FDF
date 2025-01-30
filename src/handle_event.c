/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <jbayonne@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-16 16:20:57 by jbayonne          #+#    #+#             */
/*   Updated: 2025/01/04 15:49:39 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	handle_input_mouse(int keysym, int x, int y, t_ctx *ctx)
{
	(void)x;
	(void)y;
	if (keysym == 4)
		scale_up(ctx);
	if (keysym == 5)
		scale_down(ctx);
	return (keysym);
}

int	handle_color(int keysym, t_ctx *ctx)
{
	if (keysym == 0x0072)
		ctx->rgb->r += 5;
	if (keysym == 0x0067)
		ctx->rgb->g += 5;
	if (keysym == 0x0062)
		ctx->rgb->b += 5;
	reload(ctx);
	draw_image(ctx);
	return (keysym);
}

int	handle_input(int keysym, t_ctx *ctx)
{
	if (keysym == 0x0077)
		translate_up(ctx);
	if (keysym == 0x0064)
		translate_right(ctx);
	if (keysym == 0x0061)
		translate_left(ctx);
	if (keysym == 0x0073)
		translate_down(ctx);
	if (keysym == 0xff53)
		turn_right(ctx);
	if (keysym == 0x0065)
		middle(ctx);
	if (keysym == 0xff52)
		strech_up(ctx);
	if (keysym == 0xff54)
		strech_down(ctx);
	if (keysym == 0xff1b)
		close_win(ctx);
	if (keysym == 0x0020)
		plat(ctx);
	else
		handle_color(keysym, ctx);
	return (keysym);
}
