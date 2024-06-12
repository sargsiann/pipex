/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:31:44 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 12:32:50 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fds[2];
    int i;  

    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
        i = 3;
    else
        i = 2;
    if (argc < 5)
    {
        write(2, "Error: Invalid number of arguments\n", 36);
        return (1);
    }
    if (pipe(fds) == -1)
    {
        write(2, "Error: Pipe error\n", 18);
        return (1);
    }
    init_data_to_pipe(argc, argv);
    while (argv[i + 2] != NULL)
    {
        logic(argv, envp, i);
        i++;
    }
    return (0);
}