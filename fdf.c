/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 12:20:53 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/07 18:00:40 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_pixel_image(t_env *env, int x, int y)
{
	int		i;

	i = ((env->bpp / 8) * x) + ((env->sline) * y);
	if (i >= 0 && i < SCREEN_Y * env->sline && i > y * env->sline && i <
			(y * env->sline) + ((env->bpp / 8) * SCREEN_X))
	{
		env->str[i] = env->color;
		env->str[i + 1] = (env->color) >> 8;
		env->str[i + 2] = (env->color) >> 16;
	}
}

void		key_hook_2nd(int keycode, t_env *env)
{
	if (keycode == T_RIGHT)
		env->move_x += 10;
	else if (keycode == T_LEFT)
		env->move_x -= 10;
	else if (keycode == T_DOWN)
		env->move_y += 10;
	else if (keycode == T_UP)
		env->move_y -= 10;
	else if (keycode == T_SEVEN)
		env->ratio += 1000;
	else if (keycode == T_FOUR)
		env->ratio -= 1000;
}

int			expose_hook(t_env *env)
{
	ft_bzero(env->str, SCREEN_Y * env->sline);
	ft_draw_grid(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int			key_hook(int keycode, t_env *env)
{
	if (keycode == T_ESC)
		exit(0);
	else if (keycode == T_ONE)
		ft_rotate_x(keycode, env);
	else if (keycode == T_THREE)
		ft_rotate_x(keycode, env);
	else if (keycode == T_TWO)
		ft_rotate_y(keycode, env);
	else if (keycode == T_FIVE)
		ft_rotate_y(keycode, env);
	else if (keycode == T_NINE)
		ft_zoom(T_NINE, env);
	else if (keycode == T_SIX)
		ft_zoom(keycode, env);
	else if (keycode == T_MOINS)
		ft_zoom(keycode, env);
	else if (keycode == T_PLUS)
		ft_zoom(keycode, env);
	else
		key_hook_2nd(keycode, env);
	expose_hook(env);
	return (0);
}

int			ft_fdf(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, SCREEN_X, SCREEN_Y, "42");
	if (!(env->img = mlx_new_image(env->mlx, SCREEN_X, SCREEN_Y)))
		return (-1);
	if (!(env->str = mlx_get_data_addr(env->img, &(env->bpp), &(env->sline),
					&(env->endian))))
		return (-1);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_hook(env->win, 2, 3, key_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
