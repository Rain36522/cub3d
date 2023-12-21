/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:05:28 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/21 11:12:42 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	destroy_img_texture(t_input *input)
{
	if (input->t_no.addr)
		mlx_destroy_image(input->t_no.addr, input->t_no.img);
	if (input->t_so.addr)
		mlx_destroy_image(input->t_so.addr, input->t_so.img);
	if (input->t_we.addr)
		mlx_destroy_image(input->t_we.addr, input->t_we.img);
	if (input->t_ea.addr)
		mlx_destroy_image(input->t_ea.addr, input->t_ea.img);
}