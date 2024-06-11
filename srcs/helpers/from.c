/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:49:36 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/11 14:38:49 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	from(char **argv, int index, int fds[2], char **envp)
{
	close(fds[0]);
	dup2(fds[1], STDOUT_FILENO);
	exec_command(argv[index], envp, fds);
}
