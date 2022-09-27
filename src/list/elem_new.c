/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:58:13 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/27 11:58:14 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_element *elem_new(void *content)
{
	t_element *new_elm;

	new_elm = (t_element *)ft_malloc(sizeof(t_element));
	if (!new_elm)
		return (NULL);
	new_elm->content = content;
	return (new_elm);
}
