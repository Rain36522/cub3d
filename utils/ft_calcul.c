/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:56:18 by pudry             #+#    #+#             */
/*   Updated: 2023/12/16 23:00:59 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static double	deg_to_rad(int deg)
{
	return (((double)deg * 2 * PI) / 360);	
}

double	ft_calc_depl_x(int iangl)
{
	int		icadran;
	double	imv;

	if (iangl == 0 || iangl == 180)
		return (0);
	else if (iangl == 270)
		return (DEPLACEMENT);
	else if (iangl == 90)
		return (DEPLACEMENT * -1);
	icadran  = 0;
	if (iangl > 90 && iangl < 180)
		icadran = 1;
	else if (iangl > 180 && iangl < 270)
		icadran = 2;
	else if (iangl > 270)
		icadran = 3;
	iangl = iangl - (90 * icadran);
	if (icadran == 1 || icadran  == 3)
		imv = cos(deg_to_rad(iangl)) * DEPLACEMENT;
	else
		imv = sin(deg_to_rad(iangl)) * DEPLACEMENT;
	if (icadran > 1)
		return (imv * -1);
	return (imv);
}

double	ft_calc_depl_y(int iangl)
{
	int		icadran;
	double	imv;

	if (iangl == 90 || iangl == 270)
		return (0);
	else if (iangl == 180)
		return (DEPLACEMENT);
	else if (iangl == 0)
		return (DEPLACEMENT * -1);
	icadran  = 0;
	if (iangl > 90 && iangl < 180)
		icadran = 1;
	else if (iangl > 180 && iangl < 270)
		icadran = 2;
	else if (iangl > 270)
		icadran = 3;
	iangl = iangl - (90 * icadran);
	if (icadran == 0 || icadran  == 2)
		imv = cos(deg_to_rad(iangl)) * DEPLACEMENT;
	else
		imv = sin(deg_to_rad(iangl)) * DEPLACEMENT;
	printf("ymv : %f\n", imv);
	if (icadran == 0 || icadran == 3)
		return (imv * -1);
	printf("ymv : %f\n", imv);
	return (imv);
}

int	ft_calcul_ang(int iangl, int iofset)
{
	iangl += iofset;
	if (iangl < 0)
		return (360 - (iangl * -1));
	else if (iangl >= 360)
		return (iangl - 360);
	return (iangl);
}
