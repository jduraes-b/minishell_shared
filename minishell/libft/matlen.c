/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:13:35 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/12 22:27:28 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_matlen(char **mat)
{
	size_t	i;

	i = 0;
	while (mat[i] != NULL)
		i++;
	return (i);
}