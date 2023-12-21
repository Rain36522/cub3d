/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_in_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:19:15 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/21 10:20:06 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static void	put_texture_in_node(t_pixput *texture, t_data *data)
{
	texture->img =  mlx_xpm_file_to_image(data->mlx, data->no, &texture->width, \
		&texture->heigth);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bit_pp, \
		&texture->line_len, &texture->endian);
}

void	all_texture_in_data(t_data *data)
{
	put_texture_in_node(data->t_no, data);
	put_texture_in_node(data->t_so, data);
	put_texture_in_node(data->t_we, data);
	put_texture_in_node(data->t_ea, data);
}