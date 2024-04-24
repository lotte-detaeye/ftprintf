/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:32:53 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/05 11:22:29 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkforc(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*newstr;
	int			start;
	int			end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (checkforc(set, s1[start]) == 0)
		start++;
	if (s1[start] == '\0')
	{
		newstr = (char *)malloc(start * sizeof(char));
		if (newstr == 0)
			return (0);
		else
		{
			free(newstr);
			return (ft_strdup(""));
		}
	}
	while (checkforc(set, s1[end - 1]) == 0)
		end--;
	newstr = ft_substr(s1, start, (end - start));
	return (newstr);
}
