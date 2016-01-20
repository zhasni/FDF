/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:34:49 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/07 21:23:34 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_writegrid(int **grid, int fd, t_env *env)
{
	char	**tmp;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		j = 0;
		while (tmp[j])
		{
			grid[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		if (j > env->len_x)
			env->len_x = j;
		free(line);
		free(tmp);
		i++;
	}
	return (grid);
}

int		ft_tab_len(int fd, int *len, char *av)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	line = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		while (line[j])
			j++;
		if (*len < j)
			*len = j;
		i++;
		free(line);
	}
	if (close(fd) == -1)
		return (-1);
	return (i);
}

int		**ft_mallogrid(int **grid, int i, int j)
{
	int		k;
	int		l;

	k = i;
	if (!(grid = (int **)malloc(sizeof(int *) * i)))
		return (NULL);
	i = 0;
	while (i < k)
	{
		if (!(grid[i] = (int *)malloc(sizeof(int) * j)))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < k)
	{
		l = 0;
		while (l < j)
		{
			grid[i][l] = 0;
			l++;
		}
		i++;
	}
	return (grid);
}

void	ft_init_env(t_env *env)
{
	env->grid = NULL;
	env->tile_w = TILEW;
	env->tile_h = TILEH;
	env->height = HEIGHT;
	env->view_x = 1;
	env->view_y = 2;
	env->ratio = 1000;
}

int		main(int ac, char **av, char **environ)
{
	t_env	env;
	int		fd;
	int		j;

	j = 0;
	fd = 0;
	if (!environ[0])
		return (-1);
	ft_init_env(&env);
	if (ac == 2)
	{
		env.len_y = ft_tab_len(fd, &j, av[1]);
		if (env.len_y == 0 && j == 0)
			return (-1);
		env.grid = ft_mallogrid(env.grid, env.len_y, j);
		if (!env.grid)
			return (-1);
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (-1);
		env.grid = ft_writegrid(env.grid, fd, &env);
		if (close(fd) == -1)
			return (-1);
		ft_fdf(&env);
	}
	return (0);
}
