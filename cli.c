#include "stack_cli.h"

t_stack	*stacks = NULL;

short	execute(t_command *command)
{
	static short mode = 0;
	ssize_t identifier = command_identifier(mode, command);

	switch (identifier)
	{
		case 0:
			return (0);
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
		//print in log
	}
	//is a not critical error
	else
	{

		if (cmd_id == ERRCMD)
		{
			if (fd != 1)
				ft_fdprintf(fd, "WARNING: COMMAND NOT FOUND\n");
			else
				ft_fdprintf(2, "COMMAND NOT FOUND\n");
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
		if (ft_isnumber(argv[1], 0))
			fd = ft_atoi(argv[1]);
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
	return(0);
}
