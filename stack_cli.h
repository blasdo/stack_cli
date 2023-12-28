#ifndef STACK_CLI_H
# define STACK_CLI_H

# include <libft.h>
# define ERRCMD 255
# define ERRARGS 254
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


int			main(int argc, char *argv[]);
void		executer(t_command *command);
ssize_t		command_identifier(int mode, t_command *command);
t_command	*split_command(char *cmd);
#endif
