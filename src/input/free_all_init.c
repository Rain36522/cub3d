/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:05:28 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/27 13:24:08 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	destroy_img_texture(t_input *input)
{
	if (input->t_no.addr)
		mlx_destroy_image(input->mlx, input->t_no.img);
	if (input->t_so.addr)
		mlx_destroy_image(input->mlx, input->t_so.img);
	if (input->t_we.addr)
		mlx_destroy_image(input->mlx, input->t_we.img);
	if (input->t_ea.addr)
		mlx_destroy_image(input->mlx, input->t_ea.img);
	if (input->door.addr)
		mlx_destroy_image(input->mlx, input->door.img);
}