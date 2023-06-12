/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_UI.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:34:44 by ertiz             #+#    #+#             */
/*   Updated: 2023/06/11 16:35:14 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_shields(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'L')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
		if (vars->lives == 4)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->shield.shield_03, x * 64, y * 64);
		if (vars->lives == 3)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->shield.shield_02, x * 64, y * 64);
		if (vars->lives == 2)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->shield.shield_01, x * 64, y * 64);
		if (vars->lives == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->shield.shield_00, x * 64, y * 64);
	}
}

void	display_moves(t_vars *vars)
{
	char	*s_moves;
	char	*c_left;
	char	*shields;

	s_moves = ft_itoa(vars->moves);
	c_left = ft_itoa(vars->collectable);
	shields = ft_itoa(vars->lives);
	mlx_string_put(vars->mlx, vars->win, 500, vars->height -32,
		0x0000FF00, "MOVES: ");
	mlx_string_put(vars->mlx, vars->win, 554, vars->height -32,
		0x0000FF00, s_moves);
	mlx_string_put(vars->mlx, vars->win, 604, vars->height -32,
		0x0000FF00, "COLLECTABLE LEFT: ");
	mlx_string_put(vars->mlx, vars->win, 734, vars->height -32,
		0x0000FF00, c_left);
	mlx_string_put(vars->mlx, vars->win, 70, 32,
		0x0000FFFF, "SHIELDS LEFT: ");
	mlx_string_put(vars->mlx, vars->win, 180 , 32,
		0x0000FFFF, shields);
	free(s_moves);
	free(c_left);
	free(shields);
}
