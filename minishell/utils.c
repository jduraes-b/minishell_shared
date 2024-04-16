/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:20:24 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/16 19:49:49 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 


static char	*splitenv(char	*str, int type)
{
	int		i;
	char	*r;
	int		j;
	
	i = 0;
	while (str[i] != '=')
		i++;
	j = i - 1;
	if (type != 1)
	{
		i = ft_strlen(str) - i - 1;
		j = ft_strlen(str) - 1;
	}
	r = malloc(sizeof(char) * i);
	r[i--] = '\0';
	while (i >= 0)
	{
		r[i--] = str[j];
		j--;
	}
	return (r);
}
void	get_env(t_shell *shell, char **envp)
{
	t_env	*env;
	t_env	*root;
	int			i;

	i = 0;
	while (envp[i] != NULL)
	{
		env = ft_calloc(1, sizeof(t_env));
		env->kc = splitenv(envp[i], 1);
		env->value = splitenv(envp[i], 2);
		env->fullstr = ft_strdup(envp[i]);
		if (i == 0)
			root = env;
		env->root = root;
			env = env->next;
			i++;
	}
	shell->env = root;
	env->next = NULL;
}

char	*keytofull(char *key, t_shell *shell)
{
	t_env    *env;

	env = shell->env;
	while (env != NULL)
	{
		if (ft_strcmp(env->kc, key) == 0)
			return (ft_strdup(env->fullstr));
		env = env->next;
	}
	return (NULL);
}

void	newpwd(char *pwd, t_shell *shell)
{
	t_env	*env;

	env = shell->env;
	while (env != NULL)
	{
		if (ft_strcmp(env->kc, "$PWD") == 0)
		{
			free(env->value);
			free(env->fullstr);
			env->value = ft_strdup(pwd + 5);
			env->fullstr = ft_strdup(pwd);
		}
		env = env->next;
	}
}

/*
int	main(int argc, char **argv, char **envp)
{
	t_shell *shell;
	(void)argc;
	(void)argv;

	shell = calloc(1, sizeof(t_shell));
	get_env(shell, envp);
	while(shell->env->next != NULL)
		printf("%s=%s\n", shell->env->kc, shell->env->value);
	return (0);
}*/
