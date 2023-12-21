/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:30 by pudry             #+#    #+#             */
/*   Updated: 2023/12/21 10:39:21 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static t_pixput	*ft_get_texture(t_ray *ray, t_data *data)
{
	ray->dirx;
	ray->diry;
	ray->side; // 0 = touch x, 1 = touch y
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

static void	ft_put_wall(t_pixput *texture, t_data *data, int iframe, int img_frame)
{
	double	iscale;

	iscale = 
}


void	put_wall(t_data *data, t_ray *ray, int iframe)
{
	int					icolor;
	static int			img_frame;
	static t_pixput		*img;
	t_pixput			*texture;


	texture = ft_get_texture(ray,data);
	if (texture != img)
		img_frame = 0;
	if (img_frame + RESOLUTION >= texture->width)
		img_frame = 0;
	ft_putwall(texture, data, iframe * RESOLUTION, img_frame * RESOLUTION);
	img_frame ++;
	img = texture;
}

// void	put_wall(t_data *data, t_ray *ray, int iframe)
// {
// 	int	iy;
// 	int	ix;
// 	int	x;
// 	int	y;
// 	int	icolor;

// 	if (ray->wall_height > WALL_SIZE)
// 		ray->wall_height = WALL_SIZE;
// 	iy =(int)(HEIGHT / 2) - (ray->wall_height / 2);
// 	ix = iframe * (int)RESOLUTION;
// 	y = iy;
// 	icolor = ft_give_color(ray);
// 	while (y - iy < ray->wall_height && y < HEIGHT)
// 	{
// 		x = ix;
// 		while (x - ix < RESOLUTION && x < WIDTH)
// 		{
// 			if (x < 0 || y < 0)
// 				exit(1);
// 			put_pixel_img(data, x ++, y, icolor);
// 		}
// 		y ++;
// 	}
// }
