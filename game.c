/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:12:34 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/11 17:00:07 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_vars *vars)
{
	vars->flag = 0;
	vars->moves = 0;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->proiettile.X_x = 0;
	vars->proiettile.X_y = 0;
	vars->proiettile.Z_x = 0;
	vars->proiettile.Z_y = 0;
	vars->proiettile.V_x = 0;
	vars->proiettile.V_y = 0;
	vars->proiettile.A_x = 0;
	vars->proiettile.A_y = 0;
	vars->proiettile.S_x = 0;
	vars->proiettile.S_y = 0;
	vars->proiettile.enemy_loop = 0;
	vars->loop_on = YES;
	vars->lives = 4;
	vars->death.d_stance = 0;
	vars->death_loop = 0;
	vars->door.door_stance = 0;
	vars->door.door_loop = 0;
}

t_vars	start(t_vars *vars, char *path)
{
	size_t	r;

	r = 0;
	vars->mlx = mlx_init();
	init_vars(vars);
	vars->fd = open(path, O_RDONLY);
	vars->s = (char*) malloc (sizeof(char) * 1000);
	if (vars->fd < 0)
		exit(1);
	r = read(vars->fd, vars->s, 10000);
	if (r <= 0)
		exit(1);
    vars->map = ft_split(vars->s, '\n');
	vars->i = ft_count(vars->s);
    vars->height = vars->i * 64;
	vars->width = ft_strlen(vars->map[0]) * 64;
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "tpiras so_long");
    return (*vars);
}

int	get_sprite(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->bg = mlx_xpm_file_to_image(vars->mlx, "./assets/Tile_of_BG_stars_1.xpm" , &x, &y);
	vars->perimeter = mlx_xpm_file_to_image(vars->mlx, "./assets/Tile_of_BG_stars_1.xpm", &x, &y);
	vars->player = mlx_xpm_file_to_image(vars->mlx, "./assets/Player/Cuore_d'oro_FS.xpm", &x, &y);
	vars->proiettile.enemy_img = mlx_xpm_file_to_image(vars->mlx, "./assets/Enemy/projectile.xpm", &x, &y);
	vars->crew_1 = mlx_xpm_file_to_image(vars->mlx, "./assets/Collectables/Marvin_FS.xpm", &x, &y);
	vars->door.door_img = mlx_xpm_file_to_image(vars->mlx, "./assets/frame_0_door.xpm", &x, &y);
	vars->shield.shield_00 = mlx_xpm_file_to_image(vars->mlx, "./assets/shield_00.xpm", &x, &y);
	vars->shield.shield_01 = mlx_xpm_file_to_image(vars->mlx, "./assets/shield_01.xpm", &x, &y);
	vars->shield.shield_02 = mlx_xpm_file_to_image(vars->mlx, "./assets/shield_02.xpm", &x, &y);
	vars->shield.shield_03 = mlx_xpm_file_to_image(vars->mlx, "./assets/shield_03.xpm", &x, &y);
	if (!vars->bg || !vars->perimeter || !vars->player || !vars->proiettile.enemy_img || !vars->crew_1 
	|| !vars->shield.shield_03 || !vars->shield.shield_02 || !vars->shield.shield_01 || !vars->shield.shield_00)
		exit (1);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	cleaner(t_vars *vars)
{
	int	x;

	x = 0;
	while (x <= vars->i)
	{
		free(vars->map[x]);
		x++;
	}
	free(vars->map);
}
