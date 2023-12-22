#include "stack_cli.h"

void		execute(t_command command, int args)
{
	(void) args;
	if (command.instruct == 0)
		exit(0);
}

/*
 * This function ensures that the command exists and its valid
 */

ssize_t	command_identifier(int mode, const t_command *command)
{
	if (command->argc > 0)
	{
		if (!ft_strncmp("exit\n", command->argcv[1]))
			return (0);
		if (mode == 0)
		{
			if (command->args == 2)
				if (!ft_strncmp(command->argv[0], "mode", 5);
					return (1);
		}
		else if (mode == 1)
			if (ft_strncmp(
	}
	else
		return (ERRARGS)
}

int main()
{
	char	*line;
	char	**command;
	int		args;

	while ((line = get_next_line(0)))
	{
		command = ft_split_cmd(line, ' ');
		args = args_counter(command);
		execute(parser(command, args));
	}
	return(0);
}
