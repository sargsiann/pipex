/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_data_to_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:17:46 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 11:16:31 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static  void    put_from_here_doc( char **argv, char *file)
{
    char    *line;
    int     fd;

    line = NULL;
    fd = open(file, O_RDONLY, O_APPEND, O_CREAT, 0644);
    while (1)
    {
        line = get_next_line(0);
        if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
        {
            free(line);
            break ;
        }
        if (write(fd, line, ft_strlen(line)) == -1)
        {
            perror("Error: ");
            exit(1);
        }
        free(line);
    }
        
}

static  void    put_to_file(char *file)
{
    int     fd;
    char    *line;

    fd = open(file, O_RDONLY);
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
        if (write(fd, line, ft_strlen(line)) == -1)
        {
            perror("Error: ");
            exit(1);
        }
        free(line);
    }
}

void    end_data_to_file(char *file, char **argv)
{
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
        put_from_here_doc(argv, file);
    else
        put_to_file(file);
}