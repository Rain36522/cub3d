/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:16:21 by csil              #+#    #+#             */
/*   Updated: 2024/01/05 09:18:43 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// Counter should be at 0, nbr at 1.
int	check_multiple_input_2(int fd, int counter, int nbr)
{
	char	*line;

	while (nbr > 0)
	{
		nbr = read(fd, line, BUFFER_SIZE);
		if (!strncmp(line, "SO", 2))
			counter++;
		else if (!strncmp(line, "NO", 2))
			counter++;
		else if (!strncmp(line, "WE", 2))
			counter++;
		else if (!strncmp(line, "EA", 2))
			counter++;
		else if (!strncmp(line, "F", 1))
			counter++;
		else if (!strncmp(line, "C", 1))
			counter++;
	}
	if (counter > 6)
		return (printf ("Error\nWrong number of arguments in map.\n"));
	return (0);
}