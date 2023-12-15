/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:12:22 by pudry             #+#    #+#             */
/*   Updated: 2023/12/15 12:12:22 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	print_list(t_list *list)
{
	int	i;

	i = 0;
	while (list->next)
	{
		printf("chaine %d: %s\n", i, list->str);
		i++;
		list = list->next;
	}
	printf("chaine %d: %s\n", i, list->str);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("str %d: %s\n", i, tab[i]);
		i++;
	}
}