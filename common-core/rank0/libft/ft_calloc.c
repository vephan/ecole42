/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:30:26 by vephan            #+#    #+#             */
/*   Updated: 2025/10/07 16:46:26 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned long	totalsize;

	totalsize = (long)(nmemb * size);
	if (totalsize >= 2147483648 || (size > sizeof(long)))
		return (NULL);
	ptr = malloc(nmemb * size);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/*

#include <stdio.h>

int main(void)
{
	
	int size = 8539;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	if (memcmp(d1, d2, size * sizeof(int)))
		exit(0);
	free(d1);
	free(d2);
	exit(1);

    int *arr;
    int i;
    int size = 2147483647;

    // Allocate memory for 5 integers and initialize to 0
    arr = (int *)ft_calloc(size, sizeof(int));
	printf("arr %p\n", arr);
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print the initialized values
    for (i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}*/
