/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:50:19 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/24 12:18:28 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_substr;

	len_substr = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (big && *big && len_substr <= len--)
	{
		if (ft_strncmp(big, little, len_substr) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
