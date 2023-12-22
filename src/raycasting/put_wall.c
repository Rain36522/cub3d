/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:06:19 by pudry             #+#    #+#             */
/*   Updated: 2023/12/22 10:07:52 by pudry            ###   ########.ch       */
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
	// printf("iscale : %i\n", twall->iscale);
	while (ix < twall->ixend)
	{
		iyscale = iy * twall->iscale;
		ixscale = ix * twall->iscale;
		while (iyscale >= twall->texutre->heigth)
			iyscale -= twall->texutre->heigth;
		while (ixscale >= twall->texutre->width)
			ixscale -= twall->texutre->width;
		// printf("read img, x : %i, y : %i\n", ixscale, iyscale);
		ipixel_color = get_color_pixel(twall->texutre, ixscale, iyscale);
		put_pixel_img(data, ix, iy, ipixel_color);
		ix ++;
	}
}

static void	ft_put_wall(t_wall *twall, t_ray *ray, t_data *data)
{
	int		iy;

	twall->iystrt = (HEIGHT / 2) - (ray->wall_height / 2);
	if (twall->iystrt < 0)
		twall->iystrt = 0;
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
	twall.iscale = twall.texutre->heigth / (double)ray->wall_height;
	if (twall.texutre != img)
		img_frame = 0;
	if ((img_frame + RESOLUTION) * twall.iscale >= twall.texutre->width)
	{
		img_frame = 0;
		printf("reset img frame\n");
	}
	// printf("img_frame : %i, res : %i, scale : %f\n", img_frame, RESOLUTION, twall.iscale);
	twall.img_xstrt = img_frame;
	twall.ixstrt = iframe * RESOLUTION;
	twall.ixend = twall.ixstrt + RESOLUTION;
	if (twall.ixend >= WIDTH)
		twall.ixend = WIDTH - 1;
	DEBUG
	ft_put_wall(&twall, ray, data);
	DEBUG
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
