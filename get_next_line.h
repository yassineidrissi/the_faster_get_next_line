/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:57:22 by yaidriss          #+#    #+#             */
/*   Updated: 2022/10/19 16:14:57 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct l_get
{
	int		index;
	char	*data;
	char	*line;
	char	*next;
	char	*part;
	int 	end;
}t_get;

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 70
#endif

char	*get_next_line(int fd);
char	*my_ft_strjoin(char *s1, char *s2, int calloc);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t	count, size_t size);
char	*my_ft_strchr(const char	*s);
size_t	ft_strlen(const char *s);
t_get	handl_sheet(t_get line, char *buffer);
t_get	my_read(int fd, char *buffer, int a);
char	*my_ft_substr(char *s, unsigned int start, \
	size_t len, int alloc);

#endif
