/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:03:02 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/06 17:30:30 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define ESC_KEY 65307
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115
# define W_KEY 119

typedef struct s_player
{
	int	h;
	int	v;
}	t_player;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	myplayer;
	char		*img_p_path;
	char		*img_exit_path;
	int			img_width;
	int			img_height;
	int			collected;
	int			move;
	int			p_count;
	int			c_count;
	int			e_count;
	void		*img_wall;
	void		*img_empty;
	void		*img_c;
	void		*img_p;
	void		*img_e;
	int			i;
	int			j;
}	t_data;

int		check_lr_map(t_data *game);
int		check_tb_map(t_data *game);
int		check_full_map(t_data *game);
int		check_objects(t_data *game);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
void	check_valid_map(t_data *game);
void	allocate_and_free_temp(t_data *game, int nbr_lines, char *temp);
void	*ft_memset(void *b, int c, size_t len);
int		read_map(t_data *data, char *av[]);
int		check_valid_rec(t_data *data);
int		can_reach_e(t_data *game, char **map, int i, int j);
int		can_reach_to_all_c(t_data *game, char **map, int i, int j);
void	ft_init(t_data *game);
void	free_maps(char **map1, char **map2);
void	player_position(int i, int j, t_data *game);
void	ft_mapwall(int i, int j, t_data *game);
void	ft_map_pla(int i, int j, t_data *game);
void	ft_mapcoll(int i, int j, t_data *game);
void	ft_mapexit(int i, int j, t_data *game);
void	ft_map_path(int i, int j, t_data *game);
void	ft_collpos(int i, int j, t_data *game);
int		draw_map(t_data *game);
void	draw_path(t_data *game);
char	**map_dup(char **map, int len);
int		ft_move(int keycode, t_data *game);
void	ft_sync_map(int x, int y, t_data *game);
int		ft_map_update(int x, int y, t_data *game);
void	ft_refresh_game(int i, int j, t_data *game);
char	**ft_free(char **s, int j);
int		count_words(char const *s, char c);
char	*ft_word(const char *str, int start, int end);
char	**ft_sep_word(const char *str, char c, int l);
char	**ft_split(char const *s, char c);
int		is_valid_map(char *str);
void	checkcollectable(t_data *game);
void	ft_move_up(t_data *game);
void	get_p_position(t_data *game);
char	*ft_strdup(char *s);
void	have_access_e(t_data *game, char **map1, int k, int l);
void	have_access_c(t_data *game, char **map2, int a, int b);
int		ft_exit(void);
#endif
