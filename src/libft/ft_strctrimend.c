/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrimend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:29:07 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/13 14:29:12 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strctrimend(const char *str, char c)
{
    size_t len;

    len = ft_strlen(str);
    if (len == 0)
        return (ft_strdup(""));
    len--;
    while (len != 0 && str[len] == c)
        len--;
    if (len == 0)
        return (ft_strdup(""));
    return (ft_substr(str, 0, len + 1));
}
