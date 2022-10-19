/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:06:11 by yaidriss          #+#    #+#             */
/*   Updated: 2022/10/19 10:51:02 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("the first line is %s", get_next_line(fd));
	printf("the second line is %s", get_next_line(fd));
	printf("the 3th line is %s", get_next_line(fd));
	printf("the 4th line is %s", get_next_line(fd));
}
