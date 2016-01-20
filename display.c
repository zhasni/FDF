/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:11:18 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/07 18:06:15 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		ft_abs(float in)
{
	if (in < 0)
		in *= -1;
	return (in);
}

void		ft_put_line(t_env *env, t_point a, t_point b)
{
	t_point		c;
	float		slope;
	float		i;

	if (a.x >= b.x)
	{
		c = a;
		a = b;
		b = c;
	}
	slope = (b.x - a.x != 0) ? (float)((float)(b.y - a.y) /
			(float)(b.x - a.x)) : (float)(b.y - a.y);
	i = 0;
	while (a.x <= b.x)
	{
		i += ft_abs(slope);
		ft_put_pixel_image(env, a.x, a.y);
		while (i > 0 && a.y != b.y)
		{
			ft_put_pixel_image(env, a.x, a.y);
			a.y = (slope < 0) ? a.y - 1 : a.y + 1;
			i--;
		}
		a.x++;
	}
}

t_point		*ft_init_point(t_env *env, int x, int y, int z)
{
	t_point		*out;

	if (!(out = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	if (env->view_x == 0)
		out->x = (y - x) * env->tile_w + (SCREEN_X / 2) + env->move_x;
	else
		out->x = ((y - x) * env->tile_w) / env->view_x + (SCREEN_X / 2) +
			env->move_x;
	if (env->view_y == 0)
	{
		out->y = (y + x) * env->tile_h - z * env->height + (SCREEN_Y / 32)
			+ env->move_y;
	}
	else
		out->y = (y + x) * env->tile_h / env->view_y - z * env->height +
			(SCREEN_Y / 8)
			+ env->move_y;
	out->z = z;
	return (out);
}

void		ft_init_lines(t_env *env, int i, int j)
{
	t_point		*a;
	t_point		*b;
	t_point		*c;

	env->color = ft_rgbtoi(255, 255, 255);
	a = ft_init_point(env, i, j, env->grid[i][j]);
	if (i + 1 < env->len_y)
	{
		if ((env->grid[i][j] != env->grid[i + 1][j]) || (env->grid[i][j]
					!= 0 && env->grid[i + 1][j] == env->grid[i][j]))
			env->color = (env->height * env->ratio) + env->grid[i + 1][j];
		c = ft_init_point(env, i + 1, j, env->grid[i + 1][j]);
		ft_put_line(env, *a, *c);
	}
	env->color = ft_rgbtoi(255, 255, 255);
	if (j + 1 < env->len_x)
	{
		if ((env->grid[i][j] != env->grid[i][j + 1]) || (env->grid[i][j]
					!= 0 && env->grid[i][j + 1] == env->grid[i][j]))
			env->color = (env->height * env->ratio) + env->grid[i][j + 1];
		b = ft_init_point(env, i, j + 1, env->grid[i][j + 1]);
		ft_put_line(env, *a, *b);
	}
}

void		ft_draw_grid(t_env *env)
{
	int			i;
	int			j;

	i = 0;
	while (i < env->len_y)
	{
		j = 0;
		while (j < env->len_x)
		{
			ft_init_lines(env, i, j);
			j++;
		}
		i++;
	}
}
