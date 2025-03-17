#include "../so_long_bonus.h"

static void    position_war_collect(t_map **slong)
{
    int i;
    int j;
    int d;

    (*slong)->coll = malloc((*slong)->war_collect * sizeof(t_collect));
    if (!(*slong)->coll)
        return ;
    i = -1;
    d = 0;
    while ((*slong)->map[++i])
    {
        j = -1;
        while ((*slong)->map[i][++j])
        {
            if ((*slong)->map[i][j] == 'X')
            {
                (*slong)->coll[d].x_collect = i;
                (*slong)->coll[d].y_collect = j;
                d++;
            }
        }
    }
}

void    put_war_img_aid(t_map **slong, int i)
{
    if ((*slong)->e_var.x == 0)
        mlx_put_image_to_window((*slong)->mlx, (*slong)->mlx_win, (*slong)->images.enemy_1,
            (*slong)->coll[i].y_collect * SIZE, (*slong)->coll[i].x_collect * SIZE);
    else if ((*slong)->e_var.x == 1)
        mlx_put_image_to_window((*slong)->mlx, (*slong)->mlx_win, (*slong)->images.enemy_2,
            (*slong)->coll[i].y_collect * SIZE, (*slong)->coll[i].x_collect * SIZE);
    else if ((*slong)->e_var.x == 2)
        mlx_put_image_to_window((*slong)->mlx, (*slong)->mlx_win, (*slong)->images.enemy_3,
            (*slong)->coll[i].y_collect * SIZE, (*slong)->coll[i].x_collect * SIZE);
}

void    put_war_img(t_map **slong)
{
    int i;

    i = -1;
    while (++i < (*slong)->war_collect)
        put_war_img_aid(slong, i);
}

int animation_collect(t_map **slong)
{
    position_war_collect(slong);
    if (!(*slong)->coll)
        return (1);
    if ((*slong)->e_var.sleep-- <= 0)//2
	{
		(*slong)->e_var.x++;
		(*slong)->e_var.sleep = 5;
	}
	if ((*slong)->e_var.x == 3)//0
		(*slong)->e_var.x = 0;
    put_war_img(slong);
    free((*slong)->coll);
    return (0);
}
