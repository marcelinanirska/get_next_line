/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnirska <mnirska@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:26:50 by mnirska           #+#    #+#             */
/*   Updated: 2024/11/15 15:31:51 by mnirska          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
int open (const char* path, int flags [ int mode ]);
ssize_t read(int fildes, void *buf, size_t nbyte);
size_t ft_strlen(const char *s);
char	*ft_substr(const char *str, unsigned int start, size_t len);

#endif