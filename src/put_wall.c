/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:18:30 by pudry             #+#    #+#             */
/*   Updated: 2023/12/19 14:26:27 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	put_wall(t_data *data, double wall, int iframe)
{
	int	iwall;
	int	iy;
	int	ix;
	int	x;
	int	y;

	iwall = (int)wall;
	if (iwall > WALL_SIZE)
		iwall = WALL_SIZE;
	printf("iwall : %i\n", iwall);
	iy =(int)(HEIGHT / 2) - (iwall / 2);
	ix = iframe * (int)RESOLUTION;
	y = iy;
	while (y - iy < iwall && y < HEIGHT)
	{
		x = ix;
		while (x - ix < RESOLUTION && x < WIDTH)
		{
			//printf("x : %i, y : %i\n", x, y);
			if (x < 0 || y < 0)
				exit(1);
			put_pixel_img(data, x ++, y, 0x0000FF00);
		}
		y ++;
	}
}
