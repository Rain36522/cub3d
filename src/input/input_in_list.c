/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:30:30 by pudry             #+#    #+#             */
/*   Updated: 2023/12/18 11:30:30 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// static void	ft_putstr_endl(char *str)
// {
// 	printf("put line : ");
// 	while (*str)
// 	{
// 		if (*str == '\n')
// 			ft_putchar_fd('?', 1);
// 		else
// 			ft_putchar_fd(*str, 1);
// 		str ++;
// 	}
// 	ft_putchar_fd('\n', 1);
// }

static int	put_map_int_tab(t_input *input)
{
	int		i;
	int		len;
	t_list	*tmp;

	tmp = input->map;
	len = len_tab(tmp) + 1;
	input->tab_map = malloc(sizeof(char *) * (len + 1));
	if (!input->tab_map)
	{
		init_print_error("Error\ntab map allocation failed\n");
		return (init_free_all_and_exit(input));
	}
	input->tab_map[len] = NULL;
	i = 0;
	while (tmp != NULL && i < len)
	{
		input->tab_map[i] = tmp->str;
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static int	create_linked_list(t_input *input, int fd, char	*line)
{
	if (only_path(input) == 1)
		return (1);
	if (only_nbr(input) == 1)
		return (1);
	if (init_separe_colours(input) == 1)
		return (1);
	get_trgb(input);
	while (line)
	{
		line = ft_strdup_free(line);
		if (!*line || (line[0] == '\n' && line[1] == '\0'))
			free_str_and_null(line);
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
		if (line && line[0] && line[0] == '\n' && line[1] == '\0')
			free_str_and_null(line);
		else if (!ft_strncmp(line, "NO ", 3))
			input->no = ft_strdup_endl(line);
		else if (!ft_strncmp(line, "SO ", 3))
			input->so = ft_strdup_endl(line);
		else if (!ft_strncmp(line, "WE ", 3))
			input->we = ft_strdup_endl(line);
		else if (!ft_strncmp(line, "EA ", 3))
			input->ea = ft_strdup_endl(line);
		else if (!ft_strncmp(line, "F ", 2))
			input->f = ft_strdup_endl(line);
		else if (!ft_strncmp(line, "C ", 2))
			input->c = ft_strdup_endl(line);
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
	t_data	*data = NULL;
	char	*line;
	int		fd;

	line = NULL;
	input = malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->mlx = mlx_init();
	init_to_null(input);
	fd = open(argv[1], O_RDONLY);
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
	ft_put_array(input->tab_map);
	data = t_input_to_t_data(input);
	init_free_all_and_exit(input);
	printf("end parsing\n");
	return (data);
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	(void) argv;
// 	init_list(argv);
// 	return (0);
// }
