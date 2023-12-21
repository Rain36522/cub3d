/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:39:27 by pudry             #+#    #+#             */
/*   Updated: 2023/12/21 14:34:33 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"


static void	ft_raytracer(t_ray *ray, t_data *data, int iframe)
{
	while (data->map[ray->mapy][ray->mapx] != '1')
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->prpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->prpwalldist = (ray->sidedisty - ray->deltadisty);
	ray->wall_height = (int)(WALL_SIZE / ray->prpwalldist);
	put_wall(data, ray, iframe);
}

static void init_raytracer(t_ray *ray, t_data *data, int iframe)
{
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	ray->angle = (double)(ft_calcul_ang(data->look, - (LOOK_ANGLE / 2)));
	ray->angle = ft_calcul_ang(ray->angle, \
				(double)LOOK_ANGLE / ((WIDTH / RESOLUTION)) * iframe);
	ray->dirx = cos(deg_to_rad(ray->angle));
	ray->diry = sin(deg_to_rad(ray->angle));
	if (ray->dirx == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = fabs(1 / ray->dirx);
	if (ray->diry == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1 / ray->diry);
	if (ray->dirx < 0)
		ray->stepx = -1;
	else
		ray->stepx = 1;
	if (ray->diry < 0)
		ray->stepy = -1;
	else
		ray->stepy = 1;
}

static void	ft_launch_ray(t_data *data, t_ray *ray)
{
	int		iframe;

	iframe = 0;
	while (iframe * RESOLUTION < WIDTH)
	{
		init_raytracer(ray, data, iframe);
		if (ray->dirx < 0)
			ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
		else
			ray->sidedistx = (ray->mapx + 1 - ray->posx) * ray->deltadistx;
		if (ray->diry < 0)
			ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
		else
			ray->sidedisty = (ray->mapy + 1 - ray->posy) * ray->deltadisty;
		ft_raytracer(ray, data, iframe);
		iframe++;
	}
	// printf("data look : %f\n", data->look);
}

void	ft_raycasting(t_data *data)
{
	t_ray	*ray;

	ray = &data->raystruct;
	ray->posx = data->xpos;
	ray->posy = data->ypos;
	ray->side = 0;
	ft_launch_ray(data, ray);
}