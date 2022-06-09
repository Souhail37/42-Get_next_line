/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:03:47 by sismaili          #+#    #+#             */
/*   Updated: 2021/12/14 17:53:51 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)&str[i]);
}

char	*ft_strjoin(char *s1, char *s2, int j, int i)
{
	char	*result;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	result = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free (s1);
	return (result);
}
