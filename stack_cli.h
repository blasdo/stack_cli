#ifndef STACK_CLI_H
# define STACK_CLI_H
# include "libft/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
// CONSTANTS
# define ERRCMD 255
# define ERRARGS 254
# define ERSTACK 253
# define EXCFAIL 252
# define ERREXIS 251
# define EREMPTY 250
# define ERRMEMO -1

extern char *cmds[];

typedef struct s_stack
{
	char	identifier[10];
	t_list	*stack;
}				t_stack;

typedef struct s_mode
{
	int		push_swap;
	char	*push_swap_args;
	int		log_fd;
}				t_mode;

typedef struct	s_command
{
	size_t	argc;
	char	**argv;
}				t_command;

int			main(int argc, char *argv[]);
void		executer(t_command *command);
ssize_t		command_identifier(t_command *command);
t_command	*split_command(char *cmd);
//list functions
void		print_node(void *content);
void		print_n_free(void *content);
//STACK FUNCTIONS
t_stack		*stack_finder(char *identifier);
t_stack		*newstack(char *identifier, t_list *contents);
short int	push(char *identifier, int value);
short int			pop(char *identifier);
void		exit_cli(void);
//CLI COMMANDS
short int	init(t_command *command);
short int	set_mode(t_command *command);
short int	print_stack(t_command *command);
short int	push_cmd(t_command *command);
short int	pop_cmd(t_command *command);
short int	print_help(t_command *command);
#endif
