/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:13:25 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 17:41:54 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

void				rotate(void **array, size_t amount, t_range rng)
{
	reverse(array, rng);
	reverse(array, range(rng.start, rng.start + amount));
	reverse(array, range(rng.start + amount, rng.end));
}
