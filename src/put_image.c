/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:42:38 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 18:15:26 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	img_put(t_map *slong, void *type, int i, int j)
{
	mlx_put_image_to_window(slong->mlx, slong->mlx_win,
		type, j * SIZE, i * SIZE);
}

static void	aid_put_image(t_map *slong, int i, int j)
{
	if (slong->map[i][j] == '1')
		img_put(slong, slong->images.wall, i, j);
	else if (slong->map[i][j] == '0')
		img_put(slong, slong->images.space, i, j);
	else if (slong->map[i][j] == 'P')
		img_put(slong, slong->images.player_right, i, j);
	else if (slong->map[i][j] == 'C')
		img_put(slong, slong->images.collect, i, j);
	else if (slong->map[i][j] == 'E')
		img_put(slong, slong->images.exit_close, i, j);
}

static bool	init_image_2(t_map *slong)
{
	slong->images.player_left = slong->images.player_down;
	slong->images.player_right = slong->images.player_up;
	slong->images.exit_close = mlx_xpm_file_to_image(slong->mlx, CDOOR,
		&slong->h_map, &slong->w_map);
	if (!slong->images.exit_close)
		return (false);
	slong->images.exit_open = mlx_xpm_file_to_image(slong->mlx, ODOOR,
		&slong->h_map, &slong->w_map);
	if (!slong->images.exit_open)
		return (false);
	return (true);
}

static bool	init_image_1(t_map *slong)
{
	slong->images.collect = mlx_xpm_file_to_image(slong->mlx, COLLECT,
		&slong->h_map, &slong->w_map);
	if (!slong->images.collect)
		return (false);
	slong->images.wall = mlx_xpm_file_to_image(slong->mlx, WALL,
		&slong->h_map, &slong->w_map);
	if (!slong->images.wall)
		return (false);
	slong->images.space = mlx_xpm_file_to_image(slong->mlx, SPACE,
		&slong->h_map, &slong->w_map);
	if (!slong->images.space)
		return (false);
	slong->images.player_up = mlx_xpm_file_to_image(slong->mlx, PMAN_U,
		&slong->h_map, &slong->w_map);
	if (!slong->images.player_up)
		return (false);
	slong->images.player_down = mlx_xpm_file_to_image(slong->mlx, PMAN_D,
		&slong->h_map, &slong->w_map);
	if (!slong->images.player_down)
		return (false);
	return (true);
}

bool	put_image(t_map *slong)
{
	int	i;
	int	j;

	i = -1;
	if (!init_image_1(slong) || !init_image_2(slong))
		return (false);
	while (slong->map[++i])
	{
		j = -1;
		while (slong->map[i][++j])
			aid_put_image(slong, i, j);
	}
	return (true);
}
