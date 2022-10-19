/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:48:53 by yaidriss          #+#    #+#             */
/*   Updated: 2022/10/19 12:11:54 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_read(int fd, char *buffer, int a)
{
	t_get		yi;
	if (!a)
	{
		yi.data = ft_calloc(BUFFER_SIZE + 1, 1);
		while(my_ft_strchr(yi.data) && read(fd, yi.data, BUFFER_SIZE) > 0)
		{
			if (my_ft_strchr(yi.data))
				yi = handl_sheet(yi, buffer);
			else
				buffer = my_ft_strjoin(buffer, yi.data, 1);
		}
	}
	else
	{
		yi.data = buffer;
		buffer = NULL; 
		yi = handl_sheet(yi, buffer);
	}
		return (yi.line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			exist;
	char		*final;

	exist = 0;
	if(my_ft_strchr(buffer))
		exist = 1;
	final = my_read(fd,	buffer, exist);
	return (final);
}

