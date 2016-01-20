/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 18:25:45 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/05 20:06:46 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int keycode, t_env *env)
{
	if (keycode == T_NINE)
		env->height += 1;
	else if (keycode == T_SIX)
		env->height -= 1;
	else if (keycode == T_MOINS)
	{
		env->tile_w -= 1;
		env->tile_h -= 1;
	}
	else if (keycode == T_PLUS)
	{
		env->tile_w += 1;
		env->tile_h += 1;
	}
}

void	ft_rotate_x(int keycode, t_env *env)
{
	if (keycode == T_ONE)
	{
		if (env->view_x > 10 || env->view_x < -20)
			env->view_x += 10000;
		if (env->view_x > 20000)
			env->view_x = -10;
		else
			env->view_x += 1;
	}
	else if (keycode == T_THREE)
	{
		if (env->view_x < -10 || env->view_x > 20)
			env->view_x -= 10000;
		if (env->view_x < -20000)
			env->view_x = 10;
		env->view_x -= 1;
	}
}

void	ft_rotate_y(int keycode, t_env *env)
{
	if (keycode == T_TWO)
	{
		if (env->view_y > 10 || env->view_y < -20)
			env->view_y += 10000;
		if (env->view_y > 20000)
			env->view_y = -10;
		else
			env->view_y += 1;
	}
	else if (keycode == T_FIVE)
	{
		if (env->view_y < -10 || env->view_y > 20)
			env->view_y -= 10000;
		if (env->view_y < -20000)
			env->view_y = 10;
		else
			env->view_y -= 1;
	}
}
