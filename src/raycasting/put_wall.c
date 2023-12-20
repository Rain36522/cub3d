/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:30 by pudry             #+#    #+#             */
/*   Updated: 2023/12/20 16:32:19 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static int	ft_give_color(t_ray *ray)
{
	int	icolor;

	icolor = 0;
	icolor = (255 * ray->wall_height) / WALL_SIZE;
	if (ray->side == 0 && ray->diry >= 0 && ray->dirx >= 0)
		icolor = create_trgb(0 , 0, icolor, 0);
	else if (ray->side == 1 && ray->diry >= 0 && ray->dirx < 0)
		icolor = create_trgb(0 , 0, icolor, 0);
	else if (ray->side == 0 && ray->diry >= 0 && ray->dirx >= 0)
		icolor = create_trgb(0 , 0, 0, icolor);
	else if (ray->side == 1 && ray->diry < 0 && ray->dirx >= 0)
		icolor = create_trgb(0 , 0, 0, icolor);
	else if (ray->side == 0 && ray->diry < 0 && ray->dirx >= 0)
		icolor = create_trgb(0 , icolor, 0, 0);
	else if (ray->side == 1 && ray->diry < 0 && ray->dirx < 0)
		icolor = create_trgb(0 , icolor, 0, 0);
	else if (ray->side == 0 && ray->diry < 0 && ray->dirx < 0)
		icolor = create_trgb(0 , icolor, icolor, 0);
	else if (ray->side == 1 && ray->diry >= 0 && ray->dirx < 0)
		icolor = create_trgb(0 , icolor, icolor, 0);
	return (icolor);
}

void	put_wall(t_data *data, t_ray *ray, int iframe)
{
	int	iy;
	int	ix;
	int	x;
	int	y;
	int	icolor;

	if (ray->wall_height > WALL_SIZE)
		ray->wall_height = WALL_SIZE;
	iy =(int)(HEIGHT / 2) - (ray->wall_height / 2);
	ix = iframe * (int)RESOLUTION;
	y = iy;
	icolor = ft_give_color(ray);
	while (y - iy < ray->wall_height && y < HEIGHT)
	{
		x = ix;
		while (x - ix < RESOLUTION && x < WIDTH)
		{
			if (x < 0 || y < 0)
				exit(1);
			put_pixel_img(data, x ++, y, icolor);
		}
		y ++;
	}
}
