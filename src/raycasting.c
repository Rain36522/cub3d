/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:10:56 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/19 11:10:59 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Includes/cub3d.h"

// function to throw the rays
void	ft_raycasting(t_data data, int map[WIDTH][HEIGHT])
{
	int		i;
	double	angle;
	i = 0;
	// calcul langle du rayon par rapport a la dir du player
	while (i < WIDTH)
	{
		angle = data.look - ANGLE / 2 + i * (ANGLE / WIDTH);
		i++;
	}
}