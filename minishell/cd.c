/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:46:31 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/16 19:52:45 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	updatepwd(t_shell *shell)
{
    
}

void	noargs(t_shell *shell)
{
	char	*temp;

	temp = keytofull("$HOME", shell);
	if (!chdir(temp))
		cderror();
	else
		newpwd(getcwd(NULL, 0) shell);
	free(temp);
}

void	cd(char **args, t_shell *shell)
{
	if (!args)
		noargs(shell);
}