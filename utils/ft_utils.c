/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:24:06 by pudry             #+#    #+#             */
/*   Updated: 2023/12/18 15:45:29 by pudry            ###   ########.fr       */
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
		printf("array : %s|\n", a[i ++]);
}

char	*ft_strdup_endl(char *str)
{ 
	int		isize;
	int		i;
	char	*dup;

	if (!str)
		return (NULL);
	isize = ft_strlen(str);
	if (ft_strchr(str, '\n'))
		isize --;
	if (str[0] == '\n' && str[1] == '\0')
		return (str);
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
	free (str);
	str = NULL;
	return (dup);
}