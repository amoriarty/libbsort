/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:59:47 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 11:10:42 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSORT_H
# define BSORT_H
# include "libft.h"

typedef enum e_bool		t_bool;
enum					e_bool
{
	false,
	true
};

t_bool					bsort(void **array, size_t size, t_bool (*f)(void *));

#endif