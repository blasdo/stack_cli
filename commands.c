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
	return (0);
}

// no se ha testeado
short int	init(t_command *command)
{
	size_t	i;
	int		*content;
	t_list 	*result = NULL;
	t_list	*tmp;
	char	*name_without_nl = ft_strtrim(command->argv[1], "\n ");

	if (!name_without_nl)
		return (ERRMEMO);
	if (stack_finder(name_without_nl))
		return (ERREXIS);
	i = 2;
	while (i < command->argc)
	{
		content = malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(&result, free);
			return(ERRMEMO);
		}
		*content = ft_atoi(command->argv[i]);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			ft_lstclear(&result, free);
			free(content);
			return (ERRMEMO);
		}
		ft_lstadd_back(&result, tmp);
		i++;
	}
	tmp = (t_list *)newstack(name_without_nl, result);
	if (!tmp)
	{
		ft_lstclear(&result, free);
		return (ERRMEMO);
	}
	free(name_without_nl);
	return (0);
}

//print_stack command
short int	print_stack(t_command *command)
{
	t_stack	*to_print;
	char	*name_without_nl = ft_strtrim(command->argv[1], "\n ");

	if (!name_without_nl)
		return (ERRMEMO);
	to_print = stack_finder(name_without_nl);
	if (!to_print)
	{
		return(ERSTACK);
	}
	ft_printf("%s\n---\n", to_print->identifier);
	ft_lstiter(to_print->stack, print_node);
	write(1, "---\n", 4);
	free(name_without_nl);
	return (0);
}

short int	push_cmd(t_command *command)
{
	char	*identifier = command->argv[1];
	int		to_push = ft_atoi(command->argv[2]);

	return (push(identifier, to_push));
}
short int pop_cmd(t_command *command)
{
	int res;
	char *identifier = ft_strtrim(command->argv[1], "\n ");
	if (!identifier)
		return (ERRMEMO);
	res = pop(identifier);
	free (identifier);
	return (res);
}

short int print_help(t_command *command)
{
	(void) command;
	return 0;
}