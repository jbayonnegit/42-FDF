/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:24:51 by jbayonne          #+#    #+#             */
/*   Updated: 2024/12/14 13:13:15 by jbayonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"
# include "mlx.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# define HEIGHT 1080
# define WIDTH	1920

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288419716939937510582
# endif

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_center
{
	int	c_x;
	int	c_y;
	int	c_z;
}				t_map_ct;

typedef struct s_data
{
	void	*img;
	void	*ptr;
	void	*win;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	color;

}				t_rgb;

typedef struct s_context
{
	char		*file;
	int			**map;
	int			**map_t;
	char		**color_tab;
	int			is_color;
	int			size;
	int			row;	
	int			col;
	int			fd;
	int			zoom;
	int			z_min;
	int			z_max;
	int			delta_z;
	t_data		*mlx;
	t_coord		*proj;
	t_map_ct	*center;
	t_rgb		*rgb;
}				t_ctx;

t_ctx			*ctx_init(char *file);
int				ctx_init_bis(t_ctx *ctx);
int				check_ctx(t_ctx *ctx);

int				**map_init(int size);
int				**map_t_init(int size);
void			map_color_init(t_ctx *ctx);
void			map_transformed(t_ctx *ctx);
int				map_fill(t_ctx *ctx);

int				line_len(char *str);
int				line_size(char	*file);
int				ft_count_line(char *file);

int				str_color_detect(char *s);
char			*hex_extract(char *s);
char			*str_tolower(char *s);
void			find_coma(t_ctx *ctx);
void			no_color(t_ctx *ctx);
void			fill_color(t_ctx *ctx);
ssize_t			end_of_line(char **arr, int x, t_ctx *ctx, char *s);
char			**ft_freesplit(char **arr);
int				ft_mapfree_fill(int **map);
int				ft_mapfree_init(int **map, int i);
void			ft_free_gnl(int fd, char *s);
void			ctx_free(t_ctx	*ctx);

int				my_mlx_pixel_put(t_data *data, int x, int y,
					unsigned int color);
void			draw_image(t_ctx *ctx);
void			draw_line_up(t_ctx *ctx);
void			draw_line_down(t_ctx *ctx);

void			projection_iso(t_ctx *ctx, int n);
void			middle(t_ctx *ctx);
void			scale_up(t_ctx *ctx);
void			scale_down(t_ctx *ctx);
void			plat(t_ctx *ctx);
void			translate_up(t_ctx *ctx);
void			translate_right(t_ctx *ctx);
void			translate_down(t_ctx *ctx);
void			translate_left(t_ctx *ctx);
void			turn_right(t_ctx *ctx);
void			strech_up(t_ctx *ctx);
void			strech_down(t_ctx *ctx);
void			find_center(t_ctx *ctx);
void			find_center_2d(t_ctx *ctx);
void			center_to_zero(t_ctx *ctx);

void			ft_render(t_ctx *ctx);
int				close_win(t_ctx *ctx);
int				handle_input_mouse(int keysym, int x, int y, t_ctx *ctx);
int				handle_input(int keysym, t_ctx *ctx);
int				handle_color(int keysym, t_ctx *ctx);
void			reload(t_ctx *ctx);

unsigned int	ft_atoi_base(char *str, char *base, t_ctx *ctx, int x);
unsigned int	gradient(t_ctx *ctx, int n);

void			find_coma_(t_ctx *ctx, char *s);

#endif
