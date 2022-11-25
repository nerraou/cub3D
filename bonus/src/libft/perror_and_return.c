/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_and_return.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:13:31 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/19 18:47:05 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	perror_and_return(const char *message, int exit_code)
{
	ft_putendl_fd(message, STDERR_FILENO);
	return (exit_code);
}
