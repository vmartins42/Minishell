/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:28:14 by vmartins          #+#    #+#             */
/*   Updated: 2017/11/30 12:07:25 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			prompt(void)
{
	char dir[256];

	ft_putstr(getcwd(dir, sizeof(dir)));
	ft_putstr(" $> ");
}

void			ft_handler_signal(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar('\n');
		prompt();
	}
}

static char		**parse_cmd(void)
{
	char		*line;
	char		*temp;
	char		**tab_cmd_pars;

	line = NULL;
	get_next_line(0, &line);
	if (line != NULL)
	{
		temp = ft_strtrim(line);
		tab_cmd_pars = ft_strsplit(line, ';');
		ft_strdel(&line);
		free(temp);
		return (tab_cmd_pars);
	}
	return (NULL);
}

static int		cmd_multi(t_shell *shell, char **tab_cmd_pars)
{
	char	**tmp;
	int		i;

	i = -1;
	while (tab_cmd_pars[++i])
	{
		tmp = ft_strsplit(tab_cmd_pars[i], ' ');
		if (!check_builtin(tmp, shell))
			return (0);
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
	signal(SIGINT, ft_handler_signal);
	while (status)
	{
		prompt();
		tab_cmd_pars = parse_cmd();
		if (tab_cmd_pars == NULL)
			break ;
		status = cmd_multi(shell, tab_cmd_pars);
	}
	ft_freetab((void**)shell->env, ft_tablen(shell->env));
	ft_freetab((void**)shell->old_env, ft_tablen(shell->old_env));
	free(shell);
	return (0);
}
