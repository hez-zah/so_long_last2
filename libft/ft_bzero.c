/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:05:06 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 19:27:39 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*l;

	l = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		l[i] = 0;
		i++;
	}
}
