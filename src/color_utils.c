/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <jbayonne@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 18:47:13 by jbayonne          #+#    #+#             */
/*   Updated: 2025-01-07 18:47:13 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	str_color_detect(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'x')
			return (1);
		s++;
	}
	return (0);
}

char	*str_tolower(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_tolower(s[i]);
		i++;
	}
	return (s);
}

char	*hex_extract(char *s)
{
	while (*s != 'x')
		s++;
	s += 1;
	return (s);
}

void	find_coma(t_ctx *ctx)
{
	char	*str;
	int		i;

	i = 0;
	ctx->fd = open(ctx->file, O_RDONLY);
	if (!ctx->fd)
		ctx->is_color = -1;
	str = get_next_line(ctx->fd);
	while (str)
	{
		while (str && str[i])
		{
			if (str[i] == ',')
			{
				ctx->is_color = 1;
				free(str);
				return ;
			}
			i++;
		}
		free(str);
		str = get_next_line(ctx->fd);
		i = 0;
	}
	find_coma_(ctx, str);
}

void	no_color(t_ctx *ctx)
{
	int	n;

	n = 0;
	while (n < ctx->size)
	{
		ctx->map[n][3] = -1;
		n++;
	}
}
