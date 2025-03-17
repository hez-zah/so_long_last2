/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:49:08 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 19:28:19 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include "../g_n_l/get_next_line.h"

char	**get_map(char *av[], t_map **slong)
{
	char	*line;
	char	*aid_line;
	char	*fr_line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error fd\n", 2), NULL);
	line = ft_strdup("");
	while (1)
	{
		aid_line = get_next_line(fd);
		if (!aid_line)
			break ;
		if (ft_strnstr(aid_line, "\n", 1))
			return (close (fd), free(line), free(aid_line), NULL);
		fr_line = line;
		line = ft_strjoin(line, aid_line);
		free(aid_line);
		free(fr_line);
	}
	if (line[ft_strlen(line) - 1] == '\n' || !line[0])
		return (close (fd), free(line), NULL);
	(*slong)->map = ft_split(line, '\n');
	return (close (fd), free(line), (*slong)->map);
}

bool	ft_mlx(t_map **slong)
{
	(*slong)->mlx = mlx_init();
	if (!(*slong)->mlx)
		return (fr_stack(*slong), false);
	(*slong)->mlx_win = mlx_new_window((*slong)->mlx,
			(*slong)->h_map * SIZE, (*slong)->w_map * SIZE, "so_long");
	if (!(*slong)->mlx_win)
		return (fr_stack(*slong), false);
	if (!put_image(*slong))
		return (ft_putstr_fd("Error Image\n", 2),
			free_double((*slong)->map), false);
	mlx_hook((*slong)->mlx_win, 2, (1L << 0), ft_hook, &(*slong));
	mlx_hook((*slong)->mlx_win, 17, (1L << 0), ft_exit, &(*slong));
	mlx_string_put((*slong)->mlx, (*slong)->mlx_win, 5, 15, 0x00ffff, "move : 0");
	mlx_loop_hook((*slong)->mlx, animation_collect, &(*slong));
	mlx_loop((*slong)->mlx);
	return (true);
}

void ff(){system("leaks so_long_bonus");}

int	main(int ac, char *av[])
{
	// atexit(ff);
	t_map	*slong;

	if (ac != 2 || !ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		return (ft_putstr_fd("Error Argument\n", 2), 0);
	slong = ft_calloc(1, sizeof(t_map));
	slong->map = get_map(av, &slong);
	if (!slong->map)
		return (ft_putstr_fd("Error Map\n", 2), free(slong), 1);
	if (!handl_error(&slong))
		return (ft_putstr_fd("Error Map\n", 2),
			free_double(slong->map), free(slong), 1);
	slong->e_var.x = 0;
	slong->e_var.sleep = 5;
	if (!ft_mlx(&slong))
	{
		free_image(slong);
		mlx_destroy_window(slong->mlx, slong->mlx_win);
		return (free(slong->mlx), free(slong), 1);
	}
}
