/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:59:35 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/09 21:13:49 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *s)
{
	size_t n;

	n = 0;
	while (s[n])
	{
		n++;
	}
	return (n);
}
char *ft_strdup(char *s1)
{
	char *a;
	size_t size;

	size = ft_strlen(s1) + 1;
	a = malloc(size * sizeof(char));
	if (!a)
		return (NULL);
	ft_memcpy(a, s1, size);
	return (a);
}

char *ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == '\0' && c != 0)
		return (0);
	return ((char *)s + i);
}
char *ft_substr(char *s, unsigned int start, size_t len)
{
	char *a;
	size_t i;
	size_t	lens;

	lens = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= lens)
		len = 0;
	if (len > lens)
		len = lens;
	a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i < len && s[start + i])
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char *ft_strjoin(char *temp, char *s2)
{
	char *a;
	size_t lentemp;
	size_t lens2;

	lentemp = ft_strlen(temp);
	lens2 = ft_strlen(s2);
	if (!temp || !s2)
		return (NULL);
	a = malloc((lentemp + lens2 + 1) * sizeof(char));
	if (!a)
		return (NULL);
	ft_memcpy(a, temp, lentemp);
	ft_memcpy(a + lentemp, s2, lens2);
	a[lentemp + lens2] = '\0';
	free(temp);
	return (a);
}
void *ft_memcpy(void *dst, void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}