/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:10:10 by pudry             #+#    #+#             */
/*   Updated: 2023/12/28 18:10:10 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static int	ft_is_wall(t_data *data, int iy, int ix)
{
	return (data->map[iy][ix] == '1' || data->map[iy][ix] == ' ' || \
		data->map[iy][ix] == 'D');
}

static int	ft_check_corner(t_data *data, double x, double y)
{
	int	ix;
	int	iy;

	if (!((int)x != (int)data->xpos || (int)y != (int)data->ypos))
		return (0);
	ix = (int)data->xpos;
	iy = (int)data->ypos;
	if (data->look >= 1 && data->look <= 89)
		if (ft_is_wall(data, iy + 1, ix) && ft_is_wall(data, iy, ix + 1))
			return (1);
	if (data->look >= 91 && data->look <= 179)
		if (ft_is_wall(data, iy + 1, ix) && ft_is_wall(data, iy, ix - 1))
			return (1);
	if (data->look >= 181 && data->look <= 269)
		if (ft_is_wall(data, iy - 1, ix) && ft_is_wall(data, iy, ix - 1))
			return (1);
	if (data->look >= 271 && data->look <= 359)
		if (ft_is_wall(data, iy + 1, ix) && ft_is_wall(data, iy, ix + 1))
			return (1);
	return (0);
}

int	ft_check_colision(t_data *data, double x, double y)
{
	int	ix;
	int	iy;

	if (data->xpos > x)
		ix = (int)(x - 0.1);
	else
		ix = (int)(x + 0.1);
	if (data->ypos > y)
		iy = (int)(y - 0.1);
	else
		iy = (int)(y + 0.1);
	if (ft_check_corner(data, x, y))
	{
		data->x = data->xpos;
		data->y = data->ypos;
		return (1);
	}
	if (ft_is_wall(data, iy, ix))
	{
		data->x = data->xpos;
		data->y = data->ypos;
		return (1);
	}
	return (0);
}
