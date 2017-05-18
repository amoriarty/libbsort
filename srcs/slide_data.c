/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:55:48 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 15:56:59 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

void			slide_data(void **array, size_t index, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size && array[i])
		i += 1;
	while (i > index)
	{
		array[i] = array[i - 1];
		i -= 1;
	}
}
