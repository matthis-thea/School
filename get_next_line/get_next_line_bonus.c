/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:41:35 by mthea             #+#    #+#             */
/*   Updated: 2022/12/05 11:05:34 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_reading_file(int fd, char *old_string)
{
	char	*buffer;
	int		number;

	number = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
	{
		if (old_string)
			free(old_string);
		return (NULL);
	}
	while (number > 0 && !ft_comp(old_string, '\n'))
	{
		number = read(fd, buffer, BUFFER_SIZE);
		if (number == -1)
		{
			free(old_string);
			free(buffer);
			return (NULL);
		}
		buffer[number] = 0;
		old_string = ft_strjoin(old_string, buffer);
	}
	free(buffer);
	return (old_string);
}

char	*ft_strcopy_new(char *s)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
		i--;
	new_string = ft_calloc((i + 2), sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		new_string[j++] = s[i++];
	if (s[i] == '\n')
		new_string[j++] = s[i];
	new_string[j] = '\0';
	return (new_string);
}

char	*ft_clear_old(char *s)
{
	char	*new_string;
	int		start;
	int		end;

	start = 0;
	while (s[start] != '\n' && s[start])
		start++;
	if (!s[0])
	{
		free(s);
		return (NULL);
	}
	if (s[start] != '\0')
		start++;
	new_string = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	if (!new_string)
		return (NULL);
	end = start;
	start = 0;
	while (s[end] && s)
		new_string[start++] = s[end++];
	free(s);
	return (new_string);
}

char	*get_next_line(int fd)
{
	static char	*old_string[4096];
	char		*new_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	old_string[fd] = ft_reading_file(fd, old_string[fd]);
	if (!old_string[fd])
		return (NULL);
	new_string = ft_strcopy_new(old_string[fd]);
	old_string[fd] = ft_clear_old(old_string[fd]);
	return (new_string);
}
