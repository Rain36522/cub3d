/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:05:47 by pudry             #+#    #+#             */
/*   Updated: 2023/12/26 11:10:59 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static t_pixput	*ft_get_texture(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
	{
		if (ray->dirx >= 0 && ray->diry >= 0)
			return (&data->ea);
		else if (ray->dirx < 0 &&  ray->diry >= 0)
			return (&data->we);
		else if (ray->dirx < 0 && ray->diry < 0)
			return (&data->we);
		else
			return (&data->ea);
	}
	if (ray->dirx >= 0 && ray->diry >= 0)
		return (&data->no);
	else if (ray->dirx < 0 &&  ray->diry >= 0)
		return (&data->no);
	else if (ray->dirx < 0 && ray->diry < 0)
		return (&data->so);
	else
		return (&data->so);
}

void	put_wall(t_data *data, t_ray *ray, int iframe)
{
	static t_pixput		*img;
	t_wall				wall;
	int					icolor;
	int					iy;

	img = ft_get_texture(ray, data);
	if (ray->side == 0)
		ray->wallx = ray->posy + ray->prpwalldist * ray->diry;
	else
		ray->wallx = ray->posx + ray->prpwalldist * ray->dirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = ray->wallx * img->width;
	if ((ray->side == 0 && ray->dirx > 0) || (ray->side == 1 && ray->diry < 0))
		ray->texx = img->width - ray->texx - 1;
	wall.text = img;
	wall.iscale = 1.0 * img->heigth / ray->wall_height;
	wall.iystrt = HEIGHT / 2 - ray->wall_height / 2;
	if (wall.iystrt < 0)
		wall.iystrt = 0;
	iy = wall.iystrt;
	wall.iy = 0.0;
	wall.iyend = (HEIGHT - wall.iystrt) * wall.iscale;
	DEBUG
	while (iy <= HEIGHT - wall.iystrt)
	{
		// printf("img read : %i, %i\n", ray->texx, (int)wall.iy);
		// printf("pixput : %i, %i\n", iframe * RESOLUTION, iy);
		icolor = get_color_pixel(img, ray->texx, (int)wall.iy);
		put_pixel_img(data, iframe * RESOLUTION, iy, icolor);
		wall.iy += wall.iscale;
		iy ++;
	}
	DEBUG
}
