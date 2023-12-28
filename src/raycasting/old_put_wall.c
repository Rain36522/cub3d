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
	if (data->map[ray->mapy][ray->mapx] == 'D')
	{
		printf ("Door: %s\n", data->door.path);
		return (&data->door);
	}
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

static void	ft_put_wall(t_wall *twall, t_ray *ray, t_data *data)
{
	int		iy;

	twall->iystrt = (HEIGHT / 2) - (ray->wall_height / 2);
	if (ray->side == 0)
		ray->wallx = ray->posy + ray->prpwalldist * ray->diry;
	else
		ray->wallx = ray->posx + ray->prpwalldist * ray->diry;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)(twall->text->width));
	if ((ray->side == 0 && ray->dirx > 0) || \
							(ray->side == 1 && ray->diry < 0))
		ray->texx = twall->text->width - ray->texx - 1;
	if (twall->iystrt < 0)
		twall->iystrt = 0;
	iy = twall->iystrt;
	twall->iyend = (HEIGHT / 2) + (ray->wall_height / 2);
	if (twall->iyend >= HEIGHT)
		twall->iyend = HEIGHT - 1;
	while (iy <= twall->iyend)
	{
		ft_put_line_wall(twall, data, iy, ray);
		iy ++;
	}

}

void	put_wall(t_data *data, t_ray *ray, int iframe)
{
	static int			img_frame;
	static t_pixput		*img;
	t_wall				twall;

	twall.text = ft_get_texture(ray, data);
	twall.iscale = twall.text->heigth / (double)ray->wall_height;
	if (twall.text != img)
		img_frame = 0;
	if ((img_frame + RESOLUTION) * twall.iscale >= twall.text->width)
	{
		img_frame = 0;
	}
	twall.img_xstrt = img_frame;
	twall.ixstrt = iframe * RESOLUTION;
	twall.ixend = twall.ixstrt + RESOLUTION;
	if (twall.ixend >= WIDTH)
		twall.ixend = WIDTH - 1;
	ft_put_wall(&twall, ray, data);
	img_frame++;
	img = twall.text;
}
