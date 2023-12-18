/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:02:41 by csil              #+#    #+#             */
/*   Updated: 2023/12/17 14:50:53 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

// skip the spaces before dup the str
char	*relay_only(char *str, int i)
{
	while (str[i] && str[i] == 32)
		i++;
	if (str[i])
	{
		str = ft_strdup(str + i);
	}
	return (str);
}