#ifndef SO_LONG_H
#define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <fcntl.h>
#include <unistd.h>

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

    int img_width;
    int img_height;
    int collected;
	int coll_sum;
    int p_count;
    int c_count;
    int e_count;
    void *img_wall;
    void *img_empty;
    void *img_c;
    void *img_p;
    void *img_e;
    int x;
    int y;
    int z;

} t_data;

void draw_map(t_data *data);
int	check_lf_map(t_data *game);
int	check_tb_map(t_data *game);
int	check_all_map(t_data *game);
int	check_objects(t_data *game);
void	check_map(t_data *game);
int count_maplines(char **av);
int mapread(t_data *data,char *av[]);
int check_valid_shape(t_data *data);

#endif