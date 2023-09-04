/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:18:14 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/10 13:50:42 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Add a new link to the end of a linked list
/// @param lst pointer to the head node of the list
/// @param  new the new node to add to the list
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*end;

	end = ft_lstlast(*lst);
	if (!end)
		*lst = new_node;
	else
		end->next = new_node;
}

/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	end = ft_lstlast(*lst);
	end->next = new;
}
*/