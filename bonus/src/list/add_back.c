/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:57:56 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 18:03:10 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	add_back(t_list *list, void *content)
{
	t_element	*elm;

	elm = elem_new(content);
	if (!elm)
		return ;
	if (!list->head)
		list->head = elm;
	if (!list->tail)
		list->tail = elm;
	else
	{
		list->tail->next = elm;
		elm->prev = list->tail;
		list->tail = elm;
	}
	list->size++;
}
