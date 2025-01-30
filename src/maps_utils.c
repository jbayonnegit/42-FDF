/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:36:01 by jbayonne          #+#    #+#             */
/*   Updated: 2024/12/11 18:28:56 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_len(char *str)
{
	int	c;
	int	j;
	int	k;

	c = 0;
	j = 0;
	k = 1;
	while (str[j])
	{
		while (str[j] && str[j] != ' ')
		{
			if (k == 1)
			{
				k = 0;
				c++;
			}
			j++;
		}
		while (str[j] && str[j] == ' ')
		{
			k = 1;
			j++;
		}
	}
	return (c);
}

int	line_size(char *file)
{
	int		fd;
	char	*s;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	s = get_next_line(fd);
	len = line_len(s);
	free(s);
	s = NULL;
	ft_free_gnl(fd, s);
	close(fd);
	return (len);
}

int	ft_count_line(char *file)
{
	int		fd;
	int		i;
	char	*s;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	s = get_next_line(fd);
	i++;
	free(s);
	while (s)
	{
		s = get_next_line(fd);
		if (s)
			i++;
		free(s);
	}
	close(fd);
	return (i);
}
