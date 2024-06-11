/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:50:26 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/11 14:38:32 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	to(char **argv, int index, int fds[2], char **envp)
{
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	exec_command(argv[index + 1], envp, fds);
}