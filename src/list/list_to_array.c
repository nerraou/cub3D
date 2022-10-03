/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:22:20 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/03 09:22:59 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

char **list_to_array(const t_list *list)
{
	t_element *cur;
	char **array;
	int i;

	array = (char **)malloc(sizeof(char *) * list->size);
	cur = list->head;
	i = 0;
	while (cur != NULL)
	{
		array[i] = (char *)cur->content;
		cur = cur->next;
		i++;
	}
	return (array);
}
