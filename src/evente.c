/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evente.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:56:32 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 17:55:29 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	demi_move_aid(t_map *slong, int i, int j)
{
	if (i == 1 && !j)
		mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->images.player_down,
			slong->y_p * SIZE, slong->x_p * SIZE);
	else if (i == -1 && !j)
		mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->images.player_up,
			slong->y_p * SIZE, slong->x_p * SIZE);
	else if (!i && j == 1)
		mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->images.player_right,
			slong->y_p * SIZE, slong->x_p * SIZE);
	else if (!i && j == -1)
		mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->images.player_left,
			slong->y_p * SIZE, slong->x_p * SIZE);
}

void	demi_move(t_map *slong, int i, int j, bool sign)
{
	if (sign)
	{
		if (i == 1 && !j)
			mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->images.player_down,
				(slong->y_p + j) * SIZE, (slong->x_p + i) * SIZE);
		else if (i == -1 && !j)
			mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->images.player_up,
				(slong->y_p + j) * SIZE, (slong->x_p + i) * SIZE);
		else if (!i && j == 1)
			mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->images.player_right,
				(slong->y_p + j) * SIZE, (slong->x_p + i) * SIZE);
		else if (!i && j == -1)
			mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->images.player_left,
				(slong->y_p + j) * SIZE, (slong->x_p + i) * SIZE);
	}
	else
		demi_move_aid(slong, i, j);
}

void	put_move(t_map *slong, int i, int j)
{
	char *tmp_1;
	char *tmp_2;

	mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->images.space,
		(slong->y_p) * SIZE, (slong->x_p) * SIZE);
	demi_move(slong, i, j, true);
	slong->x_p += i;
	slong->y_p += j;
	tmp_1 = ft_itoa(slong->move);
	tmp_2 = ft_strjoin("move : ", tmp_1);
	ft_putendl_fd(tmp_2, 1);
	free(tmp_1);
	free(tmp_2);
}

void	ft_go(t_map **slong, int i, int j)// i = 1, j = 0
{
	if ((*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == '1' ||
		((*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == 'E' &&
		(*slong)->collect))
		return (demi_move(*slong, i, j, false));
	if ((*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == 'C' ||
		(*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == '0')
	{
		if ((*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == 'C')
			(*slong)->collect -= 1;
		(*slong)->map[(*slong)->x_p][(*slong)->y_p] = '0';
		(*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] = 'P';
		(*slong)->move += 1;
	}
	else if ((*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == 'E' &&
		!(*slong)->collect)
	{
		ft_putendl_fd("You Win :)", 1);
		fr_stack(*slong);
		mlx_destroy_window((*slong)->mlx, (*slong)->mlx_win);
		exit(0);
	}
	if (!(*slong)->collect)
		ft_ft(*slong);
	put_move(*slong, i, j);
}

int	ft_hook(int prees, t_map **slong)
{
	if (prees == 1)
		ft_go(slong, 1, 0);
	else if (prees == 13)
		ft_go(slong, -1, 0);
	else if (prees == 2)
		ft_go(slong, 0, 1);
	else if (prees == 0)
		ft_go(slong, 0, -1);
	else if (prees == 53)
	{
		free((*slong)->mlx);
		ft_putendl_fd("Exit :(", 1);
		free_double((*slong)->map);
		mlx_destroy_window((*slong)->mlx, (*slong)->mlx_win);
		exit(1);
	}
	return (1);
}
