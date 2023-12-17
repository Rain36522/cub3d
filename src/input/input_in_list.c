/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2023/12/17 15:14:00 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static int	put_map_int_tab(t_input *input)
{
	int		i;
	int		len;
	t_list	*tmp;

	tmp = input->map;
	len = len_tab(tmp);
	input->tab_map = malloc(sizeof(char *) * (len + 1));
	if (!input->tab_map)
	{
		init_print_error("Error\ntab map allocation failed\n");
		return (init_free_all_and_exit(input));
	}
	i = 0;
	while (tmp->next != NULL)
	{
		input->tab_map[i] = tmp->str;
		tmp = tmp->next;
		i++;
	}
	input->tab_map[i] = tmp->str;
	input->tab_map[i + 1] = NULL;
	return (0);
}

static int	create_linked_list(t_input *input, int fd, char	*line)
{
	if (only_path(input) == 1)
		return (1);
	if (only_nbr(input) == 1)
		return (1);
	init_separe_colours(input);
	get_trgb(input);
	while (1)
	{
		if (line == NULL)
		{
			free(line);
			break ;
		}
		add_end(&input->map, line, input);
		line = get_next_line(fd);
	}
	return (0);
}

int	free_str_and_null(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (0);
}

static int	input_in_list(t_input *input, int fd, char *line)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line[0] && line[0] == '\n' && line[1] == '\0')
			free_str_and_null(line);
		else if (ft_strnstr(line, "NO", 2) != NULL)
			input->no = line;
		else if (ft_strnstr(line, "SO", 2) != NULL)
			input->so = line;
		else if (ft_strnstr(line, "WE", 2) != NULL)
			input->we = line;
		else if (ft_strnstr(line, "EA", 2) != NULL)
			input->ea = line;
		else if (ft_strnstr(line, "F", 1) != NULL)
			input->f = line;
		else if (ft_strnstr(line, "C", 1) != NULL)
			input->c = line;
		else
		{
			if (create_linked_list(input, fd, line) == 1)
				return (init_free_all_and_exit(input));
			break ;
		}
	}
	return (free_str_and_null(line));
}

// If fuction return NULL => Error was declared
// list has been freed
// And program should be stopped.
t_data	*init_list(char **argv)
{
	t_input	*input;
	t_data	*data;
	char	*line;
	int		fd;

	line = NULL;
	input = malloc(sizeof(t_input));
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{
		init_print_error("Error\nmap opening failed\n");
		return (NULL);
	}
	if (input_in_list(input, fd, line) == 1)
		return (NULL);
	if (put_map_int_tab(input) == 1)
		return (NULL);
	close(fd);
	data = t_input_to_t_data(input);
	clean_list(input->map);
	return (data);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	init_list(argv);
	return (0);
}