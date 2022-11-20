/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:01:52 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/19 18:43:44 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include "libft.h"

typedef struct s_element
{
	void *content;
	struct s_element *next;
	struct s_element *prev;
} t_element;

typedef struct s_list
{
	t_element *head;
	t_element *tail;
	int size;
} t_list;

void add_front(t_list *list, void *content);
void add_back(t_list *last, void *content);
void list_del(t_list **lst, void (*del)(void *));
void list_del_noop(void *content);

char **list_to_array(const t_list *list);

t_element *elem_new(void *content);

t_list *list_new(void);

#endif
