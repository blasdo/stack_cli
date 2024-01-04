#include "stack_cli.h"

// testeo debil
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

// no se ha testeado
short int	init(t_command *command)
{
	size_t	i;
	int		*content;
	t_list 	*result = NULL;
	t_list	*tmp;

	i = 2;
	while (i < command->argc)
	{
		content = malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(&result, free);
			return(-1);
		}
		*content = ft_atoi(command->argv[i]);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			ft_lstclear(&result, free);
			free(content);
			return (-1);
		}
		ft_lstadd_back(&result, tmp);
		i++;
	}
	tmp = (t_list *)newstack(command->argv[1], result);
	if (!tmp)
	{
		ft_lstclear(&result, free);
		return (-1);
	}
	return (0);
}
//print_stack command
short int	print_stack(t_command command)
{}