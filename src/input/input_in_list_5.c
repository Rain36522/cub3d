/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <cduffaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2024/01/05 09:17:30 by cduffaut         ###   ########.fr       */
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

void	init_to_null(t_input *input, char *str)
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
	input->no = NULL;
	input->so = NULL;
	input->we = NULL;
	input->ea = NULL;
	check_multiple_input(str);
}
