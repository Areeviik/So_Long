/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:56:05 by akhachat          #+#    #+#             */
/*   Updated: 2021/07/27 12:57:29 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int 	check_map_symbols(char *line)
{
	int	i = 0;

	if (ft_strlen(line) != map.length)
		return (0);
	while (line[i] != '\0')
	{
		if(line[i] != '0' && line[i] != '1' && line[i] != '1' && line[i] != 'E' && line[i] != 'C' && line[i] != 'P' && line[i] !='G')
		return (0);
		i++;
		if (line[i] == 'C')
			count.coins_count++;
		if (line[i] == 'E')
			count.exit_count++;
		if (line[i] == 'P')
			count.plr_count++;
	}
	return (1);
}

void	map_malloc(t_vars *vars)
{
	int i =0;
	if (!(map.map = malloc((map.height + 1) * sizeof(char*))))
		error("Error\n Can't allocate",vars);
	while(i < map.height)
	{
		if(!(map.map[i] = malloc((map.length + 1) * sizeof(char *))))
			error("Error\n Can't allocate", vars);
		i++;
	}
}

int fill_map(int fd, t_vars *vars)
{
	int i,j;
	int a = 1;
	char *s;

	i = 0;
	while (i < map.height)
	{
		a = get_next_line(fd, &s);
		j = 0;
		while (j < map.length)
		{
			map.map[i][j] = s[j];
			if(map.map[i][j] == 'P')
			{
				vars->plr.x = i;
				vars->plr.y = j;
				vars->new_plr.x = i;
				vars->new_plr.y = j;
				map.map[i][j] = '0';
			}
			++j;
		}
		map.map[i][j] = '\0';
		++i;
	}
	map.map[i] = NULL;
	return 0;
}

int check_walls(int a, int b)
{
	int i,j;

	i = 0;
	while (i < b)
	{
		j = 0;
		while (j < a)
		{
			if (i == 0 || i == b - 1 || j == 0 || j == a - 1)
				if (map.map[i][j] != '1')
					return 0;
				j++;
		}
		i++;
	}
	return (1);
}

