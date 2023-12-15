/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:54:22 by csil              #+#    #+#             */
/*   Updated: 2023/12/15 16:06:07 by pudry            ###   ########.fr       */
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