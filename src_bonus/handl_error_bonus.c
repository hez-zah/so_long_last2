/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:35:08 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 00:56:57 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static bool	handl_wall(t_map **slong)
{
	int	i;
	int	j;

	j = -1;
	while ((*slong)->map[0][++j])
		if ((*slong)->map[0][j] != '1')
			return (false);
	(*slong)->h_map = j;
	i = -1;
	while ((*slong)->map[++i])
		if ((*slong)->map[i][j - 1] != '1')
			return (false);
	j = -1;
	while ((*slong)->map[i - 1][++j])
		if ((*slong)->map[i - 1][j] != '1')
			return (false);
	i = -1;
	while ((*slong)->map[++i])
		if ((*slong)->map[i][0] != '1')
			return (false);
	(*slong)->w_map = i;
	(*slong)->move = 0;
	return (true);
}

static int	aid_handl_caracters(t_map **slong, int i, int j)
{
	if ((*slong)->map[i][j] == 'C')
		(*slong)->collect += 1;
	if ((*slong)->map[i][j] == 'X')
		(*slong)->war_collect += 1;
	else if ((*slong)->map[i][j] == 'P')
	{
		(*slong)->x_p = i;
		(*slong)->y_p = j;
	}
	else if ((*slong)->map[i][j] == 'E')
	{
		(*slong)->x_e = i;
		(*slong)->y_e = j;
	}
	if ((*slong)->map[i][j] == 'P')
		return (1);
	return (0);
}

static bool	handl_caracteres_1(t_map **slong)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	(*slong)->collect = 0;
	player = 0;
	while ((*slong)->map[++i])
	{
		j = -1;
		while ((*slong)->map[i][++j])
		{
			if (!ft_strchr("01CPEX", (*slong)->map[i][j]) || player >= 2)
				return (false);
			player += aid_handl_caracters(slong, i, j);
		}
	}
	if (!player || !(*slong)->collect)
		return (false);
	(*slong)->call = false;
	return (true);
}

static bool	handl_caracters_2(t_map **slong)
{
	int i;
	int j;
	int	x_enem;
	int	door;

	i = -1;
	x_enem = 0;
	door = 0;
	while ((*slong)->map[++i])
	{
		j = -1;
		while ((*slong)->map[i][++j])
		{
			if ((*slong)->map[i][j] == 'X')
				x_enem++;
			else if ((*slong)->map[i][j] == 'E')
				door++;
		}
	}
	if (!x_enem || !door)
		return (false);
	return (true);
}

bool	handl_error(t_map **slong)
{
	char **copy;

	if (!(*slong)->map)
		return (false);
	if (!handl_caracteres_1(slong))
		return (false);
	if (!handl_caracters_2(slong))
		return (false);
	if (!handl_wall(slong))
		return (false);
	copy = copy_map((*slong)->map);
	if (!copy)
		return (false);
	if (!handl_close(copy))
		return (free_double(copy), false);
	return (free_double(copy), true);
}
