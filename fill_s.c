/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:20:16 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/23 17:20:17 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fill_s(t_s *s, char **argv)
{
	s->pipefd[0] = -1;
	s->pipefd[1] = -1;
	s->path = "PATH=/home/asmkrtch/bin:/home/asmkrtch/bin:"
		"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:"
		"/usr/games:/usr/local/games:/snap/bin";
	s->cmd1_split = NULL;
	s->path1 = NULL;
	s->path2 = NULL;
	s->argv1 = argv[1];
	s->argv2 = argv[2];
	s->argv3 = argv[3];
	s->argv4 = argv[4];
	s->status2 = 0;
}
