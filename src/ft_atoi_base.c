/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 23:45:23 by jbayonne          #+#    #+#             */
/*   Updated: 2024/07/12 12:01:33 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fdf.h>
#include <stdio.h>

int	is_valid(char *b)
{
	size_t	i;
	int		k;

	k = 0;
	i = 0;
	if (b[0] == '\0')
		return (-1);
	if (ft_strlen(b) == 1)
		return (-1);
	while (b[i] != '\0')
	{
		if ((b[i] >= 9 && b[i] <= 13) || (b[i] == 32)
			|| (b[i] == '-') || (b[i] == '+'))
			return (-1);
		k = i + 1;
		while (b[k])
		{
			if (b[i] == b[k])
				return (-1);
		k++;
		}
	i++;
	}
	return (0);
}

int	ft_index(char *base, char c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(base))
	{
		if (c == base[i])
			return (i);
	i++;
	}
	return (-1);
}

unsigned int	ft_atoi_base(char *str, char *base, t_ctx *ctx, int x)
{
	unsigned int	i;
	int				b;

	b = 0;
	i = 0;
	if (is_valid(base) == -1)
		return (0);
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		b = (b * ft_strlen(base)) + ft_index(base, str[i]);
		i++;
	}
	if (x == ctx->col - 1)
		free(str);
	return (b);
}
