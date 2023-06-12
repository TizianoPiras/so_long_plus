/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:32:41 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/12 02:22:40 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shootings(t_vars *vars)
{
	
	if (vars->loop_on == NO && vars->collectable == 0)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, 554, 288,
		 0x00FF0000, "GOOD JOB, AND REMEMBER: DON'T PANIC!");
		if (vars->lives == 4)
			mlx_string_put(vars->mlx, vars->win, 554, 388,
		 0x00FF0000, "YOU ARE THE BEST!");
		return (1);
	}
	else
	{
		if (vars->proiettile.enemy_loop < 500)
		{
			vars->proiettile.enemy_loop++;
			return (0);
		}
		vars->proiettile.enemy_loop = 0;
		if (vars->lives > 0)
		{
			X_move(vars);
			V_move(vars);
			A_move(vars);
			S_move(vars);
		}
		if (vars->lives == 0)
		{
			animation(vars);
			if (vars->flag == 1)
			{
				mlx_clear_window(vars->mlx, vars->win);
				mlx_string_put(vars->mlx, vars->win, 554, 288,
				 0x00FF0000, "GOOD JOB, AND REMEMBER: DON'T PANIC!");
			}
		}
		if (vars->collectable == 0)
			door_animation(vars);
		else
		{
			mlx_clear_window(vars->mlx, vars->win);
			draw_map(vars);
		}
	}
	return (0);
}

int		X_move(t_vars *vars)
{
	if (vars->proiettile.X_x != 0)
	{
		vars->proiettile.X_x--;
		if (vars->map[vars->proiettile.X_y][vars->proiettile.X_x] == '0')
			vars->map[vars->proiettile.X_y][vars->proiettile.X_x] = 'X';
		if (vars->map[vars->proiettile.X_y][vars->proiettile.X_x] == '1')
		    vars->map[vars->proiettile.X_y][ft_strlen(vars->map[0]) - 2] = 'X';
		if (vars->map[vars->proiettile.X_y][vars->proiettile.X_x + 1] == 'P')
			vars->map[vars->proiettile.X_y][vars->proiettile.X_x + 1] = 'P';
		else
			vars->map[vars->proiettile.X_y][vars->proiettile.X_x + 1] = '0';
		if (vars->map[vars->proiettile.X_y][vars->proiettile.X_x] == 'P')
		{
			vars->lives--;
			vars->map[vars->proiettile.X_y][vars->proiettile.X_x] = 'P';
		}
	}
	return (0);
}

int		V_move(t_vars *vars)
{
	if (vars->proiettile.V_x != 0)
	{
		vars->proiettile.V_x--;
		if (vars->map[vars->proiettile.V_y][vars->proiettile.V_x] == '0')
			vars->map[vars->proiettile.V_y][vars->proiettile.V_x] = 'V';
		if (vars->map[vars->proiettile.V_y][vars->proiettile.V_x] == '1')
		    vars->map[vars->proiettile.V_y][ft_strlen(vars->map[0]) - 2] = 'V';
		if (vars->map[vars->proiettile.V_y][vars->proiettile.V_x + 1] == 'P')
			vars->map[vars->proiettile.V_y][vars->proiettile.V_x + 1] = 'P';
		else
			vars->map[vars->proiettile.V_y][vars->proiettile.V_x + 1] = '0';
		if (vars->map[vars->proiettile.V_y][vars->proiettile.V_x] == 'P')
		{
			vars->lives--;
			vars->map[vars->proiettile.V_y][vars->proiettile.V_x] = 'P';
		}
	}
	return (0);
}

int		A_move(t_vars *vars)
{
	if (vars->proiettile.A_x != 0)
	{
		vars->proiettile.A_x--;
		if (vars->map[vars->proiettile.A_y][vars->proiettile.A_x] == '0')
			vars->map[vars->proiettile.A_y][vars->proiettile.A_x] = 'A';
		if (vars->map[vars->proiettile.A_y][vars->proiettile.A_x] == '1')
		    vars->map[vars->proiettile.A_y][ft_strlen(vars->map[0]) - 2] = 'A';
		if (vars->map[vars->proiettile.A_y][vars->proiettile.A_x + 1] == 'P')
			vars->map[vars->proiettile.A_y][vars->proiettile.A_x + 1] = 'P';
		else
			vars->map[vars->proiettile.A_y][vars->proiettile.A_x + 1] = '0';
		if (vars->map[vars->proiettile.A_y][vars->proiettile.A_x] == 'P')
		{
			vars->lives--;
			vars->map[vars->proiettile.A_y][vars->proiettile.A_x] = 'P';
		}
	}
	return (0);
}

int		S_move(t_vars *vars)
{
	if (vars->proiettile.S_x != 0)
	{
		vars->proiettile.S_x--;
		if (vars->map[vars->proiettile.S_y][vars->proiettile.S_x] == '0')
			vars->map[vars->proiettile.S_y][vars->proiettile.S_x] = 'S';
		if (vars->map[vars->proiettile.S_y][vars->proiettile.S_x] == '1')
		    vars->map[vars->proiettile.S_y][ft_strlen(vars->map[0]) - 2] = 'S';
		if (vars->map[vars->proiettile.S_y][vars->proiettile.S_x + 1] == 'P')
			vars->map[vars->proiettile.S_y][vars->proiettile.S_x + 1] = 'P';
		else
			vars->map[vars->proiettile.S_y][vars->proiettile.S_x + 1] = '0';
		if (vars->map[vars->proiettile.S_y][vars->proiettile.S_x] == 'P')
		{
			vars->lives--;
			vars->map[vars->proiettile.S_y][vars->proiettile.S_x] = 'P';
		}
	}
	return (0);
}