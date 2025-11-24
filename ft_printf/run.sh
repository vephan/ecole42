#!/bin/bash

cc -c ft_print.c -o ft_print.o 
cc -c ft_write_s.c -o ft_write_s.o 
cc -c ft_write_hex.c -o ft_write_hex.o 
cc -c ft_write_i.c -o ft_write_i.o 
cc -c ft_write_u.c -o ft_write_u.o 
cc -c ft_write_c.c -o ft_write_c.o 

ar rcs libftprintf.a *.c *.o 