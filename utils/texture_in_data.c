/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_in_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:19:15 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/26 14:34:30 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int		refresh_texture(t_pixput *texture, t_data *data, char *filename)
{
	texture->img =  mlx_xpm_file_to_image(data->mlx, filename, &texture->width, \
		&texture->heigth);
	if (!texture->img)
		return (1);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bit_pp, \
		&texture->line_len, &texture->endian);
	if (!texture->addr)
		return (1);
	return (0);
}

static int	put_texture_in_node(t_pixput *texture, t_input *input, char *name)
{
	texture->img =  mlx_xpm_file_to_image(input->mlx, name, &texture->width, \
		&texture->heigth);
	DEBUG
	ft_put_array(input->tab_map);
	if (!texture->img)
		return (1);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bit_pp, \
		&texture->line_len, &texture->endian);
	if (!texture->addr)
		return (1);
	return (0);
}

int	all_texture_in_data(t_input *input)
{
	if (put_texture_in_node(&input->t_no, input, input->no) == 1)
		return (init_free_all_and_exit(input, 1));
	if (put_texture_in_node(&input->t_so, input, input->so) == 1)
		return (init_free_all_and_exit(input, 1));
	if (put_texture_in_node(&input->t_we, input, input->we) == 1)
		return (init_free_all_and_exit(input, 1));
	if (put_texture_in_node(&input->t_ea, input, input->ea) == 1)
		return (init_free_all_and_exit(input, 1));
	return (0);
}