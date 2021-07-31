/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:55:14 by akhachat          #+#    #+#             */
/*   Updated: 2021/07/27 12:55:50 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_square(t_data *img, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < sqsize.h)
	{
		i = 0;
		while (i < sqsize.l)
		{
			my_mlx_pixel_put(img, x * sqsize.l + i, y * sqsize.h + j, color);
			i++;
		}
		j++;
	}
}

void	draw_imgs(t_data *img, t_data *texture, int x, int y)
{
	int	i;
	int	j;
	int	color;

	j = 0;
	while (j < sqsize.h)
	{
		i = 0;
		while (i < sqsize.l)
		{
			color = get_pixel(texture, i, j);
			if ((unsigned int)color != 0xFF000000)
				my_mlx_pixel_put(img, x * sqsize.l + i, y * sqsize.h + j, color);
			else
				my_mlx_pixel_put(img, x * sqsize.l + i, y * sqsize.h + j, 
				my_rgb(229, 204, 255));
			i++;
		}
		j++;
	}
}

int		draw(t_vars *vars)
{
    int	i;
	int	j;

    j = 0;
    while (j < map.height)
    {
        i = 0;
        while (i < map.length)
        {
            if(map.map[j][i] == '1')
			{
                draw_imgs(&vars->data, &vars->wall, i, j);
			}
            if(map.map[j][i] == '0' || map.map[j][i] == '2')
			{
                draw_square(&vars->data, i, j, my_rgb(204,255,229));
			}
			if(map.map[j][i] == 'E')
			{
				draw_imgs(&vars->data, &vars->exit, i, j);
			}
			if(map.map[j][i] == 'C')
			{
				draw_imgs(&vars->data, &vars->coins, i, j);
			}
			if(map.map[j][i] == 'G')
			{
				draw_imgs(&vars->data, &vars->enemy, i, j);
			}
			if ((j == vars->plr.x) && (i == vars->plr.y))
			{
				draw_imgs(&vars->data, &vars->player, i, j);
			}
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data.img, 0, 0);
	mlx_string_put(vars->mlx, vars->mlx_win,730,480,my_rgb(0,0,0), "Count = ");
	mlx_string_put(vars->mlx, vars->mlx_win, 810, 480, my_rgb(0,0,0), 
	ft_itoa(vars->steps));
    return	(0);
}
