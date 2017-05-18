/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 14:59:14 by alegent           #+#    #+#             */
/*   Updated: 2017/04/26 15:19:38 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			length(const char **split)
{
	int				i;
	int				len;

	i = -1;
	len = 0;
	while (split[++i])
		len += ft_strlen(split[i]);
	return (len);
}

char				*ft_strimp(const char **split, const char c)
{
	int				i;
	int				off;
	char			*str;

	i = -1;
	off = 0;
	if (!(str = ft_strnew(length(split))))
		return (NULL);
	while (split[++i])
	{
		ft_strcpy(str + off, split[i]);
		off += ft_strlen(str + off);
		if (split[i + 1])
			str[off++] = c;
	}
	return (str);
}
