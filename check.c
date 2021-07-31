/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:57:38 by akhachat          #+#    #+#             */
/*   Updated: 2021/07/27 12:58:20 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int 	check_map_name(char *argv)
{
	if (argv[ft_strlen(argv) - 1] == 'r' && argv[ft_strlen(argv) - 2] == 'e'
		&& argv[ft_strlen(argv) - 3] == 'b' && argv[ft_strlen(argv) - 4] == '.')
		return (0);
	else
		return (1);
}

void	check_arguments(int argc, char **argv, t_vars *vars)
{
	if (argc != 2)
		error("Error\nWrong number of arguments", vars);
	else if (check_map_name(argv[1]))
		error("Error\nThe end of map name isn't .ber", vars);
}
