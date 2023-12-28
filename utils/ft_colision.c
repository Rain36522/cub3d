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
	if (data->map[iy][ix] == '1' || data->map[iy][ix] == ' ' || \
												data->map[iy][ix] == 'D')
	{
		data->x = data->xpos;
		data->y = data->ypos;
		return (1);
	}
	return (0);
}