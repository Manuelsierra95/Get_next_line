/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:08:20 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/10 18:07:04 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *temp;
	static char *save;

	temp = "";
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	if (save != NULL && save[0] != '\0')
	{
		if (!(ft_strchr(temp, '\n')))
			ft_read(fd, &save, temp);
		temp = ft_cut(save, '\n', &save);
	}
	else
	{
		ft_read(fd, &save, temp);
		if (!ft_ifsave(&save))
			return (NULL);
		temp = ft_cut(save, '\n', &save);
	}
	if (!temp)
		return (NULL);
	return (temp);
}
int ft_ifsave(char **save)
{
	if (!*save)
		return (0);
	if (!**save)
	{
		free(*save);
		*save = NULL;
		return (0);
	}
	return (1);
}

char	*ft_read(int fd, char **save, char *temp)
{
	int	numr;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while ((!*save || !ft_strchr(*save, '\n')))
	{
		numr = read(fd, temp, BUFFER_SIZE);
		if (numr <= 0)
			break;
		temp[numr] = '\0';
		if (save != NULL && save[0] != '\0')
			*save = ft_strjoin(*save, temp);
		else
			*save = ft_strdup(temp);
	}
	free(temp);
	return(*save);
}

char *ft_cut(char *s, int c, char **save)
{
	size_t len;
	size_t i;
	char *line;
	char *aux;

	if (!*save)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	aux = *save;
	while (s[i] != (char)c && i < len)
		i++;
	line = ft_substr(s, 0, (i + 1));
	*save = ft_substr(s, (i + 1), len);
	free(aux);
	return (line);
}
