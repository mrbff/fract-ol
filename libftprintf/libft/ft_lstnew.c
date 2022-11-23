/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:01:14 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/10 23:29:48 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*uah;

	uah = malloc(sizeof(t_list));
	if (!uah)
		return (NULL);
	uah->content = content;
	uah->next = NULL;
	return (uah);
}
