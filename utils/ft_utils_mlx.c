/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:36:33 by pudry             #+#    #+#             */
/*   Updated: 2023/12/15 16:27:17 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	ft_put_square(t_data *data, int x, int y, int icolor)
{
	int	i;
	int	j;

	x *= MAP_SIZE;
	y *= MAP_SIZE;
	j = 0;
	while (j <= MAP_SIZE && j < HEIGHT)
	{
		i = 0;
		while (i <= MAP_SIZE && i < WIDTH)
		{
			// printf("put pixel : %i, %i\n", x + i, j + y);
			mlx_pixel_put(data->mlx, data->mlx_win, x + i, y + j, icolor);
			i ++;
		}
		j ++;
	}
}

