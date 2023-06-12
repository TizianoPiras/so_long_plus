/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:41:56 by tpiras            #+#    #+#             */
/*   Updated: 2023/05/19 23:09:25 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_vars *vars)
{
	if (vars->lives > 0 && vars->loop_on == YES)
	{
		if (keycode == 119 || keycode == 65362)
		{
			move_w(vars);
			vars->moves++;
		}
		if (keycode == 115 || keycode == 65364)
		{
			move_s(vars);
			vars->moves++;
		}
		if (keycode == 97 || keycode == 65361)
		{
			move_a(vars);
			vars->moves++;
		}
		if (keycode == 100 || keycode == 65363)
		{
			move_d(vars);
			vars->moves++;
		}
	}
	print_moves(vars);
	return (1);
}

int	move_w(t_vars *vars)
{
	vars->player_y -= 1;
	if (vars->map[vars->player_y][vars->player_x] == '1')
		vars->map[vars->i - 2][vars->player_x] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'X')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->lives--;
	}
	if (vars->map[vars->player_y][vars->player_x] == 'C')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->collectable -= 1;
	}
	if (vars->map[vars->player_y][vars->player_x] == '0')
		vars->map[vars->player_y][vars->player_x] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'E')
	{
		if(vars->collectable > 0)
			return (0);
		else
			vars->loop_on = NO;
	}
	vars->map[vars->player_y + 1][vars->player_x] = '0';
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}

int	move_s(t_vars *vars)
{
	vars->player_y += 1;
	if (vars->map[vars->player_y][vars->player_x] == '1')
		vars->map[1][vars->player_x] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'X')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->lives--;
	}
	if (vars->map[vars->player_y][vars->player_x] == 'C')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->collectable -= 1;
	}
	if (vars->map[vars->player_y][vars->player_x] == '0')
		vars->map[vars->player_y][vars->player_x] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'E')
	{
		if(vars->collectable > 0)
			return (0);
		else
			vars->loop_on = NO;
	}
	vars->map[vars->player_y - 1][vars->player_x] = '0';
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}

int	move_a(t_vars *vars)
{
	vars->player_x -= 1;
	if (vars->map[vars->player_y][vars->player_x] == '1')
		vars->map[vars->player_y][ft_strlen(vars->map[0]) - 2] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'X')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->lives--;
	}
	if (vars->map[vars->player_y][vars->player_x] == 'C')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->collectable -= 1;
	}
	if (vars->map[vars->player_y][vars->player_x] == '0')
		vars->map[vars->player_y][vars->player_x] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'E')
	{
		if(vars->collectable > 0)
			return (0);
		else
			vars->loop_on = NO;
	}
	vars->map[vars->player_y][vars->player_x + 1] = '0';
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}

int	move_d(t_vars *vars)
{
	vars->player_x += 1;
	if (vars->map[vars->player_y][vars->player_x] == '1')
		vars->map[vars->player_y][1] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'X')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->lives--;
	}
	if (vars->map[vars->player_y][vars->player_x] == 'C')
	{
		vars->map[vars->player_y][vars->player_x] = 'P';
		vars->collectable -= 1;
	}
	if (vars->map[vars->player_y][vars->player_x] == '0')
		vars->map[vars->player_y][vars->player_x] = 'P';
	if (vars->map[vars->player_y][vars->player_x] == 'E')
	{
		if(vars->collectable > 0)
			return (0);
		else
			vars->loop_on = NO;
	}
	vars->map[vars->player_y][vars->player_x - 1] = '0';
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}

void	print_moves(t_vars *vars)
{
	char	*moves;

	moves = ft_itoa(vars->moves);
	ft_putstr("MOVES:");
	ft_putstr(moves);
	ft_putstr("\n");
	free(moves);
}