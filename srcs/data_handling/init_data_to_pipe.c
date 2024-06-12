/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_to_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:59:08 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 11:18:07 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static int  get_from_here_doc(char *limiter)
{
    char    *line;

    line = NULL;
    while (1)
    {
        line = get_next_line(0);
        if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
        {
            free(line);
            break ;
        }
        if (write(STDIN_FILENO, line, ft_strlen(line)) == -1)
        {
            write(2, "Error: Write error\n", 20);
            exit(1);
        }
        free(line);
    }
    return (0);
}

static int  get_from_file(char *file)
{
    int     fd;
    char    *line;

    fd = open(file, O_RDWR);
    if (fd == -1)
    {
        perror("Error: ");
        exit(1);
    }
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        if (write(STDIN_FILENO, line, ft_strlen(line)) == -1)
        {
            perror("Error: ");
            exit(1);
        }
        free(line);
    }
    close(fd);
    return (0);
}

void    init_data_to_pipe(int argc, char **argv)
{
    if (ft_strncmp("here_doc", argv[2], 8) == 0)
    {
        if (argc < 6)
        {
            write(2, "Error: Invalid number of arguments\n", 36);
            exit(1);
        }
        get_from_here_doc(argv[3]);
    }
    else
    {
        if (argc < 5)
        {
            write(2, "Error: Invalid number of arguments\n", 36);
            exit(1);
        }
        get_from_file(argv[2]);
    }
}