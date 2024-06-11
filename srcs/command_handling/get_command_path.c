/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:33:16 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/11 14:18:35 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static int	find_equal(char	*str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

static void	free_folders(char **folders)
{
	int	i;

	i = 0;
	while (folders[i])
	{
		free(folders[i]);
		i++;
	}
	free(folders);
}

static	char	*search_for_exact(char	*command, char	*folder)
{
	char	**folders;
	int		i;
	char	*path;

	folders = ft_split(folder, ':', 0);
	i = 0;
	while (folders[i])
	{
		path = ft_gstrjoin(folders[i], command, 0, 0);
		if (access(path, F_OK) == 0)
		{
			free_folders(folders);
			return (path);
		}
		free(path);
		i++;
	}
	free_folders(folders);
	return (NULL);
}

char	*get_command_path(char **envp, char *command)
{
	int		i;
	char	*folder;
	char	*path;
	int		equal;

	i = 0;
	folder = NULL;
	path = NULL;
	equal = 0;
	while (envp[i])
	{
		equal = find_equal(envp[i]) + 1;
		folder = ft_substr(envp[i], equal, ft_strlen(envp[i]) - equal);
		if (ft_strncmp(folder, "/usr", 4) == 0)
			path = search_for_exact(command, folder);
		else
			path = ft_gstrjoin(folder, command, 1, 0);
		if (access(path, F_OK) == 0)
		{
			free(folder);
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}
