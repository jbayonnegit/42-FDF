/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:38:42 by jbayonne          #+#    #+#             */
/*   Updated: 2025/01/04 15:47:46 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_empty(char *str)
{
	int		fd;
	int		i;
	char	buffer[1];

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	i = read(fd, buffer, 1);
	if (i <= 0)
		return (1);
	return (0);
}

int	check(char *str)
{
	int		i;
	int		j;
	char	*ext;

	i = 0;
	j = 0;
	ext = ".fdf";
	while (str[i])
		i++;
	i -= 4;
	while (str[i + j])
	{
		if (str[i + j] != ext[j])
			return (-1);
		j++;
	}
	if (is_empty(str))
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ctx	*ctx;

	if (argc != 2)
		return (-1);
	if (check(argv[1]) == -1)
		return (-1);
	ctx = ctx_init(argv[1]);
	if (check_ctx(ctx) == -1)
		return (-1);
	ctx_init_bis(ctx);
	if (!ctx->rgb)
		return (-1);
	ft_render(ctx);
	return (0);
}
