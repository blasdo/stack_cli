#include "stack_cli.h"


char *cmds[] = {"exit", "init", "print", "push", "pop", "help"};

void	free_cmd(t_command *command)
{
	int i = 0;
	while (command->argv[i])
		free(command->argv[i++]);
	free(command->argv);
	free(command);
}


/*
 * This function ensures that the command exists and its valid
 */

ssize_t	command_identifier(t_command *command)
{
	if (command->argc > 0)
	{
		for (int i = 0; cmds[i]; i++)
		{
			if (!ft_strncmp(cmds[i], command->argv[0], ft_strlen(cmds[i])))
				return (i);
		}
	}
	return (ERRCMD);
}
short	execute(t_command *command)
{
	ssize_t identifier = command_identifier(command);
	int			result;

	switch (identifier)
	{
		case 0:
			exit_cli();
		case 1:
		{
			result = init(command);
			if (result == 0)
				return (2);
			else
				return(result);
		}
		case 2:
		{
			result = print_stack(command);
			if  (result != 0)
				return (result);
			return (3);
		}
		case 3:
		{
			result = push_cmd(command);
			if (result != 0)
				return (result);
			return (4);
		}
		case 4:
		{
			result = pop_cmd(command);
			if (result != 0)
				return (result);
			return (5);
		}
		case 5:
		{
			result = print_help(command);
			if (result != 0)
				return (result);
			return (6);
			
		}
		default:
			return (ERRCMD);
	}
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
		else if (cmd_id == 3)
			ft_fdprintf(fd, "Print\n");
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
		if (cmd_id == ERSTACK)
		{
			if (fd != 1)
				ft_fdprintf(fd, "WARNING: STACK NOT FOUND\n");
			ft_fdprintf(2, "STACK NOT FOUND\n");
		}
		if (cmd_id == ERREXIS)
		{
		   if (fd != 1)
			   ft_fdprintf(fd, "WARNING: STACK ALREADY EXISTS\n");
		   ft_fdprintf(2, "STACK ALREDY EXISTS\n");
		}
		if (cmd_id == EREMPTY)
		{
			if (fd != 1)
				ft_fdprintf(fd, "WARNING: STACK IS EMPTY\n");
			ft_fdprintf(2, "STACK IS EMPTY\n");
		}
		if (cmd_id == ERRARGS)
		{
			if (fd != 1)
				ft_fdprintf(fd, "WARNING: INVALID ARGS\n");
			ft_fdprintf(2, "BAD ARGS\n");
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

	if (argc >= 2)
	{
		fd = open(argv[1], O_CREAT, 0644);
	}
	ft_printf("---Stack CLI Alpha 0.2.0 (c)2024 bvelasco under GPLv3---\n");
	line = (void *) 1;
	while (line)
	{
		line = readline("Stack CLI -> ");
		command = split_command(line);
		if (command == NULL)
			error(ERRMEMO);
		cmd_id = execute(command);
		if (cmd_id > 0)
		{
			if (cmd_id < 127)
				add_history(line);
			print_in_log(cmd_id, fd);
		}
		else if (cmd_id < 0)
			error(cmd_id);
		else
			break;
		free_cmd(command);	
		free(line);
		command = 0;
	}
	close(fd);
	exit_cli();
}
