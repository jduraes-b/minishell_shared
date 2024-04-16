/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:35:58 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/15 20:55:10 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <assert.h>

typedef struct	s_env
{
	char	*kc;
	char	*value;
	char	*fullstr;
	struct s_env	*next;
}				t_env;

typedef struct	s_shell
{
	char	*line;
	t_env	*env;
}				t_shell;

void	get_env(t_shell *shell, char **envp);

#endif
