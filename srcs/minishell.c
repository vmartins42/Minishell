/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:28:14 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/20 14:47:10 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			prompt(t_shell *shell)
{
	(void)shell;
	char dir[256];

	ft_putendl(getcwd(dir, sizeof(dir)));
	ft_putstr("$> ");
	//ft_putstr(dir);
}

static char		**parse_cmd(void)
{
	char		*line;
	char		*temp;
	char		**tab_cmd_pars;

	get_next_line(0, &line);
	temp = ft_strtrim(line);
	tab_cmd_pars = ft_strsplit(line, ';');
	ft_strdel(&line);
	free(temp);
	return (tab_cmd_pars);
}

static int		cmd_multi(t_shell *shell, char **tab_cmd_pars)
{
	char	**tmp;
	int		i;

	i = -1;
	while (tab_cmd_pars[++i])
	{
		tmp = ft_strsplit(tab_cmd_pars[i], ' ');
		if (/*is_builtin(tmp[0])*/!check_builtin(tmp, shell, 0))
			return (0);
		//check_builtin(tmp[0], tmp, shell, 0);
		ft_freetab((void**)tmp, ft_tablen(tmp));
	}
	ft_freetab((void**)tab_cmd_pars, ft_tablen(tab_cmd_pars));
	return (1);
}

int				main(void)
{
	t_shell			*shell;
	extern char		**environ;
	int				status;
	char			**tab_cmd_pars;

	status = 1;
	shell = (t_shell *)malloc(sizeof(t_shell));
	shell->env = ft_tabdup(environ);
	shell->old_env = ft_tabdup(environ);
	while (status)
	{
		prompt(shell);
		tab_cmd_pars = parse_cmd();
		status = cmd_multi(shell, tab_cmd_pars);
	}
	ft_freetab((void**)shell->env, ft_tablen(shell->env));
	ft_freetab((void**)shell->old_env, ft_tablen(shell->old_env));
	free(shell);
	return (0);
}
