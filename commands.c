#include "stack_cli.h"

short int	set_mode(t_command *command)
{
	char *mode = command->argv[1];
	if (!ft_strncmp("legacy", mode, 6) || !ft_strncmp("Legacy", mode, 6) || \
			!ft_strncmp("1", mode, 1))
	{
		ft_printf("The mode is now \"LEGACY\"\n");
		return (1);
	}
	else if (!ft_strncmp("order", mode, 5) || !ft_strncmp("Order", mode, 5) || \
			!ft_strncmp("2", mode, 1))
	{
		ft_printf("The mode is now \"ORDER\"\n");
		return (2);
	}
	return (0);
}
