/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:29:19 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/13 14:29:19 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strendswith(const char *str, const char *sub)
{
    size_t str_len;
    size_t sub_len;

    str_len = ft_strlen(str);
    sub_len = ft_strlen(sub);
    if (str_len < sub_len)
        return (0);
    return (ft_strcmp(str + (str_len - sub_len), sub) == 0);
}
