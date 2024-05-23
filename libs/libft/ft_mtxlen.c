/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:57:41 by egeraldo          #+#    #+#             */
/*   Updated: 2024/03/18 16:09:02 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_mtxlen(char **mtx)
{
	size_t	i;

	i = 0;
	if (!mtx)
		return (0);
	while (mtx[i])
		i++;
	return (i);
}
