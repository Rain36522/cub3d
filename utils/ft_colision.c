/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:05:36 by pudry             #+#    #+#             */
/*   Updated: 2023/12/18 18:16:44 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	ft_check_colision(t_data *data, double x, double y)
{
	int	ix;
	int	iy;

	ix = (int)x;
	iy = (int)y;
	if (data->map[iy][ix] == '1' || data->map[iy][ix] == ' ')
		return (1);
	return (0);
}