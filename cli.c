#include "stack_cli.h"

t_parsed	parser(char **command, int args)
{
	t_parser	to_return;
	to_return->argc = args;
	to_return->argv = ++command;

	if(!ft_strncmp(command[0], "exit\n"), 5)
	{
		to_return->instruct = 0;
	}
	if (!ft_strncmp(command[0], "init", 4))
	{
		if (args < 2)
		{
			nf_error(1);
			return (0);
		}
		to_return->instruct = 1;
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
