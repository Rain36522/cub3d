/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2023/12/21 11:17:55 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free (tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
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

int	init_free_all_and_exit(t_input *input)
{
	if (input->no)
		free_str_and_null(input->no);
	if (input->so)
		free_str_and_null(input->so);
	if (input->we)
		free_str_and_null(input->we);
	if (input->ea)
		free_str_and_null(input->ea);
	if (input->f)
		free_str_and_null(input->f);
	if (input->c)
		free_str_and_null(input->c);
	destroy_img_texture(input);
	clean_list(input->map);
	free_tab(input->tab_map);
	if (input)
	{
		free (input);
		input = NULL;
	}
	return (1);
}

void	add_end(t_list **list, char *line, t_input *input)
{
	t_list	*tmp;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		printf ("Error\nlist allocation failed\n");
		init_free_all_and_exit(input);
	}
	new_node->str = line;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	tmp = ptr_last_node(*list);
	tmp->next = new_node;
}

int	init_print_error(char *str)
{
	printf ("%s", str);
	return (1);
}