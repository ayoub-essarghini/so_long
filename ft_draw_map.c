#include "so_long.h"

void draw_map(t_data *data)
{
    (void) data;
    char *line = NULL;
    int fd;
    int img_width;
    int img_height;
    void *wall_img;
    void *grass_img;

    wall_img = mlx_xpm_file_to_image(data->mlx,"textures/wall.xpm",&img_width,&img_height);
    grass_img = mlx_xpm_file_to_image(data->mlx,"textures/grass.xpm",&img_width,&img_height);
    fd = open("maps/map.ber",O_RDONLY);
    if (fd < 0)
        ft_printf("Error to open file descriptor");
    int y = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        int x = 0;
       
       while (*line)
       {
            if (*line == '1')
                mlx_put_image_to_window(data->mlx,data->win,wall_img,x,y);
            else if (*line == '0')
                mlx_put_image_to_window(data->mlx,data->win,grass_img,x ,y);
        line++;
        x += 40;
         
       }
       y += 40;
        
    }
    close(fd);
}