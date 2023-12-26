/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:30:58 by pudry             #+#    #+#             */
/*   Updated: 2023/12/22 09:30:58 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static int	ft_check_dir_door(int look, t_data *data)
{
	return 0;
}
static void	ft_change_door(t_data *data)
{
	int	l;
	int	r;

	r = (int)ft_calcul_ang(data->look, LOOK_ANGLE / 2);
	l = (int)ft_calcul_ang(data->look, -(LOOK_ANGLE / 2));
	if ((l > 315 || l < 45) || (r > 315 || r < 45))
		if (data->map[(int)data->ypos][(int)data->xpos + 1] == 'D')
			data->map[(int)data->ypos][(int)data->xpos + 1] = '0';
	else if ((l > 45 && l < 135) || (r > 45 && r < 135))
		if (data->map[(int)data->ypos + 1][(int)data->xpos] == 'D')
			data->map[(int)data->ypos + 1][(int)data->xpos] = '0';
	else if ((l > 135 && l < 225) || (r > 135 && r < 225))
		if (data->map[(int)data->ypos][(int)data->xpos - 1] == 'D')
			data->map[(int)data->ypos][(int)data->xpos - 1] = '0';
	else
		if (data->map[(int)data->ypos - 1][(int)data->xpos] == 'D')
			data->map[(int)data->ypos - 1][(int)data->xpos] = '0';
}

static int	ft_check_angle(t_data *data, int keycode)
{
	if (keycode == 123)
		data->look = ft_calcul_ang(data->look, ANGLE * -1);
	else if (keycode == 124)
		data->look = ft_calcul_ang(data->look, ANGLE);
	else if (keycode == 49)
		ft_change_door(data);
	else
		return (0);
	ft_make_moov(data, data->xpos, data->ypos);
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
	data->x = ft_calc_depl_x(iangl) + data->xpos;
	data->y = (ft_calc_depl_y(iangl) + data->ypos);
	if (ft_check_colision(data, data->x, data->y))
		return (0);
	while (data->make_moov == '1')
		continue ;
	data->make_moov = '1';
	return (0);
}

int	ft_press_cross(void)
{
	printf("Exit\n");
	exit(0);
	return (0);
}