/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:25:23 by ertiz             #+#    #+#             */
/*   Updated: 2023/06/11 16:25:38 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_matrix(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i] != NULL)
	{
		j = -1;
		while (vars->map[i][++j] != '\0')
		{
			printf("%c",vars->map[i][j]);
		}
		printf("\n");
	}
}