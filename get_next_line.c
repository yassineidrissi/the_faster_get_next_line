/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:48:53 by yaidriss          #+#    #+#             */
/*   Updated: 2022/10/19 16:22:28 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_get	my_read(int fd, char *buffer, int a)
{
	t_get		yi;
	int 		j;

	j = 1;
	yi.data = "";
	yi.end = 1;
	if (!a)
	{
		yi.data = ft_calloc(BUFFER_SIZE + 1, 1);
		while(!my_ft_strchr(yi.data) &&  j > 0)
		{
			j = read(fd, yi.data, BUFFER_SIZE);
			if (my_ft_strchr(yi.data))
			{
				yi = handl_sheet(yi, buffer);
				buffer = yi.next;
			}
			else
			{
				buffer = my_ft_strjoin(buffer, yi.data, 1);
				if (!j)
				{
					yi.line = buffer;
					buffer = NULL;
					yi.end = 0;
				}
			}
		}
	}
	else
	{
		yi.data = buffer;
		buffer = NULL; 
		yi = handl_sheet(yi, buffer);
	}
		return (yi);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			exist;
	t_get		final;

	exist = 0;

	if(my_ft_strchr(buffer))
		exist = 1;
	final = my_read(fd,	buffer, exist);
	if (final.line == NULL || !final.end)
		return (NULL);
	buffer = final.next;
	return (final.line);
}

