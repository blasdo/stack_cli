#include "stack_cli.h"
#include "string.h"

/*
 * reimplementation of ft_split but returns a struct
 * that includes the number of words (arguments of command)
 */
static size_t	count_args(char *cmd)
{
	int	i = 0;
	int	in_word = 0;
	size_t words = 0;

	while (cmd[i] != 0)
	{
		if (!in_word && !(cmd[i] == ' '))
		{
			in_word = 1;
			words++;
		}
		else if(in_word && cmd[i] == ' ')
			in_word = 0;
		i++;
	}
	return (words);
}

t_command	*split_command(char *cmd)
{
	t_command	*result = malloc(sizeof(t_command));
	size_t			i = 0;
	size_t			j = 0;
	size_t			k;

	if (!result)
		return (0);
	result->argc = count_args(cmd);
	result->argv = malloc(sizeof(char **) * (result->argc + 1));
	for (; i < result->argc; ++i)
	{
		for (; cmd[j] == ' '; ++j);
		k = j;
		for (; cmd[k] != '\0' && cmd[k] != ' '; ++k);
		result->argv[i] = ft_substr(cmd, j, k-j);
		j = ++k;
	}
	return (result);
}
/*
 * End of reimplementation of ft_split
 */
