/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:24:32 by vmartins          #+#    #+#             */
/*   Updated: 2017/11/29 16:32:32 by vmartins         ###   ########.fr       */
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
# include <signal.h>
# include <../libft/libft.h>
# define BUFF_SIZE 50

typedef struct	s_shell
{
	char	**env;
	char	**old_env;
}				t_shell;

int		get_next_line(const int fd, char **line);
void	ft_exit(char **args);
int		check_builtin(char **tab, t_shell *shell);
int		ft_env(char **tab, t_shell *shell);
int		ft_unsetenv(char **tab, t_shell *shell, int j);
int		ft_echo(char **tab, t_shell *shell, int i);
int		ft_error_env(char *elem_tab, char *name, char *error);
int		ft_error_setenv(char *name, char *elem_tab, char *error);
void	ft_cd(char **tab, t_shell *shell, int fast);
int		ft_setenv(char **tab, t_shell *shell, char *resutl, char *temp);
char	*get_env(char *elem_tab, char **env);
int		modify_env(char *name, char *value, t_shell **beginshell);
int		check_env(char **tab);
int		add_or_modif_env(t_shell *shell, char *elem_tab, int i);
int		cd_fast(char **tab, t_shell *shell);
char	*go_link(char *elem, char **env);
char	*back_link(char *elem_tab, char *getenv, int i);
char	*check_link(char *elem_tab, char **env);
int		cd_error(char **tab);
void	cd_adomold(t_shell **beginshell, char *actual_path, char *name);
void	cd_adompwd(t_shell **beginshell, char *actual_path, char *name);
int		check_files(char *elem_tab);
int		process(char **tab, t_shell *shell);
char	*ft_replace_str(char *new_str, char *old);
char	*ft_remove_useless_path(char *str);
void	replace_pwd(t_shell **beginshell, char *pwd);

#endif
