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
				if (!ft_strncmp(command->argv[0], "mode", 5))
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
	//is OK
	if (cmd_id <= 128)
	{
		//print in log
	}
	//is a not critical error
	else
	{

		if (cmd_ID == ERRCMD)
		{
			if (fd)
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

}
int main(int argc, char *argv[])
{
	char		*line;
	short		cmd_id;
	t_command	*command;
	int			fd;

	if (argc == 2)
		if (ft_isnumber(argv[1]))
			fd = ft_atoi(argv[1]);
	while ((line = get_next_line(0)))
	{
		command = split_command(line);
		if (command == NULL)
			error(255);
		cmd_id = execute(command);
		if (cmd_id > 0)
			print_in_log(cmd_id);
		else if (cmd_id < 0)
			error(cmd_id);
		else
			break;
	}
	return(0);
}
