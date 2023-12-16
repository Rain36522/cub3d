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
# define MAP_SIZE 70
# define DEPLACEMENT 1.5
# define ANGLE 5
# define DEBUG printf("\033[1;31m%s:%d\n\033[0;37m", __FILE__, __LINE__);

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
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
}				t_input;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	double	xpos;
	double	ypos;
	int		look;
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

// utils mlx
void	ft_put_square(t_data *data, int x, int y, int icolor);
void	put_map(t_data *data);
void	put_player(t_data *data);


// utils calcul
double	ft_calc_depl_x(int iangl);
double	ft_calc_depl_y(int iangl);
int		ft_calcul_ang(int iangl, int iofset);

// key_hook
int		key_hook(int keycode, t_data *data);
int		ft_press_cross(void);

// Init part
void	print_list(t_list *list);
void	print_tab(char **tab);
void	add_end(t_list **list, char *line, t_input *input);
t_list	*ptr_last_node(t_list *list);
int		len_tab(t_list *list);
char	*ft_strdup_free(const char *str);
int		only_path(t_input *input);
int		only_nbr(t_input *input);
int		init_print_error(char *str);
int		init_free_all_and_exit(t_input *input);
int		free_str_and_null(char *str);
int 	only_nbr(t_input *input);
int		only_path(t_input *input);
char	*ft_strndup(const char *str, int isize);
int		not_enough_commas(char *str);
int		other_than_digit(char *str);
int		init_separe_colours(t_input *input);

#endif