/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:24:50 by pudry             #+#    #+#             */
/*   Updated: 2023/12/18 11:24:50 by pudry            ###   ########.ch       */
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
# define MAP_SIZE 100
# define PLAYER_SIZE 20
# define DEPLACEMENT 0.4
# define ANGLE 15
# define PI 3.141592653589793
# define DEBUG printf("\033[1;31m%s:%d\033[0;37m\n", __FILE__, __LINE__);

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

typedef struct s_pixput
{
	void	*img;
	char	*addr;
	int		bit_pp;
	int		line_len;
	int		endian;
}	t_pixput;

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
	int		color_ceiling;
	int		color_floor;
}			t_input;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	double		xpos;
	double		ypos;
	int			look;
	char		**map;
	int			ix;
	int			iy;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f;
	int			c;
	t_pixput	img;
}	t_data;

void	print_list(t_list *list);
void	print_tab(char **tab);

// utils mlx
void	ft_put_square(t_data *data, int x, int y, int icolor);
void	ft_make_moov(t_data *data, double x, double y);
void	ft_new_img(t_data *data);
void	put_pixel_img(t_data *data, int x, int y, int icolor);


// utils calcul
double	ft_calc_depl_x(int iangl);
double	ft_calc_depl_y(int iangl);
int		ft_calcul_ang(int iangl, int iofset);
int		ft_check_colision(t_data *data, double x, double y);

// key_hook
int		key_hook(int keycode, t_data *data);
int		ft_press_cross(void);

// Init part
void	print_list(t_list *list);
void	print_tab(char **tab);
void	add_end(t_list **list, char *line, t_input *input);
t_list	*ptr_last_node(t_list *list);
int		len_tab(t_list *list);
char	*ft_strdup_free(char *str);
int		only_path(t_input *input);
int		only_nbr(t_input *input);
int		init_print_error(char *str);
int		init_free_all_and_exit(t_input *input);
int		free_str_and_null(char *str);
int		only_nbr(t_input *input);
int		only_path(t_input *input);
char	*ft_strndup(const char *str, int isize);
int		not_enough_commas(char *str);
int		other_than_digit(char *str);
int		init_separe_colours(t_input *input);
t_data	*t_input_to_t_data(t_input *input);
void	free_tab(char **tab);
char	*relay_only(char *str, int i);
void	clean_list(t_list *list);

t_data	*init_list(char **argv);

// RGB part
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void	get_trgb(t_input *input);


int		ft_check_map(char **map);

// Err
void	ft_error_quit(t_data *data, int icode);

// Utils
char	*ft_strdup_endl(char *str);
void	ft_put_array(char **a);

#endif