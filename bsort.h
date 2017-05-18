/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsort.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:59:47 by alegent           #+#    #+#             */
/*   Updated: 2017/05/18 12:25:42 by alegent          ###   ########.fr       */
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
** f function take the two void * being tested by block sort.
** It has to return true parameter are correctly order, false otherwise.
** Example:
**		f(int *x, int *y) {
**			return ((x <= y) ? true : false);
**		}
**		f(Person *x, Person *y) {
**			return ((x->age <= y) ? true : false);
**		}
*/

void					bsort(void **array, size_t size, t_bool (*f)(void *, void *));
size_t					floor_power_of_two(size_t x);
void					rotate(void **array, size_t amount, t_range range);
void					merge(void **array, t_range a, t_range b);
void					insertion_sort(void **array, t_range range, t_bool (*f)(void *, void *));

#endif