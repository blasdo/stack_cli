#ifndef STACK_CLI_H
# define STACK_CLI_H

#include <libft.h>
#define ERRINEX 255
#define ERRARGS 254

typedef struct s_stack
{
	char	identifier[10];
	t_list	stack;
}				t_stack;
typedef struct	s_command
{
	size_t	argc;
	char	**argv;
}				t_command;

t_stack	*stacks = NULL;

int			main(int argc, char *argv[]);
void		executer(t_command command, int args);
ssize_t		command_identifier(int mode, const t_command command);

#endif
