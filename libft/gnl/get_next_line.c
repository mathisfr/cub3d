/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:00:19 by lloison           #+#    #+#             */
/*   Updated: 2022/11/19 11:38:51 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static void	*return_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (0);
}

int	has_nl_or_is_empty(int behavior, char *s)
{
	unsigned int	i;

	i = 0;
	if (behavior == 1)
	{
		while (i < BUFFER_SIZE + 1)
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
		return (0);
	}
	else
	{
		while (i < BUFFER_SIZE + 1)
		{
			if (s[i] != 0)
				return (0);
			i++;
		}
		return (1);
	}
}

char	*extract_line(char *buf, int i, int len)
{
	int		start_index;
	char	*output;

	while (buf[i + 1] == 0)
		i++;
	start_index = i + 1;
	while (buf[++i] != 0 && buf[i] != '\n')
		len++;
	if (buf[i] == '\n')
		len++;
	output = (char *) malloc(sizeof(char) * (len + 1));
	if (output == 0)
	{
		exit(0);
		return (0);
	}
	i = -1;
	while (++i < len)
	{
		output[i] = buf[start_index];
		buf[start_index] = 0;
		start_index++;
	}
	output[i] = 0;
	return (output);
}

char	*str_join_free(char *s1, char *s2, int size_s1, int size_s2)
{
	char			*output;
	int				i;

	i = -1;
	while (!*s1)
		s1++;
	while (s1[size_s1])
		size_s1++;
	while (!*s2)
		s2++;
	while (s2[size_s2])
		size_s2++;
	output = (char *) malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (output == 0)
		return (return_free(s1, s2));
	while (++i < size_s1)
		output[i] = s1[i];
	i--;
	while (++i < size_s1 + size_s2)
		output[i] = s2[i - size_s1];
	output[i] = 0;
	free(s1);
	free(s2);
	return (output);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*temp;
	char		*temp_buf;

	if (!has_nl_or_is_empty(2, buf))
	{
		if (has_nl_or_is_empty(1, buf))
			return (extract_line(buf, -1, 0));
		temp_buf = extract_line(buf, -1, 0);
		if (temp_buf == 0)
			return (0);
		temp = get_next_line(fd);
		if (temp == 0)
			return (temp_buf);
		return (str_join_free(temp_buf, temp, 0, 0));
	}
	if (read(fd, buf, BUFFER_SIZE) <= 0)
		return (0);
	return (get_next_line(fd));
}

/*int	main(int argc, char **argv)
  {
  int	fd;
  char	*line;

  (void) argc;
  fd = open(argv[1], O_RDONLY);
  line = get_next_line(fd);
  while (line)
  {
  printf("%s", line);
  line = get_next_line(fd);
  }
  return (0);
 }*/
