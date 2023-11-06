/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:19:08 by haze              #+#    #+#             */
/*   Updated: 2023/11/04 13:40:45 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include "../MLX42-C/include/MLX42/MLX42.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (10)
# endif
# ifndef WIDTH
#  define WIDTH 640
# endif
# ifndef HEIGHT
#  define HEIGHT 640
# endif
# ifndef  MAPS
#  define MAPS 64
# endif
# ifndef PI
#  define PI 3.1415926535
# endif
# ifndef P2
#  define P2 1.57079632675
# endif
# ifndef P3
#  define P3 4.71238898038
# endif
// Structure for parsing the .cub
typedef struct s_verification
{
	int				nb_arg;
	int				h;
	int				i;
	int				j;
	int				bin_j;
	int				parametres;
	int				bool_color;
	int				z;
	int				d;
	int				c;
	int				size;
	int				boolean;
	int				incr;
	int				max_y;
	int				max_x;
	int				tab_gestion[6];
	char			**map;
	char			*argv;
	char			**color;
	mlx_texture_t	*texture;
	char			**binary_map;
	char			*north_texture;
	char			*west_texture;
	char			*east_texture;
	char			*south_texture;
	char			orientation;
	int				size_map_x;
	int				size_map_y;
	int				player_x;
	int				player_y;
	int				red_floor;
	int				green_floor;
	int				blue_floor;
	int				red_ceiling;
	int				green_ceiling;
	int				blue_ceiling;
	int				y;
	int				a;
	int				g;
	int				line_off;
	int				r;
	int				mx;
	int				my;
	int				mp;
	int				dof;
	int				raynb;
	int				ca;
	int				line_h;
	int				map_x;
	int				map_y;
	float			px;
	float			py;
	float			tx;
	float			ty;
	float			ty_off;
	float			ty_step;
	float			vx;
	float			vy;
	float			rx;
	float			ry;
	float			ra;
	float			xo;
	float			yo;
	float			dis_v;
	float			dis_h;
	float			tan;
	float			pdx;
	float			pdy;
	float			pa;
	char			p_dir;
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	mlx_image_t		*l_img;
	mlx_image_t		*f_img;
	mlx_texture_t	*twe;
	mlx_texture_t	*tea;
	mlx_texture_t	*tno;
	mlx_texture_t	*tso;
	mlx_texture_t	*t;
}					t_verification;

void	draw_rays(t_verification *pars);
int		get_rgba(int r, int g, int b, int a);
int		pixel_to_color(uint32_t x, uint32_t y, t_verification *pars);
void	quit(t_verification *pars);
int		fix_ang(int a);
float	deg_to_rad(int a);
void	floor_ceiling(t_verification *pars);
void	load_player(t_verification *pars);
void	display_line(t_verification *pars);
void	import_textures(t_verification *pars);
void	spawn_look(t_verification *pars);
void	graph(t_verification *pars);
void	vertical_line(t_verification *pars);
void	horizontal_line(t_verification *pars);
void	draw_rays_bis(t_verification *pars);
void	draw_rays_ter(t_verification *pars);
void	r_l_move(t_verification *pars);
void	a_w_s_d_move(t_verification *pars);
//--------------------
// ft_parsing.c
int		ft_valid_extension(int nb_arg, char *argv, t_verification *pars);
int		ft_size_file_cub_heigth(char *argv, t_verification *pars);
int		ft_size_file_cub_length(char *argv, t_verification *pars);
int		ft_all_verification(t_verification *pars, char *argv, int nb_arg);
int		ft_verif_if_elem_first(char **map, t_verification *pars, char *argv);
//--------------------
// ft_parsing_alloc.c
char	**ft_allocation_char_map(char *argv, t_verification *pars);
char	**ft_allocation_char_map_bin(char *argv, t_verification *pars);
char	**ft_allocation_remp_map(t_verification *pars, char *argv);
char	**ft_allocation_remp_binary(t_verification *pars, char *argv);
int		alloc_totale(char *argv, t_verification *pars);
//--------------------
//ft_parsing_verif_elements
int		ft_verif_n_s_e_w_f_c(char **map, t_verification *pars, char *argv);
//--------------------
//ft_parsing_verif_elements_solo
void	ft_verif_north(char **map, t_verification *pars, char *argv);
void	ft_verif_west(char **map, t_verification *pars, char *argv);
void	ft_verif_east(char **map, t_verification *pars, char *argv);
void	ft_verif_south(char **map, t_verification *pars, char *argv);
void	ft_verif_floor(char **map, t_verification *pars, char *argv);
//--------------------
//ft_parsing_verif_elements_solo_bis
int		ft_verif_floor_bis(char **map, t_verification *pars, char *argv);
void	ft_verif_all_elements(t_verification *pars, char *argv);
void	ft_verif_ceiling(char **map, t_verification *pars, char *argv);
int		ft_verif_ceiling_bis(char **map, t_verification *pars, char *argv);
int		verif_number(long long int number);
//--------------------
// ft_utils.c
int		ft_strncmp(const char *s1, const char *s2);
int		ft_error_return(int v, t_verification *pars, char *argv, int p);
char	**ft_char_error_return(int v, t_verification *pars, char *argv, int p);
char	**ft_free_malloc(char **tab, int pos);
char	*ft_strdup(char *source);
char	*ft_strdup_bis(char *source);
//--------------------
// ft_utils_bis.c
int		ft_initialisation_var_struc(t_verification *pars);
int		ft_free_initialisation(t_verification *pars, char *argv, int p);
int		ft_final_free(t_verification *pars, char *argv);
int		ft_atoi(const char *thestring);
int		ft_isdigit_str(char *str);
//--------------------
// ft_getnextline.c
char	*get_next_line(int fd);
char	*ft_reading_file(int fd, char *old_string);
char	*ft_strcopy_new(char *s);
char	*ft_clear_old(char *s);
int		ft_comp(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
//--------------------
// ft_parsing_verif_map_texture.c
void	ft_verif_map_elements(char **map, t_verification *pars, char *argv);
void	ft_verif_texture(t_verification *pars, char *argv);
void	positon_player(t_verification *pars);
void	verif_map_compact(char **map, t_verification *pars, char *argv);
// ft_parsing_flood_fill.c
void	ft_recursive_flood(char **tab, int px, int py, t_verification *pars);
int		ft_verification_flood_fill(t_verification *pars);
void	reinitialisation_map(t_verification *pars);
//-----------------------
// ft_split.c
char	**ft_split(char const *s, char c);
char	**ft_free_split(char **tab, int pos);
//------------------------------
// ft_parsing_utils.c.c
void	lecture(char **map, t_verification *pars);
void	ft_verif_if_elem_first_bis(char **map, t_verification *pars);
int		ft_free_initialisation_bis(t_verification *pars, char *argv);
char	*ft_strdup_modifed(char *source, t_verification *pars);
int		ft_atoi_bis(const char *thestring, int valeur, int moins, int i);
//------------------------------*
#endif
