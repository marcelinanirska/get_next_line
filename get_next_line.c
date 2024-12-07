/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnirska <mnirska@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:26:42 by mnirska           #+#    #+#             */
/*   Updated: 2024/11/26 21:04:13 by mnirska          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stash;
	int			bytes_read;
	
	bytes_read = read(fd, stash, BUFFER_SIZE);
	if (!bytes_read)
		return (-1)
	WHILE STASH [I]
		if stash [i] != \n
			i++;
	else 
	read_line ( )

}


int main()
{
	int fd;
	fd = open("file.txt", O_RDONLY);
	printf()
}