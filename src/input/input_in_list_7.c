/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:16:21 by csil              #+#    #+#             */
/*   Updated: 2024/01/05 10:20:19 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// Counter should be at 0, nbr at 1.
int	check_multiple_input_2(int fd, int counter)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen(line) > 1 && !ft_strncmp(line, "SO", 2))
			counter++;
		else if (ft_strlen(line) > 1 && !ft_strncmp(line, "NO", 2))
			counter++;
		else if (ft_strlen(line) > 1 && !ft_strncmp(line, "WE", 2))
			counter++;
		else if (ft_strlen(line) > 1 && !ft_strncmp(line, "EA", 2))
			counter++;
		else if (line && !ft_strncmp(line, "F", 1))
			counter++;
		else if (line && !ft_strncmp(line, "C", 1))
			counter++;
		free (line);
		line = get_next_line(fd);
	}
	free_str_and_null(line);
	if (counter > 6)
		return (printf ("Error\nWrong number of arguments in map.\n"));
	return (0);
}
