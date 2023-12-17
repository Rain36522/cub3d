/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2023/12/17 15:10:53 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// function that return in int
// the value of trgb in one
static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// function that get trgb of C and F
void	get_trgb(t_input *input)
{
	input->color_floor = create_trgb(0, input->f_r, input->f_g, input->f_b);
	input->color_ceiling = create_trgb(0, input->c_r, input->c_g, input->c_b);
}
