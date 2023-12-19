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

void	init_raycasting(t_raycast *raycast, t_data *data, double angle)
{
	raycast->x = data->xpos;
	raycast->y = data->ypos;
	raycast->cos_x = cos(angle);
	raycast->sin_y = sin(angle);
	raycast->max_dist = RENDER_DIST;
	raycast->distance = 0;
}

// function to throw the rays
// "stop when it hits the wall"
void	ft_raycasting(t_data *data)
{
	int			i;
	double		angle;
	t_raycast	raycast;

	i = 0;
	// calcul langle du rayon par rapport a la dir du player
	while (i < WIDTH)
	{
		angle = data->look - ANGLE / 2 + i * (ANGLE / WIDTH);
		i++;
	}
	// init list raycast
	init_raycasting(&raycast, data, angle);
	// throw the ray
	while (raycast.distance < raycast.max_dist)
	{
		raycast.x += raycast.cos_x * DEPLACEMENT;
		raycast.y += raycast.sin_y * DEPLACEMENT;
		// check if the ray is out of the map
		if (raycast.x < 0 || raycast.x > WIDTH
			|| raycast.y < 0 || raycast.y > HEIGHT)
			break ;
		// the ray incouneter a wall
		if (ft_check_colision(data, raycast.x, raycast.y))
			break ;
		// dislay the ray on the screen
		printf("Ray at angle %.2f hit point (%.2f, %.2f)\n", angle, raycast.x, raycast.y);
		raycast.distance += DEPLACEMENT;
	}
}
int	main(void)
{
	int		map[WIDTH][HEIGHT];
	t_data	data;

	data.look = 20;
	data.xpos = 2;
	data.ypos = 4;

	ft_raycasting(&data);
}