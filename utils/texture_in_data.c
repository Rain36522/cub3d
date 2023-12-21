/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_in_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:19:15 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/21 10:28:32 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static t_pixput	put_texture_in_node(t_pixput texture, t_data *data)
{
	texture.img =  mlx_xpm_file_to_image(data->mlx, data->no, &texture.width, \
		&texture.heigth);
	texture.addr = mlx_get_data_addr(texture.img, &texture.bit_pp, \
		&texture.line_len, &texture.endian);
	return (texture);
}

void	all_texture_in_data(t_data *data)
{
	data->t_no = put_texture_in_node(data->t_no, data);
	data->t_so = put_texture_in_node(data->t_so, data);
	data->t_we = put_texture_in_node(data->t_we, data);
	data->t_ea = put_texture_in_node(data->t_ea, data);
}