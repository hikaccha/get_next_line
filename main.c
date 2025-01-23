/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichikaw <hichikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:58:32 by hichikaw          #+#    #+#             */
/*   Updated: 2025/01/23 13:39:30 by hichikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **v)
{
	int		fd;
	char	*line;

	(void)ac;
	fd = open(v[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

// int main()
//{
//	int	fd = 0;
//	char	*line = NULL;
//	//char	line2 = NULL;
//
//	fd = open("test.txt", O_RDONLY);
//	//int 	fd2 = open("text.txt", O_RDONLY);
//	while (1)
//	{
//		line = get_next_line(fd);
//		//line2 = get_next_line(fd2);
//		printf("1---%s", line);
//		//printf("1---%s", line2);
//		if (line == NULL)
//			break ;
//		free(line);
//	}
//	close(fd);
//}
