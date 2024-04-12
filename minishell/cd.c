/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:35:28 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/12 17:31:03 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*findpath(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i] && !ft_strnstr(envp[i], "PWD=", 4))
		;
	return (envp[i] + 4);
}

static int	goahead(char *path)
{
	if (access(path, F_OK))
		return (0);
	return (1);
}

static void	casenotbase(char *path, char **envp)
{
	char	*newpwd;
	char	*oldpwd;

	oldpwd = findpath(envp);
	oldpwd = ft_strjoin(oldpwd, "/");
	newpwd = ft_strjoinfree(oldpwd, path);
	if (goahead(newpwd))
		chdir(newpwd);
	free(newpwd);
}

void	cd(char *fullcmd, char **envp)
{
	if (fullcmd[0] == '/')
	{
		if (goahead(fullcmd))
			chdir(fullcmd);
	}
	else
		casenotbase(fullcmd, envp);
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	cd(av[1], envp);
	return (0);
}
