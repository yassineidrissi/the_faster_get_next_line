/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:57:22 by yaidriss          #+#    #+#             */
/*   Updated: 2022/10/19 12:12:48 by yaidriss         ###   ########.fr       */
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
}t_get;

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*my_ft_strjoin(char *s1, char *s2, int calloc);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t	count, size_t size);
char	*my_ft_strchr(const char	*s);
size_t	ft_strlen(const char *s);
char	*my_read(int fd, char *buffer, int a);
t_get	handl_sheet(t_get line, char *buffer);
char	*my_read(int fd, char *buffer, int a);
char	*my_ft_substr(char *s, unsigned int start, \
	size_t len, int alloc);

#endif
