/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:34:38 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/20 16:02:20 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <math.h>

typedef struct s_tuplef
{
	float value1;
	float value2;
} t_tuplef;

int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_strcmp(const char *s1, const char *s2);
int ft_indexof(const char *str, int c);
int ft_atoi(const char *str);
int ft_isspace(int c);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int wcount(char const *s, char c);
int is_long(const char *str);
int ft_tolower(int c);

char *ft_strctrim(const char *str, char c);
int ft_strendswith(const char *str, const char *sub);
char *ft_strctrimend(const char *str, char c);
int is_string_rgb(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strncpy(char *dest, const char *src, size_t n);
char *ft_strdup(const char *s);
char *ft_itoa(int n);
char *ft_strjoin(char const *s1, char const *s2);

char **ft_split(char const *s, char c);

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

void *ft_memset(void *s, int c, size_t n);
void *ft_malloc(size_t size);
void *ft_memcpy(void *dst, const void *src, size_t n);

void ft_putendl_fd(const char *s, int fd);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(const char *s, int fd);

long ft_atol(const char *str);

float distance(float start_x, float start_y, float end_x, float end_y);
float normalize_angle(float angle);
int perror_and_return(const char *message, int exit_code);

#endif
