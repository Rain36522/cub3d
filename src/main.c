/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:39:16 by pudry             #+#    #+#             */
/*   Updated: 2023/12/15 12:40:42 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

t_data	*init_game(void)
{
	t_data	*data;
	char *array[] = {"11111111111", "10010000001", "10010000001", "10010010001", "10000000001", "10000000001", "11111111111"};

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 950, "so_long");
	data->map = array;
	data->ix = 11;
	data->iy = 7;
	return (data);
}

int	ft_press_cross(void)
{
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	*data;

	// loadImage(ptr, tw, th, "../pics/barrel.png");
	data = init_game();
	// data.input = ft
	mlx_hook(data->mlx_win, WIDTH, HEIGHT, ft_press_cross, NULL);
	mlx_loop(data->mlx);
}