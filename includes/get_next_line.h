/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:31:22 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/28 15:08:49 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFFER_SIZE 1000

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char *one_line_rest(char **rest, int index);
char *read_line(int fd, char **rest);
char *get_next_line(int fd);
char *ft_strjoin_line(char const *s1, char const *s2);
void str_del(char **str);
size_t ft_strclen(const char *s, int param);

#endif
