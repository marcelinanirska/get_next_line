/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelina <marcelina@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:25:17 by marcelina         #+#    #+#             */
/*   Updated: 2024/12/07 19:30:59 by marcelina        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include <unistd.h>
#include <stdio.h>

char	*ft_free(char *stash, char *buf)
{
	char	*temp;

	temp = ft_strjoin(stash, buf);
	free(stash);
	return (temp);
}

char	*ft_next_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (stash[i])
		line[j++] = stash[i++];
	free(stash);
	return (line);
}

char *ft_new_line(char *stash)
{
    char *new_line;
    int i;

    i = 0;
    if (!stash[i])
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    new_line = ft_calloc(i + 2, sizeof(char)); 
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        new_line[i] = stash[i];
        i++;
    }
    if (stash[i] && stash[i] == '\n')
        new_line[i++] = '\n';

    return (new_line);
}

char *ft_read(int fd, char *result)
{
    int   bytes_read;
    char  *stash;

    bytes_read = 1;
    if (!result)
		result = ft_calloc(1, 1);
    stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!stash)
        return (NULL);
    while (bytes_read > 0)
    {
        bytes_read = read(fd, stash, BUFFER_SIZE);
        if (bytes_read <= 0)
            return (free (stash), NULL);
        stash[bytes_read] = '\0';
        result = ft_free(result, stash);
        if (ft_strchr(stash, '\n'))
            break;
    }
    free(stash);
    return (result);
}
char *get_next_line(int fd)
{
    static char *stash;
    char        *new_line;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
    stash = ft_read(fd, stash);
    if (!stash)
		return (NULL);
    new_line = ft_new_line(stash);
    stash = ft_next_line(stash);
    return (new_line);
}

#include <fcntl.h>

int main(void)
{
    int    fd;
    char  *next_line;
    int  count;

    count = 0;
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("File not found");
        return (1);
    }
    while (1)
    {
        next_line = get_next_line(fd);
        if (!next_line)
            break;
        count++;
        printf("[%d]:%s\n", count, next_line);
        free(next_line);
        next_line = NULL;
    }
    close(fd);
    return (0);
}
