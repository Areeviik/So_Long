/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:10:49 by akhachat          #+#    #+#             */
/*   Updated: 2021/07/19 13:01:40 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

struct sq_size
{
	int h;
	int l;
}		sqsize;

typedef struct s_plr
{
	int 	x;
	int		y;
}		t_plr;


typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_data		data;
	t_data		coins;
	t_data		exit;
	t_data		wall;
	t_data		player;
	t_plr 		plr;
	t_plr 		new_plr;
	t_data		enemy;
	int 		count_coins;
	int			steps;
}				t_vars;

struct s_count
{
	int	coins_count;
	int	plr_count;
	int	exit_count;
}		count;

struct 		s_map
{
	int		height;
	int		length;
	char	**map;
}			map;	

void	images(t_vars *vars);
void	init(t_vars *vars);
void	parsing(char **argv, t_vars *vars);
int    	get_pixel(t_data *texture, int x, int y);
int		my_rgb(int r, int g, int b);
int		close_win(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	error(char *str, t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
void	move_down(t_vars *vars);
void	move_up(t_vars *vars);
int 	check_walls(int a, int b);
int 	fill_map(int fd, t_vars *vars);
void	map_malloc(t_vars *vars);
int 	check_map_symbols(char *line);
int 	draw(t_vars *vars);
void	draw_imgs(t_data *img, t_data *texture, int x, int y);
void	draw_square(t_data *img, int x, int y, int color);
void	check_arguments(int argc, char **argv, t_vars *vars);
int 	check_map_name(char *argv);

#endif
