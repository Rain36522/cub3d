/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:08:43 by pudry             #+#    #+#             */
/*   Updated: 2023/12/17 20:25:58 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static int	ft_check_angle(t_data *data, int keycode)
{
	if (keycode == 123)
		data->look = ft_calcul_ang(data->look, ANGLE * -1);
	else if (keycode == 124)
		data->look = ft_calcul_ang(data->look, ANGLE);
	else
		return (0);
	ft_make_moov(data, data->xpos, data->ypos);
	printf("iangl : %2f\n", data->look);
	return (0);
}

// a ajouter :
// pour decaler a droite iangl += 90;
// pour deplacer a gauche iangle -= 90;
// pour deplacer en arriere, iangle += 180;
// 123 / 124 change angle
int	key_hook(int keycode, t_data *data)
{
	double	iangl;
	double	x;
	double	y;

	printf("keycode : %i\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 13 || keycode == 126)
		iangl = data->look;
	else if (keycode == 1 || keycode ==  125)
		iangl = ft_calcul_ang(data->look, 180);
	else if (keycode == 0)
		iangl = ft_calcul_ang(data->look, -90);
	else if (keycode == 2)
		iangl = ft_calcul_ang(data->look, 90);
	else
		return (ft_check_angle(data, keycode));
	x = ft_calc_depl_x(iangl) + data->xpos;
	y = (ft_calc_depl_y(iangl) + data->ypos);
	if (ft_check_colision(data, x, y))
		return (0);
	ft_make_moov(data, x, y);
	printf("iangl : %2f\n", data->look);
	return (0);
}

int	ft_press_cross(void)
{
	printf("Exit\n");
	exit(0);
	return (0);
}