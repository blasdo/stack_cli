#include "stack_cli.h"


short	execute(t_command *command)
{
	static short mode = 0;
	ssize_t identifier = command_identifier(mode, command);

	switch (identifier)
	{
		case 0:
			return (0);
		case 1:
			{
				mode = set_mode(command);
				if (mode == 0)
					return (EXCFAIL);
				return (1);
			}
		case 2:
		{
			return(init(command));
		}
		default:
			return (ERRCMD);
	}
}

/*
 * This function ensures that the command exists and its valid
 */

ssize_t	command_identifier(int mode, t_command *command)
{
	if (command->argc > 0)
	{
		if (!ft_strncmp("exit\n", command->argv[0], 4))
			return (0);
		if (mode == 0)
		{
			if (command->argc != 2)
				return (ERRARGS);
			else if (!ft_strncmp(command->argv[0], "mode", 5))
				return (1);
		}
		else if (mode == 1)
			if (!ft_strncmp(command->argv[0], "init", 5 ))
			{
				if (command->argc < 3)
					return (ERRARGS);
				return (2);
			}
	}
	return (ERRARGS);
}


/*
 * Error system
 */
//Non-Critical and correct executions
void	print_in_log(unsigned short cmd_id, int fd)
{
	if (fd == 0)
		fd = 1;
	//is OK
	if (cmd_id <= 128)
	{
		if (fd == 1) // there isn't log
			return;
		if (cmd_id == 1)
			ft_fdprintf(fd, "Mode\n");
		else if (cmd_id == 2)
			ft_fdprintf(fd, "Init\n");
		//print in log
	}
	//is a not critical error
	else
	{

		if (cmd_id == ERRCMD)
		{
			if (fd != 1)
				ft_fdprintf(fd, "WARNING: COMMAND NOT FOUND\n");
			ft_fdprintf(2, "COMMAND NOT FOUND\n");
		}
		if (cmd_id == EXCFAIL)
		{
			if (fd != 1)
				ft_fdprintf(fd, "WARNING: EXECUTION FAILED\n");
			ft_fdprintf(2, "EXECUTION FAILED\n");
		}
		//add all errors
	}
	return ;
}
//critical, ends in exit()
void	error(unsigned short errnum)
{
	(void) errnum;
}
int main(int argc, char *argv[])
{
	char		*line;
	short		cmd_id;
	t_command	*command;
	int			fd = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_CREAT, S_IRWXU);
		close(fd);
		fd = open(argv[1], O_WRONLY);
	}
	while ((line = get_next_line(0)))
	{
		command = split_command(line);
		if (command == NULL)
			error(255);
		cmd_id = execute(command);
		if (cmd_id > 0)
			print_in_log(cmd_id, fd);
		else if (cmd_id < 0)
			error(cmd_id);
		else
			break;
	}
	close(fd);
	return(0);
}
