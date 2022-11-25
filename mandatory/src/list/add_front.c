/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:58:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 18:03:19 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	add_front(t_list *list, void *content)
{
	t_element	*elm;

	elm = elem_new(content);
	if (!elm)
		return ;
	if (!list->tail)
		list->tail = elm;
	elm->next = list->head;
	if (list->head != NULL)
		list->head->prev = elm;
	list->head = elm;
	list->size++;
}
