#include "stack_cli.h"

void		execute(t_parsed command, int args)
{
	(void) args;
	if (command.instruct == 0)
		exit(0);
}

t_parsed	parser(char **command, int args)
{
	t_parsed	to_return;
	to_return.argc = args;
	to_return.argv = ++command;

	if(!ft_strncmp(command[0], "exit\n", 5))
	{
		to_return.instruct = 0;
	}
	if (!ft_strncmp(command[0], "init", 4))
	{
		if (args < 3)
		{
			ft_fdprintf(2, "Too few arguments: 'init STACK_ID [CONTENT_1 ...]', if need more info use 'help init'\n");
			return (0);
		}
		to_return.instruct = 1;
	}
	return (to_return);
}

int main()
{
	char	*line;
	char	**command;
	int		args;

	while ((line = get_next_line(0)))
	{
		command = ft_split(line, ' ');
		args = args_counter(command);
		execute(parser(command, args));
	}
	return(0);
}
