/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:20:05 by pudry             #+#    #+#             */
/*   Updated: 2023/12/15 12:20:05 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int		len_tab(t_input *input)
{
	int		len;

	len = 0;
	while (input->map->next != NULL)
	{
		input->map = input->map->next;
		len++;
	}
	return (len);
}

void	put_map_int_tab(t_input *input)
{
	int		i;
	int		len;

	len = len_tab(input);
	input->tab_map = malloc(sizeof(char *) * (len + 1));
	if (!input->tab_map)
	{
		// exit error func
		return ;
	}
	i = 0;
	while (input->map->next != NULL)
	{
		input->tab_map[i] = input->map->str;
		input->map = input->map->next;
		i++;
	}
	input->tab_map[i] = input->map->str;
	input->tab_map[i + 1] = NULL;
}

void	create_tab(t_input *input, int fd)
{
	char	*line;

	line = NULL;
	input->map = malloc(sizeof(t_list));
	if (!input->map)
	{
		printf ("Erreur alloation map list\n");
		return ;
	}
	input->map->str = line;
	input->map = input->map->next;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free (line);
			line = NULL;
			input->map = NULL;
			break ;
		}
		input->map = malloc(sizeof(t_list));
		input->map->str = line;
		printf ("la ligne: %s\n", input->map->str = line);
		input->map = input->map->next;
	}
	input->map = NULL;
}

void	input_in_list(t_input *input, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line[0] == '\n' && line[1] == '\0')
		{
			free (line);
			line = NULL;
		}
		else if (!input->no)
			input->no = line;
		else if (!input->so)
			input->so = line;
		else if (!input->we)
			input->we = line;
		else if (!input->ea)
			input->ea = line;
		else if (!input->f)
			input->f = line;
		else if (!input->c)
			input->c = line;
		else
		{
			create_tab(input, fd);
			break ;
		}
	}
	if (line)
	{
		free (line);
		line = NULL;
	}
	print_list(input->map);
}

void	init_list(char **argv)
{
	t_input	input;
	int		fd;

	input = (t_input){};
	fd = open(argv[1], O_RDWR);
	// put an exit error func
	if (fd < 0)
	{
		printf ("error map opening\n");
		return ;
	}
	input_in_list(&input, fd);
	//put_map_int_tab(&input);
	close(fd);
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	(void) argv;
// 	init_list(argv);
// 	return (0);
// }
