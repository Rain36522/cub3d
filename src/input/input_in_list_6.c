/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:16:21 by csil              #+#    #+#             */
/*   Updated: 2024/01/05 09:47:11 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	ft_check_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	clean_list(t_list *list)
{
	t_list	*tmp;

	if (list)
	{
		while (list)
		{
			tmp = list->next;
			free (list);
			list = NULL;
			list = tmp;
		}
		free(list);
		list = NULL;
	}
}

int	check_extension(char *str)
{
	int	len;

	if (!str)
		return (printf("Error\nProblem with map reading."));
	len = ft_strlen(str);
	if (str[len] != '\0')
		return (init_print_error("Error\nWrong extension map file.\n"));
	else if (str[len - 1] != 'b')
		return (init_print_error("Error\nWrong extension map file.\n"));
	else if (str[len - 2] != 'u')
		return (init_print_error("Error\nWrong extension map file.\n"));
	else if (str[len - 3] != 'c')
		return (init_print_error("Error\nWrong extension map file.\n"));
	len = open(str, O_RDONLY);
	if (len < 0)
		return (init_print_error("Error\nMap file failed to open.\n"));
	close(len);
	return (0);
}

int	input_not_full(t_input *input)
{
	if (!input->no)
		return (1);
	else if (!input->so)
		return (1);
	else if (!input->ea)
		return (1);
	else if (!input->we)
		return (1);
	return (0);
}

// If it returns upper thqn zero: free all and exit.
int	check_multiple_input(char *str)
{
	int	fd;
	int	result;

	result = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (printf ("Error\nFailed to open the file."));
	result = check_multiple_input_2(fd, 0, 1);
	close (fd);
	return (result);
}
