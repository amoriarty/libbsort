/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:59:47 by alegent           #+#    #+#             */
/*   Updated: 2017/05/22 13:59:11 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSORT_H
# define BSORT_H
# include "libft.h"

/* https://en.wikipedia.org/wiki/Block_sort#Outer_Loop */

typedef enum e_bool		t_bool;
enum					e_bool
{
	false,
	true
};

typedef struct s_range	t_range;
struct					s_range
{
	size_t				start;
	size_t				end;
};

t_range					range(size_t start, size_t end);

/*
** sorted function take the two void * being tested by block sort.
** It has to return true parameter are correctly order, false otherwise.
** Example:
**		sorted(void *x, void *y)
**		{
**			int _x = *(int *)x;
**			int _y = *(int *)y;
**
**			return ((_x <= _y) ? true : false);
**		}
**
**		sorted(void *x, void *y)
**		{
**			Person *_x = (Person *)x;
**			Person *_y = (Person *)y;
**
**			return ((_x->age <= _y->age) ? true : false);
**		}
**
**		sorted(void *x, void *b)
**		{
**			char *_x = (char *)x;
**			char *_y = (char *)y;
**
**			return ((strcmp(_x, _y) <= 0) ? true : false);
**		}
*/

void					bsort(void **array, size_t size, t_bool (*sorted)(void *, void *));
size_t					floor_power_of_two(size_t x);
void					rotate(void **array, size_t amount, t_range rng);
void					merge(void **array, t_range a, t_range b, t_bool (*sorted)(void *, void *));
void					insertion_sort(void **array, t_range range, t_bool (*sorted)(void *, void *));
void					reverse(void **array, t_range range);

#endif
