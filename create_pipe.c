/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:19:40 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/23 17:19:42 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(t_s *s)
{
	if (pipe(s->pipefd) == -1)
	{
		perror("pipe");
		exit (1);
	}
}
