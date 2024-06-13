/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:39:57 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/13 21:25:10 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		write(2, "argument is missing", 20);
		return (1);		
	}
	logic(argv, envp, argc);
}
