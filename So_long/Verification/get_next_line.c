/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:46:28 by mthea             #+#    #+#             */
/*   Updated: 2023/01/18 11:39:58 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

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
	static char	*old_string;
	char		*new_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	old_string = ft_reading_file(fd, old_string);
	if (!old_string)
		return (NULL);
	new_string = ft_strcopy_new(old_string);
	old_string = ft_clear_old(old_string);
	return (new_string);
}
