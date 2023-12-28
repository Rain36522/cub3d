/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2023/12/28 22:36:08 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// skip the spaces before dup the str
char	*relay_only(char *str, int i)
{
	char	*dup;

	while (str[i] && str[i] == 32)
		i++;
	if (str[i])
	{
		dup = ft_strdup(str + i);
		free(str);
		str = NULL;
		return (dup);
	}
	return (str);
}

void	init_to_null(t_input *input)
{
	input->map = NULL;
	input->tab_map = NULL;
	input->t_we.addr = NULL;
	input->t_ea.addr = NULL;
	input->t_no.addr = NULL;
	input->t_no.addr = NULL;
	input->t_so.img = NULL;
	input->t_we.img = NULL;
	input->t_ea.img = NULL;
	input->t_no.img = NULL;
}
