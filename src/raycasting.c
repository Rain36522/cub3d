/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:10:56 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/19 11:10:59 by cduffaut         ###   ########.fr       */
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

// function to throw the rays
// "stop when it hits the wall"
// void	ft_raycasting_one_ray(t_data *data, int iframe)
// {
// 	int			i;
// 	t_raycast	raycast;

// 	i = 0;

// 	// calcul langle du rayon par rapport a la dir du player
// 	raycast.angle = (double)(ft_calcul_ang(data->look, - (LOOK_ANGLE / 2)));
// 	i = ((double)LOOK_ANGLE / ((WIDTH / RESOLUTION)) * iframe);
// 	raycast.angle = ft_calcul_ang_dbl(raycast.angle, i);
// 	// init list raycast
// 	init_raycasting(&raycast, data, raycast.angle);
// 	// throw the ray
// 	while (raycast.distance < raycast.max_dist)
// 	{
// 		raycast.x += raycast.cos_x * DEPLACEMENT;
// 		raycast.y += raycast.sin_y * DEPLACEMENT;
// 		// check if the ray is out of thes map
// 		if (raycast.x < 0 || raycast.x > WIDTH
// 			|| raycast.y < 0 || raycast.y > HEIGHT)
// 		{
// 			DEBUG
// 			break ;
// 		}
// 		// the ray incouneter a wall
// 		if (ft_check_colision(data, raycast.x, raycast.y))
// 		{
// 			// calcul euclidien
// 			raycast.distance_to_wall = distance(data->xpos, data->ypos, raycast.x, raycast.y);
// 			// modifier la taille du mur
// 			raycast.wall_height = WALL_SIZE / raycast.distance_to_wall;
// 			// "afficher le mur"
// 			// printf ("wall height: %.2f, wall distance: %.2f\n", raycast.wall_height, raycast.distance_to_wall);
// 			break ;
// 		}
// 		// dislay the ray on the screen
// 		// printf("Ray at angle %.2f hit point (%.2f, %.2f)\n", raycast.angle, raycast.x, raycast.y);
// 		raycast.distance += DEPLACEMENT;
// 		// printf("wall height : %f\n", raycast.wall_height);
// 	}
// 	printf("wall height : %f\n", raycast.wall_height);
// 	put_wall(data, raycast.wall_height, iframe);
// }

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
	printf("iangl : %f\n", iangl);
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
	printf("wall_size : %f, ilen : %f\n\n", (double)WALL_SIZE / ilen, ilen);
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
		DEBUG
		iframe += 1;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
