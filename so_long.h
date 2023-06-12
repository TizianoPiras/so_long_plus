/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:04:44 by tpiras            #+#    #+#             */
/*   Updated: 2023/06/11 16:37:08 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#define YES	1
#define	NO	0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

//shield_live
typedef struct s_shields
{
	void	*shield_00;
	void	*shield_01;
	void	*shield_02;
	void	*shield_03;
}	t_shields;

//death animation
typedef struct death_animation
{
	int		d_stance;
	int		d_frame;
}	explosion;

//door animation
typedef struct door_animation
{
	int		door_stance;
	int		door_frame;
	int		door_loop;
	void	*door_img;
}	o_door;

//structure with enemies and crews
typedef struct enemy_movement
{
	int		X_x;
	int		X_y;
	int		Z_x;
	int		Z_y;
	int		V_x;
	int		V_y;
	int		A_x;
	int		A_y;
	int		S_x;
	int		S_y;
	int		enemy_loop;
	void	*enemy_img;
}	enemy;

//structure with all elements
typedef struct s_vars
{
	int			lives;
	void		*crew_1;
	void		*crew_2;
    void		*mlx;
    void		*win;
	int			width;
	int			height;
	char		*s;
	int			fd;
	char		*pd;
	int			i;
	int			moves;
	char		**map;
	int			map_x;
	int			map_y;
	void		*perimeter;
	void		*bg;
	int			collectable;
	int			lost_members;
	void		*exit;
	void		*player;
	int			player_loop;
	int			death_loop;
	int			player_x;
	int			player_y;
	int			flag;
	int			x;
	int			y;
	int			loop_on;
	int 		seen_flag;
	enemy		proiettile;
	explosion	death;
	o_door		door;
	t_shields	shield;
}	t_vars;

//map checker
int		ft_count(char *s1);
void	ft_putstr(char *str);
void	cleaner(t_vars *vars);
int		ft_control(t_vars *vars);
int		checking_edges(t_vars *vars);
int		checking_middles(t_vars *vars);
int		checking_stucture(t_vars *vars);
int		checking_elements(t_vars *vars);

//graphics of the map
t_vars	start(t_vars *vars, char *path);
int		get_sprite(t_vars *vars);
void	draw_map(t_vars *vars);
void	draw_1_0(t_vars *vars, int x, int y);
void	draw_p_x(t_vars *vars, int x, int y);
void	draw_e_c(t_vars *vars, int x, int y);
void	draw_shields(t_vars *vars, int x, int y);
void	display_moves(t_vars *vars);
void	print_moves(t_vars *vars);

//animation functions
int		animation(t_vars *vars);
void	change_image(t_vars *vars);
int		door_animation(t_vars *vars);
void	open_door(t_vars *vars);

//movements
int		move(int keycode, t_vars *vars);
int		move_w(t_vars *vars);
int		move_s(t_vars *vars);
int		move_d(t_vars *vars);
int		move_a(t_vars *vars);
int		shootings(t_vars *vars);
int		X_move(t_vars *vars);
int		Z_move(t_vars *vars);
int		V_move(t_vars *vars);
int		A_move(t_vars *vars);
int		S_move(t_vars *vars);

#endif