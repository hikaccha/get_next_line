/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichikaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:58:32 by hichikaw          #+#    #+#             */
/*   Updated: 2024/12/25 08:29:56 by hichikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

//int	main(int c, char **v)
//{
//	int		fd;
//	char	*line;
//
//	(void)c;
//	fd = open("test.txt", O_RDONLY);
//	line = NULL;
//	printf("BUFFER_SIZE=%d\n\n", BUFFER_SIZE);
//	while ((line = get_next_line(1)))
//	{
//		printf("> %s", line);
//		free(line);
//	}
//	free(line);
//	close(fd);
//}

int main() 
{
    int fd = 0;
    char *line = NULL;
    // char *line2 = NULL;
    fd = open("test.txt", O_RDONLY);
    // int fd2 = open("test.txt", O_RDONLY);
    while (1) {
        line = get_next_line(fd);
        // line2 = get_next_line(fd2);
	if (line == NULL)
              break;
        printf("1---%s", line);
        // printf("2---%s", line2);
        free(line);
    }
    close(fd);
}
