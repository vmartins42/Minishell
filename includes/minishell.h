/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:24:32 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/26 14:53:57 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <../libft/libft.h>
# define BUFF_SIZE 1

typedef struct	s_shell
{
	char	**env;
	char	**old_env;
}				t_shell;

int		get_next_line(const int fd, char **line);
void	ft_exit(char **args);
//int		is_builtin(char *elem_tab);
int		check_builtin(char **tab, t_shell *shell, int i);
int		ft_env(char **tab, t_shell *shell);
int		ft_unsetenv(char **tab, t_shell *shell);
int		ft_echo(char **tab, t_shell *shell);
int		ft_error_env(char *elem_tab, char *name, char *error);
int		ft_error_setenv(char *name, char *elem_tab, char *error);
int		ft_cd(char **tab, t_shell *shell, int fast);
int		ft_setenv(char **tab, t_shell *shell, char *resutl, char *temp);
char	*get_env(char *elem_tab, char **env);
int		modify_env(char *name, char *value, t_shell **beginshell);
int		check_env(char **tab);
int		add_or_modif_env(t_shell *shell, char *elem_tab, int i);

#endif
