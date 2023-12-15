/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:39:02 by pudry             #+#    #+#             */
/*   Updated: 2023/12/15 12:39:02 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <math.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 980

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

typedef struct s_input
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	t_list	*map;
	char	**tab_map;
}				t_input;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	double	xpos;
	double	ypos;
	double	look;
	char	**map;
	int		ix;
	int		iy;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
}	t_data;

void	print_list(t_list *list);
void	print_tab(char **tab);

#endif