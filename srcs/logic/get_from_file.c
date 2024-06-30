/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:55:10 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/30 17:16:51 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	handle_input_file(int argc, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_error(FILE_OPEN_ERR, FILE_OPEN_STAT);
	handle_commands(infile, argv + 2, argv[argc - 1], envp);
}
