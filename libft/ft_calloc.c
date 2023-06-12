/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:57:46 by tpiras            #+#    #+#             */
/*   Updated: 2023/05/19 23:14:41 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*alloc;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	alloc = (char *)malloc(count * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, (count * size));
	return (alloc);
}
