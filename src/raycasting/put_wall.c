/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:30 by pudry             #+#    #+#             */
/*   Updated: 2023/12/21 15:39:37 by pudry            ###   ########.fr       */
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

static void ft_put_line_wall(t_wall *twall, t_data *data, int iy)
{
	int				ix;
	int				iyscale;
	int				ixscale;
	unsigned int	ipixel_color;

	ix = twall->ixstrt;
	while (ix < twall->ixend)
	{
		iyscale = iy * twall->iscale;
		ixscale = ix * twall->iscale;
		if (iyscale >= twall->texutre->heigth)
			iyscale = twall->texutre->heigth - 1;
		if (ixscale >= twall->texutre->width)
			ixscale = twall->texutre->width - 1;
		ipixel_color = get_color_pixel(twall->texutre, ixscale, iyscale);
		put_pixel_img(data, ix, iy, ipixel_color);
		ix ++;
	}
}

static void	ft_put_wall(t_wall *twall, t_ray *ray, t_data *data)
{
	int		iy;

	twall->iscale = twall->texutre->heigth / ray->wall_height;
	twall->iystrt = (HEIGHT / 2) - (ray->wall_height / 2);
	iy = twall->iystrt;
	twall->iyend = (HEIGHT / 2) + (ray->wall_height / 2);
	if (twall->iyend >= HEIGHT)
		twall->iyend = HEIGHT- 1;
	while (iy <= twall->iyend)
	{
		ft_put_line_wall(twall, data, iy);
		iy ++;
	}

}


void	put_wall(t_data *data, t_ray *ray, int iframe)
{
	static int			img_frame;
	static t_pixput		*img;
	t_wall				twall;

	// DEBUG
	twall.texutre = ft_get_texture(ray,data);
	twall.iscale = ray->wall_height / twall.texutre->heigth ;
	if (twall.texutre != img)
		img_frame = 0;
	if ((img_frame + RESOLUTION) * twall.iscale >= twall.texutre->width)
		img_frame = 0;
	twall.img_xstrt = img_frame;
	twall.ixstrt = iframe * RESOLUTION;
	twall.ixend = twall.ixstrt + RESOLUTION;
	if (twall.ixend >= WIDTH)
		twall.ixend = WIDTH - 1;
	ft_put_wall(&twall, ray, data);
	img_frame ++;
	img = twall.texutre;
	
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
