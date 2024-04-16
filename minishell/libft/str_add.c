/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:35:26 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/12 22:29:29 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**str_add(char **a, char *s, int pos)
{
	int		i;
	int		j;
	int		size;
	char	**new;

	i = 0;
	j = 0;
	size = matlen(a);
	if (pos > (size + 1) || pos < 0)
		return (NULL);
	new = malloc(sizeof(char *) * (size + 2));
	while (i < size + 1)
	{
		if (i == pos)
		{
			new[i] = ft_strdup(s);
			j++;
		}
		else
			new[i] = ft_strdup(a[j]);
		i++;
		j++;
	}
	return (new);
}