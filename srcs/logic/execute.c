/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:21:37 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/30 17:26:13 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	handle_commands(int infile, char **cmds, char *outfile, char **envp)
{
	int	pipefd[2];
	int	i;
	int	prev_pipe;
	int	cmd_count;

	prev_pipe = infile;
	i = 0;
	cmd_count = get_command_count(cmds);
	while (i < cmd_count)
	{
		if (pipe(pipefd) == -1)
			ft_error(PIPE_CREATE_ERR, PIPE_CREATE_STAT);
		execute_command(prev_pipe, pipefd[1], cmds[i], envp);
		close(pipefd[1]);
		prev_pipe = pipefd[0];
		i++;
	}
	execute_last_command(prev_pipe, outfile, cmds[cmd_count - 1], envp);
}

void	execute_command(int input_fd, int output_fd, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if ((pid) == -1)
		ft_error(FORK_CREATE_ERR, FORK_CREATE_STAT);
	if (pid == 0)
	{
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		close(input_fd);
		execve_command(cmd, envp);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(input_fd);
		close(output_fd);
	}
}

void	execute_last_command(int input_fd, char *outfile,
			char *cmd, char **envp)
{
	int		output_fd;
	pid_t	pid;

	pid = fork();
	output_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		ft_error(FILE_OPEN_ERR, FILE_OPEN_STAT);
	if (pid == -1)
		ft_error(FORK_CREATE_ERR, FORK_CREATE_STAT);
	if (pid == 0)
	{
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		close(input_fd);
		close(output_fd);
		execve_command(cmd, envp);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(input_fd);
		close(output_fd);
		exit(get_status(pid));
	}
}

void	execve_command(char *cmd, char **envp)
{
	char	*command_path;
	char	**args;
	char	*command;

	command = get_command(cmd);
	command_path = get_command_path(envp, command);
	args = get_com_args(cmd);
	if (command_path == NULL)
	{
		free(command);
		free(args);
		ft_error(CMD_NOT_FOUND_ERR, CMD_NOT_FOUND_STAT);
	}
	if (execve(command_path, args, envp) == -1)
	{
		free(command);
		free(args);
		free(command_path);
		ft_error(EXEC_ERR, EXEC_STAT);
	}
}
