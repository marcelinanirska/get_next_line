/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnirska <mnirska@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:26:47 by mnirska           #+#    #+#             */
/*   Updated: 2024/11/17 16:22:30 by mnirska          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	char_c;
	int		i;

	char_c = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == char_c)
			return ((char *)&str[i]);
		i++;
	}	
	if (str[i] == char_c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined[j++] = s2[i++];
	joined[j] = 0;
	return (joined);
}

char	*ft_strdup(char *src)
{
	size_t	src_len;
	char	*dest;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	dest = malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t i;
	size_t str_len;
	char *sub_str;

	i = 0;
	str_len = ft_strlen(str);
	if (!str)
		return (NULL);
	if (start > str_len)
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (i < len)
		sub_str[i++] = str[start++];
	return (sub_str);
}

/*int main (void)
{
	char	a[] = "hello world";

	printf("%s\n", ft_strchr(a, 'e'));
	printf("%s\n", strchr(a, 'e'));
}

int	main(void)
{
	char str[] = "source";
	printf("%s", ft_substr(str, 0, 6));
	return (0);
}*/
