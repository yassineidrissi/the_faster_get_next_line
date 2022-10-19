/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:49:10 by yaidriss          #+#    #+#             */
/*   Updated: 2022/10/19 12:05:57 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_ft_strjoin(char *s1, char *s2, int calloc)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	if (calloc)
		free (s1);
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*b;

	b = (unsigned char *)s;
	i = -1;
	while (++i < n)
		b[i] = 0;
}

void	*ft_calloc(size_t	count, size_t size)
{
	void	*result;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	result = malloc(count * size);
	if (!result)
		return (0);
	ft_bzero(result, count * size);
	return (result);
}

char	*my_ft_strchr(const char	*s)
{
	int		i;
	char	*s1;
	int		n;

	i = 0;
	s1 = (char *)s;
	n = ft_strlen(s1);
	while (i <= n)
	{
		if (s1[i] == '\n')
		{
			return (&s1[i]);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_ft_substr(char *s, unsigned int start,\
	 size_t len, int alloc)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len < 0 || ft_strlen(s) < start)
		result = malloc(sizeof(*s));
	else if (ft_strlen(s) + len < start)
		result = malloc((ft_strlen(s) - start + 1) * sizeof(*s));
	else
		result = malloc((len + 1) * sizeof(*s));
	if (!result)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			result[j++] = s[i];
		i++;
	}
	result[j] = 0;
	if (alloc)
		free(s);
	return (result);
}


t_get	handl_sheet(t_get line,char *buffer)
{
	line.index = (int)(my_ft_strchr(line.data) - line.data);
	line.part = my_ft_substr(line.data,0,line.index, 0);
	line.next = my_ft_substr(line.data, line.index + 1, ft_strlen(line.data) - line.index, 1);
	line.line = my_ft_strjoin(buffer, line.part, 1);
	buffer = line.next;
	return (line);
}
