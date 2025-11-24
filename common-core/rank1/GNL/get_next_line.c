/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:40:16 by vephan            #+#    #+#             */
/*   Updated: 2025/10/30 14:31:45 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_more_data(int fd, char *saved_data, char *buffer);
static char	*split_line(char *line);
static char	*reset_s(char *s);

char	*get_next_line(int fd)
{
	static char	*saved_data;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		buffer = reset_s(buffer);
		saved_data = reset_s(saved_data);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = get_more_data(fd, saved_data, buffer);
	buffer = reset_s(buffer);
	if (!line)
	{
		saved_data = reset_s(saved_data);
		return (NULL);
	}
	saved_data = split_line(line);
	return (line);
}

static char	*reset_s(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

/* check EOF or EOL*/
static char	*split_line(char *line_buffer)
{
	char	*saved_data;
	char	*tmp;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[i + 1] == 0)
		return (NULL);
	tmp = ft_strchr(line_buffer, '\n');
	saved_data = ft_strdup((tmp + 1));
	if (*saved_data == 0)
		saved_data = reset_s(saved_data);
	line_buffer[i + 1] = 0;
	return (saved_data);
}

static char	*get_more_data(int fd, char *saved_data, char *buffer)
{
	ssize_t	newbytes;
	char	*tmp;

	newbytes = 1;
	while (newbytes > 0)
	{
		newbytes = read(fd, buffer, BUFFER_SIZE);
		if (newbytes == -1)
			return (NULL);
		else if (newbytes == 0)
			break ;
		buffer[newbytes] = 0;
		if (!saved_data)
			saved_data = ft_strdup("");
		tmp = saved_data;
		saved_data = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (saved_data);
}

/*#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int fd = open("1char.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd))) {
		printf("%s", line);
		free(line);
	}
	line = get_next_line(fd); // After EOF
	printf("After EOF: %s\n", line ? line : "NULL");
	free(line);
	close(fd);
	line = get_next_line(fd); // After close
	printf("After close: %s\n", line ? line : "NULL");
	free(line);
}
*/
/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd); // Your implementation

int main(void) {
    int fd = open("1char.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    // Call again after EOF
    line = get_next_line(fd);
    printf("After EOF: %s\n", line ? line : "NULL");
    free(line);

    // Close FD and call again
    close(fd);
    line = get_next_line(fd);
    printf("After close: %s\n", line ? line : "NULL");
    free(line);

    return 0;
}*/

/*
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int fd = open("read_error.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read first two lines
    char *s = get_next_line(fd);
    printf("1: %s", s); free(s);
    s = get_next_line(fd);
    printf("2: %s", s); free(s);

    // Simulate read error by closing fd
    close(fd);

    // Try reading again (should return NULL)
    s = get_next_line(fd);
    printf("3: %s\n", s ? s : "NULL");
    free(s);

    // Reopen and read all lines
    fd = open("read_error.txt", O_RDONLY);
    for (int i = 4; i <= 8; i++) {
        s = get_next_line(fd);
        printf("%d: %s", i, s ? s : "NULL\n");
        free(s);
    }
    close(fd);
    return 0;

}
*/
/*
	int	fd = open("empty.txt", O_RDWR);
	dup2(fd, 1000);
	s = get_next_line(1000);
	free(s);
	s = get_next_line(-1);
	free(s);
	close(fd);
	s = get_next_line(fd);
	return (0);*/
