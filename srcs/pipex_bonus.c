/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:14:41 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/08 15:21:35 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	int		pid;
	int		fds[2];
	int		i;
	char	*data;

	i = 0;
	data = NULL;
	pid = 0;
	if (argc < 5)
	{
		write(2, "Error: Not enough arguments\n", 28);
		return (1);
	}
	if (pipe(fds) == -1)
	{
		perror("pipe");
		return (1);
	}
	data = get_initial_data(argv);
	printf("%s", data);
	//while (argv[i + 1] != NULL)
	//{
	//	if (pid == -1)
	//	{
	//		perror("fork");
	//		return (1);
	//	}
	//	i++;
	//}
}
