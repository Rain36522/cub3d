/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit_prog.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:31:20 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/26 13:43:34 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static void	free_pixput(t_data *data)
{
	if (data->no.addr)
		free (data->no.addr);
	if (data->so.addr)
		free (data->so.addr);
	if (data->we.addr)
		free (data->we.addr);
	if (data->ea.addr)
		free (data->ea.addr);
}

// Free and exit data struct and all the allocation made from
// The beggining
void	free_and_exit_prog(t_data *data)
{
	if (data)
	{
		if (data->map)
			free_tab(data->map);
		free_pixput(data);
		// if (data->f)
		// 	free_str_and_null(data->f);
		// if (data->c)
		// 	free_str_and_null(data->c);
		if (data->img.addr)
			free_str_and_null(data->img.addr);
		free (data);
		data = NULL;	
	}
}