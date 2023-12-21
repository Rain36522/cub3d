/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_in_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:19:15 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/21 10:52:27 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// lets see where the fuck and how mlx is init
static t_pixput	put_texture_in_node(t_pixput texture, t_input *input, char *name)
{
	texture.img =  mlx_xpm_file_to_image(input->mlx, name, &texture.width, \
		&texture.heigth);
	texture.addr = mlx_get_data_addr(texture.img, &texture.bit_pp, \
		&texture.line_len, &texture.endian);
	return (texture);
}

void	all_texture_in_data(t_input *input)
{
	input->t_no = put_texture_in_node(input->t_no, input, input->no);
	input->t_so = put_texture_in_node(input->t_so, input, input->so);
	input->t_we = put_texture_in_node(input->t_we, input, input->we);
	input->t_ea = put_texture_in_node(input->t_ea, input, input->ea);
}