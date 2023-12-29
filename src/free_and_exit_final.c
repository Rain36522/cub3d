/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit_final.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 08:51:56 by csil              #+#    #+#             */
/*   Updated: 2023/12/29 09:30:42 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static void	destroy_and_free(t_pixput *list, t_data *data)
{
	if (!list)
		return ;
	if (list->path)
	{
		free (list->path);
		list->path = NULL;
	}
	if (list)
	{
		mlx_destroy_image(data->mlx, list->img);
	}
	if (list->addr)
	{
		free (list->addr);
		list->addr = NULL;
	}
}

static void	destroy_and_free_pixput(t_data *data)
{
	destroy_and_free(&data->ea, data);
	destroy_and_free(&data->we, data);
	destroy_and_free(&data->so, data);
	destroy_and_free(&data->no, data);
	destroy_and_free(&data->door, data);
	destroy_and_free(&data->img, data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		free (data->mlx);
	data->mlx = NULL;
}

void	free_and_exit_final(t_data *data)
{
	if (!data)
		exit(0);
	free_tab(data->map);
	destroy_and_free_pixput(data);
	free (data);
	data = NULL;
}