/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:21:16 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/30 14:24:58 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in(char c, const char *set)
{
	while (c && set && *set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1)
		return (NULL);
	while (s1 && s1[start] && ft_is_in(s1[start], set))
		start++;
	while (end > start && ft_is_in(s1[end], set))
		end--;
	if (++end > start)
		result = (char *)ft_calloc((end - start + 1), sizeof(char));
	else
		result = (char *)ft_calloc(1, sizeof(char));
	if (result == NULL)
		return (NULL);
	s1 += start;
	ft_strlcpy(result, s1, (end - start + 1));
	return (result);
}
