/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_carray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:35:31 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/22 20:52:06 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_carray(char ***array, int size)
{
	int	i;

	i = 0;
	while (1)
	{
		if (size != -1 && i >= size)
			break ;
		if (size == -1 && (*array)[i] == NULL)
			break ;
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}
