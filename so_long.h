/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:53:43 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 01:53:55 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include "mlx.h"

# define SIZE 60
# define WALL "image/Wall.xpm"
# define SPACE "image/Space.xpm"
# define PMAN_R "image/jerry_right.xpm"
# define PMAN_L "image/jerry_left.xpm"
# define PMAN_U "image/jerry_right.xpm"
# define PMAN_D "image/jerry_left.xpm"
# define ODOOR "image/Open_Door.xpm"
# define CDOOR "image/Close_Door.xpm"
# define COLLECT "image/Collect.xpm"

typedef struct s_img
{
	void	*space;
	void	*wall;
	void	*collect;
	void	*player_up;
	void	*player_down;
	void	*player_right;
	void	*player_left;
	void	*exit_open;
	void	*exit_close;
}t_img;

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	t_img	images;
	char	**map;
	int		collect;
	int		h_map;
	int		w_map;
	int		x_p;
	int		y_p;
	int		x_e;
	int		y_e;
	int		move;
}	t_map;

// free
void	fr_stack(t_map *slong);
void	free_double(char **str);
void	free_image(t_map *slong);

// copy map
char	**copy_map(char **map);

// position enemy
bool	get_enemy_position(t_map **slong);

// handle error
bool	handl_close(char **map);
bool	handl_error(t_map **slong);

// put image
bool	put_image(t_map *slong);
void	ft_ft(t_map *slong);

// event
int		ft_hook(int prees, t_map **slong);
int		ft_exit(t_map *slong);

#endif
