/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:21:03 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/23 17:21:04 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	children_1(t_s *s, char **env)
{
	int		input_fd;

	if (s->pipefd[0] >= 0)
		close(s->pipefd[0]);
	input_fd = open(s->argv1, O_RDONLY);
	if (input_fd < 0)
		error_children1_1(s);
	dup2(input_fd, 0);
	dup2(s->pipefd[1], 1);
	if (s->pipefd[1] >= 0)
		close(s->pipefd[1]);
	if (input_fd >= 0)
		close(input_fd);
	if (!s->cmd1_split || !s->cmd1_split[0] || s->cmd1_split[0][0] == '\0')
		error_children1_2(s);
	s->path1 = find_path(s, s->cmd1_split[0]);
	if (!s->path1)
		error_children1_2(s);
	execve(s->path1, s->cmd1_split, env);
	free_split(s->cmd1_split);
	perror("execve:");
	free(s->path1);
	exit(2);
}

void	children_2(t_s *s, char **env)
{
	int		output_fd;

	if (s->pipefd[1] >= 0)
		close(s->pipefd[1]);
	output_fd = open(s->argv4, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd < 0)
		error_children2_1(s);
	dup2(s->pipefd[0], 0);
	dup2(output_fd, 1);
	if (s->pipefd[0] >= 0)
		close(s->pipefd[0]);
	if (output_fd >= 0)
		close(output_fd);
	if (!s->cmd2_split || !s->cmd2_split[0] || s->cmd2_split[0][0] == '\0')
		error_children2_3(env);
	s->path2 = find_path(s, s->cmd2_split[0]);
	if (!s->path2)
		error_children2_2(s);
	execve(s->path2, s->cmd2_split, env);
	free_split(s->cmd2_split);
	perror("execve:");
	free(s->path2);
	exit(2);
}

void	pipex(t_s *s, char **env)
{
	s->cmd1_split = ft_split(s->argv2, ' ');
	s->cmd2_split = ft_split(s->argv3, ' ');
	if (!s->cmd1_split || !s->cmd2_split)
	{
		perror("ft_split");
		free_split(s->cmd1_split);
		free_split(s->cmd2_split);
		exit(1);
	}
	s->pid1 = fork();
	if (s->pid1 == 0)
		children_1(s, env);
	s->pid2 = fork();
	if (s->pid2 == 0)
		children_2(s, env);
	if (s->pipefd[0] >= 0)
		close(s->pipefd[0]);
	if (s->pipefd[1] >= 0)
		close(s->pipefd[1]);
	waitpid(s->pid1, &s->status1, 0);
	waitpid(s->pid2, &s->status2, 0);
	free_split(s->cmd1_split);
	free_split(s->cmd2_split);
	exit(s->status2 >> 8);
}
