/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:03:37 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 22:30:22 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Frees the content in the node lst and frees the node.
/// @param lst The node to free
/// @param del address of function used to delte the content
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
		del(lst->content);
	free(lst);
}
