/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:17:26 by vephan            #+#    #+#             */
/*   Updated: 2025/10/30 14:28:26 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_more_data(int fd, char *saved_data, char *buffer);
char	*split_line(char *line);
char	*reset_s(char *s);
void	reset_array(char **saved_data);

char	*get_next_line(int fd)
{
	static char	*saved_data[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		buffer = reset_s(buffer);
		reset_array(saved_data);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = get_more_data(fd, saved_data[fd], buffer);
	buffer = reset_s(buffer);
	if (!line)
	{
		saved_data[fd] = reset_s(saved_data[fd]);
		return (NULL);
	}
	saved_data[fd] = split_line(line);
	return (line);
}

char	*reset_s(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

void	reset_array(char **saved_data)
{
	size_t	i;

	i = 0;
	while (i < MAX_FD)
	{
		if (saved_data[i])
			free(saved_data[i]);
		saved_data[i++] = NULL;
	}
}

char	*split_line(char *line_buffer)
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

char	*get_more_data(int fd, char *saved_data, char *buffer)
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
/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void print_and_free(char *line, const char *label) {
    printf("%s: %s", label, line ? line : "NULL\n");
    free(line);
}

int main(void) {
    char *name = "read_error.txt";
    char *other = "lines_around_10.txt";

    int fd = open(name, O_RDONLY);
    int fd2 = open(other, O_RDONLY);
    if (fd == -1 || fd2 == -1) {
        perror("open");
        return 1;
    }

    // Alternate reads aggressively
    for (int i = 0; i < 5; i++) {
        print_and_free(get_next_line(fd), "fd1");
        print_and_free(get_next_line(fd2), "fd2");
    }

    // Exhaust fd2 completely
    char *line;
    while ((line = get_next_line(fd2))) {
        print_and_free(line, "fd2");
    }

    // Call after EOF multiple times
    for (int i = 0; i < 3; i++) {
        print_and_free(get_next_line(fd2), "fd2 after EOF");
    }

    // Close fd and call again
    close(fd);
    print_and_free(get_next_line(fd), "fd1 after close");

    // Reopen fd and read again
    fd = open(name, O_RDONLY);
    if (fd == -1) {
        perror("reopen");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        print_and_free(get_next_line(fd), "fd1 reopened");
    }

    // Stress test: alternate NULL calls
    for (int i = 0; i < 5; i++) {
        print_and_free(get_next_line(fd), "fd1 extra");
        print_and_free(get_next_line(fd2), "fd2 extra");
    }

    close(fd);
    close(fd2);
    return 0;
}*/

/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void) {
    char *name = "read_error.txt";
    char *other = "lines_around_10.txt";

    int fd = open(name, O_RDONLY);
    int fd2 = open(other, O_RDONLY);
    if (fd == -1 || fd2 == -1) {
        perror("open");
        return 1;
    }

    char *line;

    // 1
    line = get_next_line(fd);
    printf("1: %s", line ? line : "NULL\n");
    free(line);

    // 2
    line = get_next_line(fd2);
    printf("2: %s", line ? line : "NULL\n");
    free(line);

    // 3
    line = get_next_line(fd);
    printf("3: %s", line ? line : "NULL\n");
    free(line);

    // 4
    line = get_next_line(fd2);
    printf("4: %s", line ? line : "NULL\n");
    free(line);

    // Simulate read error by closing fd
    close(fd);

    // 5: should return NULL
    line = get_next_line(fd);
    printf("5: %s\n", line ? line : "NULL");
    free(line);

    // Continue reading fd2
    line = get_next_line(fd2);
    printf("6: %s", line ? line : "NULL\n");
    free(line);

    // Reopen fd
    fd = open(name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 7
    line = get_next_line(fd);
    printf("7: %s", line ? line : "NULL\n");
    free(line);

    // 8
    line = get_next_line(fd2);
    printf("8: %s", line ? line : "NULL\n");
    free(line);

    // 9
    line = get_next_line(fd);
    printf("9: %s", line ? line : "NULL\n");
    free(line);

    // 10
    line = get_next_line(fd);
    printf("10: %s", line ? line : "NULL\n");
    free(line);

    // 11
    line = get_next_line(fd2);
    printf("11: %s", line ? line : "NULL\n");
    free(line);

    // 12
    line = get_next_line(fd2);
    printf("12: %s\n", line ? line : "NULL");
    free(line);

    // 13
    line = get_next_line(fd);
    printf("13: %s", line ? line : "NULL\n");
    free(line);

    // 14
    line = get_next_line(fd);
    printf("14: %s\n", line ? line : "NULL");
    free(line);

    close(fd);
    close(fd2);
    return 0;
}*/