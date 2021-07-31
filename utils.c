/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:58:24 by akhachat          #+#    #+#             */
/*   Updated: 2021/07/27 12:58:58 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str, t_vars *vars)
{
	(void)vars;
	ft_putendl_fd(str, 1);
	exit(1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8 ));
	*(unsigned int *)dst = color;
}

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	system("killall afplay");
	exit(0);
	return (0);
}

int		my_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int    get_pixel(t_data *texture, int x, int y)
{
    return *(int *)(texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8)));
}
