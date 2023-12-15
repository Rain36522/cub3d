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

static char	**tmp_gen_map(void)
{
	char	**a;

	a = (char **) malloc(sizeof(char *) * 5);
	a[4] = NULL;
	a[0] = ft_strdup("1111");
	a[1] = ft_strdup("1001");
	a[2] = a[1];
	a[3] = a[0];
	return (a);
}

static t_data	*init_game(void)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = tmp_gen_map();
	data->mlx = mlx_init();
	data->xpos = 205;
	data->ypos = 205;
	data->look = 0;
	data->mlx_win = mlx_new_window(data->mlx, 1920, 950, "so_long");
	return (data);
}

int	main(void)
{
	t_data	*data;
	int		i;

	// loadImage(ptr, tw, th, "../pics/barrel.png");
	data = init_game();
	i = 0;
	while (data->map[i])
	{
		printf("map : %s\n", data->map[i ++]);
	}
	// data.input = ft
	put_map(data);
	put_player(data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_press_cross, NULL);
	mlx_loop(data->mlx);
}