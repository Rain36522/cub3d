/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:03:26 by pudry             #+#    #+#             */
/*   Updated: 2023/12/26 23:03:26 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// static char	**tmp_gen_map(void)
// {
// 	char	**a;

// 	a = (char **) malloc(sizeof(char *) * 5);
// 	a[4] = NULL;
// 	a[0] = ft_strdup("1111");
// 	a[1] = ft_strdup("1001");
// 	a[2] = a[1];
// 	a[3] = a[0];
// 	return (a);
// }

static t_data	*init_game(char **argv)
{
	t_data *data;
	data = init_list(argv);
	DEBUG
	if (!data)
		return (NULL);
	data->x = data->xpos;
	data->y = data->ypos;
	data->make_moov = '1';
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUBE3D");
	return (data);
}

static int	ft_loop(t_data *data)
{
	if (!data->no.img)
	{
		put_texture_in_data(data);
		free(data->no.path);
		free(data->so.path);
		free(data->ea.path);
		free(data->we.path);
	}
	if (data->make_moov == '1')
	{
		ft_make_moov(data, data->x, data->y);
		data->make_moov = '0';
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		return (0);
	data = init_game(argv);
	if (!data)
		return (0);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_press_cross, NULL);
	mlx_loop_hook(data->mlx, ft_loop, data);
	mlx_loop(data->mlx);
	free_and_exit_prog(data);
}
