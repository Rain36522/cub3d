/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:47:42 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/21 15:32:03 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static void	ft_top(int	i, t_data *data)
{
	int		j;
	while (i < (HEIGHT))
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel_img(data, i, j, data->c);
			j++;
		}
		i++;
	}
}

static void	ft_bottom(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < (HEIGHT / 2))
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel_img(data, i, j, data->f);
			j++;
		}
		i++;
	}
	ft_top(i, data);
}

// give the trgb top color
// give the trgb bottom color
void	ft_background(t_data *data)
{
	ft_bottom(data);
}