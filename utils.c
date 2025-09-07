#include "libft/include/libft.h"
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

char *get_next_word(char *cmd, size_t *startpos)
{
	size_t spos = *startpos;
	size_t epos;

	while(cmd[spos] != '\0' && ft_isspace(cmd[spos]))
		spos++;
	epos = spos;
	while (cmd[epos] != '\0' && !ft_isspace(cmd[epos]))
			epos++;
	*startpos = epos;
	return ft_substr(cmd, spos, epos - spos);
}

t_command	*split_command(char *cmd)
{
	t_command	*result = malloc(sizeof(t_command));
	size_t			i = 0;
	size_t			j = 0;

	if (!result)
		return (0);
	result->argc = count_args(cmd);
	result->argv = calloc(sizeof(char **), (result->argc + 1));
	for (; i < result->argc; ++i)
	{
		result->argv[i] = get_next_word(cmd, &j);
	}
	return (result);
}
/*
 * End of reimplementation of ft_split
 */
