/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:36:33 by pudry             #+#    #+#             */
/*   Updated: 2023/12/28 19:38:45 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// Attention a bien generer l image avant.
void	ft_put_square(t_data *data, int x, int y, int icolor)
{
	int	i;
	int	ix;
	int	j;
	int	iy;

	i = (x * MAP_SIZE);
	j = (y * MAP_SIZE);
	iy = j;
	while (iy - j < MAP_SIZE)
	{
		ix = i;
		while (ix - i < MAP_SIZE)
			put_pixel_img(data, ix ++, iy, icolor);
		iy ++;
	}
}

void	ft_new_img(t_data *data)
{
	t_pixput	*img;

	img = &data->img;
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bit_pp, \
				&img->line_len, &img->endian);
}

void	put_pixel_img(t_data *data, int x, int y, int icolor)
{
	char		*dst;
	t_pixput	*img;

	img =&data->img;
	dst = img->addr + (y * img->line_len + x * (img->bit_pp / 8));
	*(unsigned int*)dst = icolor;
}

unsigned int	get_color_pixel(t_pixput *img, int x, int y)
{
	char	*dst;
	dst = img->addr + (y * img->line_len + x * (img->bit_pp / 8));
	return (*(unsigned int*)dst);
}

