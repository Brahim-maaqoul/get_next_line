/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:32:00 by bmaaqoul          #+#    #+#             */
/*   Updated: 2021/12/17 21:32:15 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (str + i);
		i++;
	}
	if (c == 0)
		return (str + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*t;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	k = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = -1;
	t = (char *) malloc(sizeof(char) * k + 1);
	if (!t)
		return (NULL);
	while (s1[++i])
		t[i] = s1[i];
	while (s2[++j])
		t[i++] = s2[j];
	t[i] = '\0';
	free (s1);
	return (t);
}

char	*ft_read(char	*str, int fd)
{
	char	*buff;
	int		r;

	r = 1;
	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(str, '\n') && r != 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
		{
			free (buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*ft_myline(char *str)
{
	int		i;
	char	*s;

	if (*str == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *) malloc(sizeof(char) * i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{	
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
