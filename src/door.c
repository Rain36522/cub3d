#include "../Includes/cub3d.h"

static void	ft_door(t_data *data, int y, int x)
{
	// printf("check char : %c pos : %i, %i\n", data->map[y][x], y, x);
	if (data->map[y][x] == 'D' && data->cdvalue == 'E')
	{
		data->map[y][x] = 'E';
		printf("change to E\n");
	}
	else if (data->map[y][x] == 'E' && data->cdvalue == 'D')
	{
		data->map[y][x] = 'D';
		printf("change to D\n");
	}
	data->dchanged ++;
	usleep(300);
}
void	ft_change_door(t_data *data)
{
	int	l;
	int	r;

	r = (int)ft_calcul_ang(data->look, LOOK_ANGLE / 2);
	l = (int)ft_calcul_ang(data->look, -(LOOK_ANGLE / 2));
	if ((l > 315 || l < 45) || (r > 315 || r < 45))
		ft_door(data, (int)data->ypos, (int)data->xpos + 1);
	if ((l > 45 && l < 135) || (r > 45 && r < 135))
		ft_door(data, (int)data->ypos + 1, (int)data->xpos);
	if ((l > 135 && l < 225) || (r > 135 && r < 225))
		ft_door(data, (int)data->ypos, (int)data->xpos - 1);
	if ((l > 225 && l < 315) || (r > 135 && r < 225))
		ft_door(data, (int)data->ypos - 1, (int)data->xpos);
}

void	ft_check_door2(t_data *data, int y, int x)
{
	// printf("check cha r : %c pos : %i, %i\n", data->map[y][x], y, x);
	if (data->map[y][x] == 'D')
	{
		data->dstep = -2;
		data->dvalue = 98;
	}
	else if (data->map[y][x] == 'E')
	{
		data->dstep = 2;
		data->dvalue = 2;
	}
}
void	ft_check_door(t_data *data)
{
	int	l;
	int	r;

	r = (int)ft_calcul_ang(data->look, LOOK_ANGLE / 2);
	l = (int)ft_calcul_ang(data->look, -(LOOK_ANGLE / 2));
	if ((l > 315 || l < 45) || (r > 315 || r < 45))
		ft_check_door2(data, (int)data->ypos, (int)data->xpos + 1);
	if ((l > 45 && l < 135) || (r > 45 && r < 135))
		ft_check_door2(data, (int)data->ypos + 1, (int)data->xpos);
	if ((l > 135 && l < 225) || (r > 135 && r < 225))
		ft_check_door2(data, (int)data->ypos, (int)data->xpos - 1);
	if ((l > 225 && l < 315) || (r > 135 && r < 225))
		ft_check_door2(data, (int)data->ypos - 1, (int)data->xpos);
}
