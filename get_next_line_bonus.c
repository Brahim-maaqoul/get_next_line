/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:32:26 by bmaaqoul          #+#    #+#             */
/*   Updated: 2021/12/17 22:02:16 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_store(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	buff = (char *) malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!buff)
		return (NULL);
	i++;
	while (str[i])
	{
		buff[j++] = str[i];
		i++;
	}
	buff[j] = '\0';
	free (str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*new;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_read(str[fd], fd);
	if (!str[fd])
		return (NULL);
	new = ft_myline(str[fd]);
	str[fd] = ft_store(str[fd]);
	return (new);
}
