/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnirska <mnirska@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:25:17 by marcelina         #+#    #+#             */
/*   Updated: 2024/12/09 12:07:51 by mnirska          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include <unistd.h>
#include <stdio.h>

char	*ft_next_line(char *stash)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	next_line = ft_calloc((ft_strlen(stash) - i), sizeof(char));
	i++;
	j = 0;
	while (stash[i])
		next_line[j++] = stash[i++];
	return (free(stash), next_line);
}

char *ft_new_line(char *stash)
{
    char *new_line;
    int i;

    i = 0;
    if (!stash[i])
        return (NULL);
    while (stash[i] != '\n' && stash[i])
        i++;
    new_line = ft_calloc(i + 2, sizeof(char)); 
    i = 0;
    while (stash[i] != '\n' && stash[i])
    {
        new_line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n' && stash[i])
        new_line[i++] = '\n';
    return (new_line);
}

char *ft_read_line(int fd, char *stash)
{
    int   bytes_read;
    char  *buffer;
    char *temp;

    bytes_read = 1;
    if (!stash)
		stash = ft_calloc(1, 1);
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return (NULL);
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            return (free (buffer), NULL);
        buffer[bytes_read] = '\0';
        temp = stash;
        stash = ft_strjoin(temp, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    return (free(buffer), free(temp), stash);
}
char *get_next_line(int fd)
{
    static char *stash;
    char        *new_line;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
    stash = ft_read_line(fd, stash);
    if (!stash)
		return (NULL);
    new_line = ft_new_line(stash);
    stash = ft_next_line(stash);
    return (new_line);
}

#include <fcntl.h>

// int main(void)
// {
//     int    fd;
//     char  *next_line;
//     int  count;

//     count = 0;
//     fd = open("file.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("File not found");
//         return (1);
//     }
//     while (1)
//     {
//         next_line = get_next_line(fd);
//         if (!next_line)
//             break;
//         count++;
//         printf("[%d]:%s\n", count, next_line);
//         free(next_line);
//         next_line = NULL;
//     }
//     close(fd);
//     return (0);
// }
