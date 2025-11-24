/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:24:42 by vephan            #+#    #+#             */
/*   Updated: 2025/10/08 10:48:26 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned int	i;
	long			val;

	while (*nptr && (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == ' ')))
		nptr++;
	i = 0;
	sign = 1;
	while (*nptr && ((*nptr == '-') || (*nptr == '+')))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
		i++;
	}
	if (i >= 2)
		return (0);
	i = 0;
	val = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		val = val * 10 + (int) nptr[i] - 48;
		i++;
	}
	return (sign * val);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	//tested OK
//char *s = "\e100\n";//"-2147483648";
//char *s1 = "\t\n\r\v\f111\n";//"-2147483648";
//char *s11 = "\t\n\r\v\f-111\n";//"-2147483648";
//char *s2 = "  200\n";//"-2147483648";
//char *s3 = "-300\n";//"-2147483648";
//char *s4 = "+400\n";//"-2147483648";
//char *s5 = "*500\n";//"-2147483648";
//char *s6 = "/600\n";//"-2147483648";
//char *s7 = "ndfdd700\n";//"-2147483648";
//char *s8 = "--800";//"-2147483648";
//char *s9 = "++900";//"-2147483648";
//char *s10 = "12345ceef56449";//"-2147483648";

	char *s = "546:5";
	char *s1 = "945";
	char *s11 = "-085";
	char *s2 = "\t\v\f\r\n \f-06050";
	char *s3 = "-123THERE IS A NYANCAT UNDER YOUR BED";
	char s4[15] = "2147483647";
	char s5[15] = "-2147483648";
	char s6[40] = "+1234";
	char s7[40] = "+1234sdeenr245";

	int	r1;
	int r2;

	// control char - before, after
	// printable chr - punctuation, sign (-, +, * /), space,  	
	r1 = atoi(s);
	r2 = ft_atoi(s);
	printf("atoi %d f_atoi %d s %s \n", r1, r2, s);
	r1 = atoi(s1);
	r2 = ft_atoi(s1);
	printf("atoi %d ft_atoi %d s %s \n", r1, r2, s1);
	r1 = atoi(s11);
	r2 = ft_atoi(s11);
	printf("atoi %d ft_atoi %d s %s \n", r1, r2, s11);
	r1 = atoi(s2);
	r2 = ft_atoi(s2);
	printf("atoi %d ft_atoi %d s %s \n", r1, r2, s2);
	r1 = atoi(s3);
	r2 = ft_atoi(s3);
	printf("atoi %d ft_atoi %d s %s \n", r1, r2, s3);
	r1 = atoi(s4);
	r2 = ft_atoi(s4);
	printf("atoi %d ft_atoi %d s %s \n", r1, r2, s4);
	r1 = atoi(s5);
	r2 = ft_atoi(s5);
	printf("atoi %d ft_atoi %d s %s \n", r1, r2, s5);
	r1 = atoi(s6);
	r2 = ft_atoi(s6);
	printf("atoi %d ft_atoi %d s %s \n", r1, r2, s6);
	r1 = atoi(s7);
	r2 = ft_atoi(s7);
	printf("atoi %d ft_atoi %d s %s \n", r1, r2, s7);
//r1 = atoi(s8);
//r2 = ft_atoi(s8);
//printf("atoi %d ft_atoi %d s %s \n", r1, r2, s8);
//r1 = atoi(s9);
//r2 = ft_atoi(s9);
//printf("atoi %d ft_atoi %d s %s \n", r1, r2, s9);
//r1 = atoi(s10);
//r2 = ft_atoi(s10);
//printf("atoi %d ft_atoi %d s %s \n", r1, r2, s10);
	return (0);
}*/