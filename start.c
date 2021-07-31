/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:29:38 by akhachat          #+#    #+#             */
/*   Updated: 2021/07/14 17:44:42 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int 	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 126)
		move_up(vars);
	if (keycode == 1 || keycode == 125)
		move_down(vars);
	if (keycode == 0 || keycode == 123)
		move_left(vars);
	if (keycode == 2 || keycode == 124)
		move_right(vars);
	if (keycode == 48)
		system("afplay ./sounds/BreakingBad.mp3 & ");
	if (keycode == 53)
		close_win(vars);
	return (0);
}

void	parsing(char **argv, t_vars *vars)
{
	int fd;
	char *line;
	int	a = 1;

	if (((fd = open(argv[1], O_RDONLY)) && fd == -1))
		error("Error\nCant open or find the file", vars);
	
	init(vars);

	while(a > 0)
	{
		a = get_next_line(fd, &line);
		map.height++;
		if (!map.length)
			map.length = ft_strlen(line);
		if(check_map_symbols(line) == 0)
			error("Invalid map",vars);
	}
	if (count.coins_count == 0 || count.plr_count == 0 || count.exit_count == 0 || count.plr_count > 1)
		error("Error\nInvalid map", vars);
	map_malloc(vars);
	close(fd);
	if (((fd = open(argv[1], O_RDONLY)) && fd == -1))
		error("Error\nCant open or find the file", vars);
	fill_map(fd, vars);
	if(check_walls(map.length, map.height) == 0)
		error("Error\nMap isn't surrounded by walls", vars);
}

void	init(t_vars *vars)
{
	map.length = 0;
	map.height = 0;
	count.exit_count = 0;
	count.plr_count = 0;
	count.coins_count = 0;
}
void	images(t_vars *vars)
{
	int 	imgW, imgH;
	int		imgC, imgCh;

	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm", &imgW, &imgH);
	vars->wall.addr = mlx_get_data_addr(vars->wall.img, &vars->wall.bits_per_pixel, &vars->wall.line_length, &vars->wall.endian);

	vars->player.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/P.xpm", &imgC, &imgCh);
	vars->player.addr = mlx_get_data_addr(vars->player.img, &vars->player.bits_per_pixel, &vars->player.line_length, &vars->player.endian);


	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/E.xpm", &imgW, &imgH);
	vars->exit.addr = mlx_get_data_addr(vars->exit.img, &vars->exit.bits_per_pixel, &vars->exit.line_length, &vars->exit.endian);

	
	vars->coins.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/coin.xpm", &imgW, &imgH);
	vars->coins.addr = mlx_get_data_addr(vars->coins.img, &vars->coins.bits_per_pixel, &vars->coins.line_length, &vars->coins.endian);

	vars->enemy.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/enemy.xpm", &imgW, &imgH);
	vars->enemy.addr = mlx_get_data_addr(vars->enemy.img, &vars->enemy.bits_per_pixel, &vars->enemy.line_length, &vars->enemy.endian);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int 	img_height;
	int 	img_width;
	int 	h,l;
	int 	sizex, sizey;


	check_arguments(argc, argv, &vars);
	parsing(argv, &vars);

	sqsize.h = 60;
	sqsize.l = 60;
	vars.mlx = mlx_init();

	mlx_get_screen_size(vars.mlx, &sizex, &sizey);
    l = map.length * sqsize.l;
    h = map.height * sqsize.h;
    if(l > sizex)
        {
            l = sizex;
            sqsize.h /= 2;
            sqsize.l /= 2;
        }
    if(h > sizey)
        {
            h = sizey;
            sqsize.h /= 2;
            sqsize.l /= 2;
        }

	vars.mlx_win = mlx_new_window(vars.mlx, l, h, "So long");
	vars.data.img = mlx_new_image(vars.mlx, l, h);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel, &vars.data.line_length, &vars.data.endian);
	images(&vars);
	mlx_loop_hook(vars.mlx, draw, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 0, close_win, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
