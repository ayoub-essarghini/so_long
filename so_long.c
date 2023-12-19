#include "minilibx-linux/mlx.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800
#define CELL_SIZE 40

typedef struct s_data {
    void *mlx;
    void *win;
    char *img_data_red;
    char *img_data_green;
} t_data;

char *map[] = {
    "1111111111111",
    "10010000000C1",
    "1000011111001",
    "1P0011E000001",
    "1111111111111"
};

void draw_tile(void *mlx_ptr, void *win_ptr, int x, int y, int width,int height, int color) {
    int i = 0;
    int j = 0;
    while(i < height) {
        while(j < width) {
            mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
             j++;
        }
         i++;
    }
}


void draw_map(void *mlx_ptr, void *win_ptr) {
    int x, y;
    int tile_size = 40; // Adjust this based on your preference for tile size

    x =0;
    y = 0;

    while ( y < HEIGHT ) {
         
        while (x < WIDTH ) {
           int color;
            switch (map[y][x]) {
                case '0':
                    color = 0x00FF00; // Green for empty space
                    break;
                case '1':
                    color = 0x000FF0; // Black for wall
                    break;
                case 'C':
                    color = 0xFFFF00; // Yellow for collectable object
                    break;
                case 'E':
                    color = 0xFF0000; // Red for exit port
                    break;
                case 'P':
                    color = 0x0000FF; // Blue for player position
                    break;
                default:
                    color = 0xFFFFFF; // White for other cases
             
            }

                       draw_tile(mlx_ptr, win_ptr, x * tile_size, y * tile_size, tile_size,tile_size, color);
               x++;
        }
           y++;
    }
}



int main() {
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx) {
        fprintf(stderr, "Error initializing MiniLibX\n");
        return 1;
    }
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "SO_LONG");
    if (!data.win) {
        fprintf(stderr, "Error creating window\n");
        return 1;
    }
    // char *line;
    // int fd;

    // fd = open("maps/map1.ber", O_RDONLY);

    // if (fd < 0)
    //     return (0);

     draw_map(data.mlx, data.win);

    // close(fd);

    mlx_loop(data.mlx);

    return (0);
}
