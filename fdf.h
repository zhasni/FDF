/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 19:00:01 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/07 19:00:44 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>

# define SCREEN_Y	1440
# define SCREEN_X	2560

# define TILEW		8
# define TILEH		8
# define HEIGHT		4
# define T_ESC		65307
# define T_PLUS		65451
# define T_MOINS	65453
# define T_UP		65362
# define T_DOWN		65364
# define T_LEFT		65361
# define T_RIGHT	65363
# define T_FIVE		65461
# define T_TWO		65458
# define T_NINE		65465
# define T_SIX		65462
# define T_ONE		65457
# define T_THREE	65459
# define T_SEVEN	65463
# define T_FOUR		65460

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*str;
	int				**grid;
	int				bpp;
	int				sline;
	int				endian;
	int				len_y;
	int				len_x;
	int				move_x;
	int				move_y;
	int				tile_w;
	int				tile_h;
	int				height;
	int				view_y;
	int				view_x;
	int				color;
	int				ratio;
}					t_env;

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

int					ft_fdf(t_env *env);
int					ft_rgbtoi(int r, int g, int b);
void				ft_zoom(int keycode, t_env *env);
void				ft_rotate_x(int keycode, t_env *env);
void				ft_rotate_y(int keycode, t_env *env);
void				ft_draw_grid(t_env *env);
void				ft_put_pixel_image(t_env *env, int x, int y);

#endif
