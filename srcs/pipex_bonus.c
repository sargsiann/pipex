/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:14:41 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/08 19:35:29 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


int	main(int argc, char **argv, char **envp)
{
	int		pid;
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
	data = get_initial_data(argv, argc);
	if (data == NULL)
	{
		write(2, "Error: Not enough arguments\n", 28);
		return (1);
	}
	//system("leaks pipex");
}
