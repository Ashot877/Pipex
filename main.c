/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:20:46 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/06/23 17:20:53 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_s	s;

	if (argc != 5)
	{
		perror("Invalid arguments");
		return (1);
	}
	fill_s(&s, argv);
	create_pipe(&s);
	ft_path_pass(&s, env);
	pipex(&s, env);
	return (0);
}
