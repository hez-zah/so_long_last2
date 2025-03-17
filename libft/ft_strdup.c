/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:07:45 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/13 19:41:17 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	l;

	l = ft_strlen(src);
	copy = (char *)malloc(l + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, src, l);
	copy[l] = '\0';
	return (copy);
}
