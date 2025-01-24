/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:45:23 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/06 15:07:00 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	out = malloc(nmemb * size);
	if (!out)
		return (out);
	ft_bzero(out, nmemb * size);
	return (out);
}
