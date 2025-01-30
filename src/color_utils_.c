/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <jbayonne@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 13:16:55 by jbayonne          #+#    #+#             */
/*   Updated: 2025-01-08 13:16:55 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ssize_t	end_of_line(char **arr, int x, t_ctx *ctx, char *s)
{
	s = ft_strdup(arr[x]);
	if (!str_color_detect(arr[x]))
		return (ft_freesplit(arr),
			ft_atoi_base(s, "0123456789abcdef", ctx, x));
	return (ft_freesplit(arr), ft_atoi_base(s, "0123456789abcdef", ctx, x));
}

void	find_coma_(t_ctx *ctx, char *s)
{
	ctx->is_color = -1;
	free(s);
}
