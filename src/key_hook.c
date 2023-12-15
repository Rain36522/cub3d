/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:07:44 by pudry             #+#    #+#             */
/*   Updated: 2023/12/15 18:12:09 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static int	ft_check_angle(t_data *data, int keycode)
{
	if (keycode == 123)
		data->look = ft_calcul_ang(data->look, ANGLE);
	else if (keycode == 124)
		data->look = ft_calcul_ang(data->look, ANGLE * -1);
	return (0);
}

// a ajouter :
// pour decaler a droite iangl += 90;
// pour deplacer a gauche iangle -= 90;
// pour deplacer en arriere, iangle += 180;
// 123 / 124 change angle
int	key_hook(int keycode, t_data *data)
{
	int		iangl;

	printf("keycode : %i\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 2)
		iangl = ft_calcul_ang(data->look, 90);
	else if (keycode == 0)
		iangl = ft_calcul_ang(data->look, -90);
	else if (keycode == 126 || keycode == 13)
		iangl = data->look;
	else if (keycode == 125 || keycode == 1)
		iangl = ft_calcul_ang(data->look, -180);
	else
		return (ft_check_angle(data, keycode));
	printf("iangl : %i, x : %f, y : %f\n", iangl, data->xpos, data->ypos);
	data->xpos += ft_calc_depl_x(iangl);
	data->ypos += ft_calc_depl_y(iangl);
	printf("x : %f, y : %f\n", data->xpos, data->ypos);
	put_map(data);
	put_player(data);
	return (0);
}

int	ft_press_cross(void)
{
	printf("Exit\n");
	exit(0);
	return (0);
}