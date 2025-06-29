/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:21:27 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/23 17:21:29 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_s
{
	int		input_fd;
	int		output_fd;
	char	**cmd1_split;
	char	**cmd2_split;
	int		checker1;
	int		checker2;
	char	*full_path;
	char	**paths;
	char	*path1;
	char	*path2;
	int		i;
	int		pipefd[2];
	char	*path;
	int		status2;
	int		status1;
	char	*argv2;
	char	*argv3;
	char	*argv1;
	char	*argv4;
	pid_t	pid1;
	pid_t	pid2;
}	t_s;

//error.c
void	error_children1_1(t_s *s);
void	error_children1_2(t_s *s);
void	error_children2_1(t_s *s);
void	error_children2_2(t_s *s);
void	error_children2_3(char **env);

void	fill_s(t_s *s, char **argv);
// new 
char	*ft_check_env(char **env);
void	ft_path_pass(t_s *s, char **env);

// pipe.c // for working with pipe
void	create_pipe(t_s *s);

// free.c
void	free_split(char **arr);

// find_path.c // for find full cmd path
char	*find_path(t_s *s, char *cmd);

// ft_pipex.c
void	pipex(t_s *s, char **env);

#endif
