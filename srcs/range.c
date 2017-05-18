/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:05:28 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 12:07:11 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsort.h"

t_range				range(size_t start, size_t end)
{
	t_range			self;

	self.start = start;
	self.end = end;
	return (self);
}