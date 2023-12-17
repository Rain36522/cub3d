/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:28:51 by pudry             #+#    #+#             */
/*   Updated: 2023/12/17 10:44:05 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static char	*ft_change_size_line(char *line, int ilen)
{
	int		i;
	char	*new_line;

	new_line = (char *) malloc(sizeof(char) * (ilen + 1));
	if (!new_line)
		return (NULL);
	new_line[ilen] = '\0';
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i ++;
	}
	while (i < ilen)
		new_line[i ++] = ' ';

	return (new_line);
}

static char	**ft_map_equal_line(char **map)
{
	int	i;
	int	ilen;

	i = 0;
	ilen = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > ilen)
			ilen = (ft_strlen(map[i]));
		i ++;
	}
	i = 0;
	while (map[i])
	{
		map[i] = ft_change_size_line(map[i], ilen);
		i ++;
	}
}

t_data *t_input_to_t_data(t_input *input)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = ft_map_equal_line(input->map);
	data->no = input->no;
	data->so = input->so;
	data->ea = input->ea;
	data->we = input->we;
	return (data);
}