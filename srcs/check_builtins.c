/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:54:59 by vmartins          #+#    #+#             */
/*   Updated: 2017/10/30 12:32:00 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_builtin(char **tab, t_shell *shell, int i)
{
	(void)i;
	if (!tab[0])
		return (1);
	if (cd_fast(tab, shell))
		return (1);
	if (ft_strcmp(tab[0], "cd") == 0)
		return (ft_cd(tab, shell, 0));
	else if (ft_strcmp(tab[0], "exit") == 0)
		return (0);
	else if (ft_strcmp(tab[0], "env") == 0)
		return (ft_env(tab, shell));
	else if (ft_strcmp(tab[0], "unsetenv") == 0)
		return (ft_unsetenv(tab, shell, -1));
	else if (ft_strcmp(tab[0], "echo") == 0)
		return (ft_echo(tab, shell, 0));
	else if (ft_strcmp(tab[0], "setenv") == 0)
		return (ft_setenv(tab, shell, NULL, NULL));
	return (process(tab, shell));
}

static char	**parse_process(char **env)
{
	char	**process;
	char	*path;
	int		i;

	i = -1;
	if ((path = get_env("PATH", env)) == NULL)
		return (NULL);
	process = ft_strsplit(path, ':');
	while (process[++i])
		process[i] = ft_strjoin(process[i], "/");
	ft_strdel(&path);
	return (process);
}

static int	execute_process(char **tab, char **env)
{
	char	**process;
	char	*line;
	int		i;
	int		size;

	i = 0;
	if ((process = parse_process(env)) == NULL)
		return (0);
	size = ft_tablen(process);
	while (process[i])
	{
		if (execve(tab[0], tab, env) != -1)
			return (1);
		line = ft_strjoin(process[i], tab[0]);
		if (execve(line, tab, env) == -1 && i != size)
			i++;
		else
			return (1);
	}
	return (0);
}

int			process(char **tab, t_shell *shell)
{
	pid_t	father;

	if (ft_theirisnothing(tab[0]))
		return (1);
	father = fork();
	if (father == 0)
	{
		if (!execute_process(tab, shell->env))
			ft_error_env(tab[0], "minishell: ", "command not found: ");
		exit(EXIT_FAILURE);
	}
	else
		wait(0);
	return (1);
}
