#ifndef SO_LONG_H
#define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define ESC_KEY 65307
#define A_KEY 97
#define D_KEY 100
#define S_KEY 115
#define W_KEY 119
#define TOP_KEY 65362
#define BOTTOM_KEY 65364
#define LEFT_KEY 65361
#define RIGHT_KEY 65363

typedef struct s_player
{
	int		h;
	int		v;
}	t_player;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_data{
    void *mlx;
    void *win;
    t_map map;
    t_player myplayer;

    char *img_p_path;
    char *img_c_path;
    char *img_empty_path;
    char *img_exit_path;
    char *img_wall_path;

    int img_width;
    int img_height;
    int collected;
    int move;

    int p_count;
    int c_count;
    int e_count;
    void *img_wall;
    void *img_empty;
    void *img_c;
    void *img_p;
    void *img_e;
    int i;
    int j;

} t_data;

int	check_lr_map(t_data *game);
int	check_tb_map(t_data *game);
int	check_full_map(t_data *game);
int	check_objects(t_data *game);
void	check_valid_map(t_data *game);
int count_ln(char **av);
int read_map(t_data *data,char *av[]);
int check_valid_rec(t_data *data);
int canReachToE(t_data *game,int i, int j);
int canReachToAllC(t_data *game,int i, int j);
void ft_init(t_data *game);
void player_position(int i, int j, t_data *game);
void	ft_mapwall(int i, int j, t_data *game);
void	ft_map_pla(int i, int j, t_data *game);
void	ft_mapcoll(int i, int j, t_data *game);
void	ft_mapexit(int i, int j, t_data *game);
void	ft_map_path(int i, int j, t_data *game);
void	ft_collpos(int i, int j, t_data *game);
int	draw_map(t_data *game);
void	draw_path(t_data *game);
int ft_move(int keycode,t_data *game);
void	ft_sync_map(int x, int y, t_data *game);
int	ft_map_update(int x, int y, t_data *game);
void ft_refresh_game(int i, int j,t_data *game);
void	checkcollectable(t_data *game);
void ft_move_up(t_data *game);
int ft_exit(void);

#endif