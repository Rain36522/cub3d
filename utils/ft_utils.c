/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:24:06 by pudry             #+#    #+#             */
/*   Updated: 2023/12/18 14:33:00 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	ft_put_array(char **a)
{
	int	i;

	if (!a)
	{
		printf("NULL\n");
		return ;
	}
	i = 0;
	while (a[i])
		printf("array : %s\n", a[i ++]);
}

char	*ft_strdup_endl(const char *str)
{
	int		isize;
	int		i;
	char	*dup;

	isize = ft_strlen(str);
	if (ft_strchr(str, '\n'))
		isize --;
	dup = (char *) malloc(isize + 1);
	if (! dup)
		return (NULL);
	dup[isize --] = '\0';
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dup[i] = str[i];
		i ++;
	}
	return (dup);
}