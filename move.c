/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:53:23 by akhachat          #+#    #+#             */
/*   Updated: 2021/07/27 12:55:01 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	int i = 0,j;
	if (map.map[vars->plr.x - 1][vars->plr.y] != '1')
	{
		if (map.map[vars->plr.x - 1][vars->plr.y] == 'C')
		{
			map.map[vars->plr.x - 1][vars->plr.y] = '2';
			vars->count_coins++;
		}
		if (map.map[vars->plr.x - 1][vars->plr.y] == 'E')
		{
			if (vars->count_coins == count.coins_count)
				close_win(vars);
		}
		if (map.map[vars->plr.x - 1][vars->plr.y] == 'G')
		{
			while(i < map.length)
			{
				j = 0;
				while(j < map.height)
				{
					if (map.map[j][i] == '2')
					{
						map.map[j][i] = 'C';
					}
					++j;
				}
				++i;
			}
			vars->plr.x = vars->new_plr.x + 1;
			vars->plr.y = vars->new_plr.y;
			vars->steps = -1;
			vars->count_coins = 0;
		}
		vars->plr.x--;
		vars->steps++;
		printf("%d\n", vars->steps);
	}
}

void	move_down(t_vars *vars)
{
	int i = 0,j;
	if (map.map[vars->plr.x + 1][vars->plr.y] != '1')
	{
		if (map.map[vars->plr.x + 1][vars->plr.y] == 'C')
		{
			map.map[vars->plr.x + 1][vars->plr.y] = '2';
			vars->count_coins++;
		}
		if (map.map[vars->plr.x + 1][vars->plr.y] == 'E')
		{
			if (vars->count_coins == count.coins_count)
				close_win(vars);
		}
		if (map.map[vars->plr.x + 1][vars->plr.y] == 'G')
		{
			while(i < map.length)
			{
				j = 0;
				while(j < map.height)
				{
					if (map.map[j][i] == '2')
					{
						map.map[j][i] = 'C';
					}
					++j;
				}
				++i;
			}
			vars->plr.x = vars->new_plr.x - 1;
			vars->plr.y = vars->new_plr.y;
			vars->steps = -1;
			vars->count_coins = 0;
		}
		vars->plr.x++;
		vars->steps++;
		printf("%d\n", vars->steps);
	}
}

void	move_left(t_vars *vars)
{
	int j, i = 0;

	if (map.map[vars->plr.x][vars->plr.y - 1] != '1')
	{
		if (map.map[vars->plr.x][vars->plr.y - 1] == 'C')
		{
			map.map[vars->plr.x][vars->plr.y - 1] = '2';
			vars->count_coins++;
		}
		if (map.map[vars->plr.x][vars->plr.y - 1] == 'E')
		{
			if (vars->count_coins == count.coins_count)
				close_win(vars);
		}
		if (map.map[vars->plr.x][vars->plr.y - 1] == 'G')
		{
			while(i < map.length)
			{
				j = 0;
				while(j < map.height)
				{
					if (map.map[j][i] == '2')
					{
						map.map[j][i] = 'C';
					}
					++j;
				}
				++i;
			}
			vars->plr.x = vars->new_plr.x;
			vars->plr.y = vars->new_plr.y + 1;
			vars->steps = -1;
			vars->count_coins = 0;
		}
		vars->plr.y--;
		vars->steps++;
		printf("%d\n", vars->steps);
	}
}

void	move_right(t_vars *vars)
{
	int i = 0,j;
	if (map.map[vars->plr.x][vars->plr.y + 1] != '1')
	{
		if (map.map[vars->plr.x][vars->plr.y + 1] == 'C')
		{
			map.map[vars->plr.x][vars->plr.y + 1] = '2';
			vars->count_coins++;
		}
		if (map.map[vars->plr.x][vars->plr.y + 1] == 'E')
		{
			if (vars->count_coins == count.coins_count)
				close_win(vars);
		}
		if (map.map[vars->plr.x][vars->plr.y + 1] == 'G')
		{
			while(i < map.length)
			{
				j = 0;
				while(j < map.height)
				{
					if (map.map[j][i] == '2')
					{
						map.map[j][i] = 'C';
					}
					++j;
				}
				++i;
			}
			vars->plr.x = vars->new_plr.x;
			vars->plr.y = vars->new_plr.y - 1;
			vars->steps = -1;
			vars->count_coins = 0;
		}
		vars->plr.y++;
		vars->steps++;
		printf("%d\n", vars->steps);
	}
}

