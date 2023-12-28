/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:10:56 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/28 18:42:04 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Includes/cub3d.h"

void	init_raycasting(t_raycast *raycast, t_data *data, double angle)
{
	raycast->x = data->xpos;
	raycast->y = data->ypos;
	raycast->cos_x = cos(deg_to_rad(angle));
	raycast->sin_y = sin(deg_to_rad(angle));
	raycast->max_dist = RENDER_DIST;
	raycast->distance_to_wall = 0;
	raycast->distance = 0;
}

// return the distance between the player and the wall
double	distance(double posx, double posy, double hitx, double hity)
{
	return (sqrt(pow(hitx - posx, 2) + pow(hity - posy, 2)));
}

static double	ft_calcul_ang_dbl(double iangl, double iofset)
{
	iangl += iofset;
	if (iangl < 0)
		return (360 - (iangl * -1));
	else if (iangl >= 360)
		return (iangl - 360);
	return (iangl);
}

void	ft_raycasting_one_ray(t_data *data, int iframe)
{
	double	iangl;
	double	i;
	double	ilen;
	double	x;
	double	y;

	iangl = (double)(ft_calcul_ang(data->look, - (LOOK_ANGLE / 2)));
	i = ((double)LOOK_ANGLE / ((WIDTH / RESOLUTION)) * iframe);
	iangl = ft_calcul_ang_dbl(iangl, i);
	ilen = 0;
	x = data->xpos;
	y = data->ypos;
	while (ilen < RENDER_DIST)
	{
		x += ft_calc_depl_x(iangl);
		y += ft_calc_depl_y(iangl);
		if (ft_check_colision(data, x, y))
			break ;
		ilen += DEPLACEMENT;
	}
	put_wall(data, WALL_SIZE / ilen, iframe);
}

void	ft_raycasting(t_data *data)
{
	int	iframe;

	iframe = 0;
	ft_new_img(data);
	while (iframe * RESOLUTION <= WIDTH)
	{
		ft_raycasting_one_ray(data, iframe);
		iframe += 1;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
