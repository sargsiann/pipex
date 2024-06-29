/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:39:57 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/29 14:37:58 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *message, int exit_status)
{
	write(2, message, ft_strlen(message));
	exit(exit_status);
}

void	get_from_here_doc(int fds[2], char *limiter)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(fds[1], line, ft_strlen(line));
		free(line);
	}
	close(fds[1]);
}

void	handle_here_doc(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	infile;

	if (pipe(pipefd) == -1)
		ft_error(PIPE_CREATE_ERR, PIPE_CREATE_STAT);
	if (fork() == 0)
	{
		close(pipefd[0]);
		get_from_here_doc(pipefd, argv[2]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);
	wait(NULL);
	infile = pipefd[0];
	handle_commands(infile, argv + 3, argc - 4, argv[argc - 1], envp);
}

void	handle_input_file(int argc, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_error(FILE_OPEN_ERR, FILE_OPEN_STAT);
	handle_commands(infile, argv + 2, argc - 3, argv[argc - 1], envp);
}

void	handle_commands(int infile, char **cmds, int cmd_count, char *outfile, char **envp)
{
	int	pipefd[2];
	int	i;
	int	prev_pipe;

	prev_pipe = infile;
	i = 0;
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

	if ((pid = fork()) == -1)
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
		close(input_fd);
}

void	execute_last_command(int input_fd, char *outfile, char *cmd, char **envp)
{
	int		output_fd;
	pid_t	pid;

	output_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		ft_error(FILE_OPEN_ERR, FILE_OPEN_STAT);
	if ((pid = fork()) == -1)
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
		waitpid(pid, NULL, 0);
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
		ft_error(CMD_NOT_FOUND_ERR, CMD_NOT_FOUND_STAT);
	if (execve(command_path, args, envp) == -1)
		ft_error(EXEC_ERR, EXEC_STAT);
}


int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		write(2, "Usage: ./pipex [here_doc LIMITER | infile] cmd1 ... cmdn outfile\n", 64);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "here_doc") == 0)
		handle_here_doc(argc, argv, envp);
	else
		handle_input_file(argc, argv, envp);
	return (0);
}
