/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:47:42 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/21 15:48:56 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// give the trgb top color
// give the trgb bottom color
void	ft_background(t_data *data)
{
	int		i;
	int		j;
	int		icolor;

	i = 0;
	icolor = data->f;
	while (i < HEIGHT)
	{
		if (i == (HEIGHT / 2))
			icolor = data->c;
		j = 0;
		while (j < WIDTH)
			put_pixel_img(data, j ++, i, icolor);
		i++;
	}
}