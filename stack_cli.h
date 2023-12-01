#ifndef STACK_SHELL_H
# define STACK_SHELL_H

#include <libft.h>

typedef struct s_stack
{
	char	identifier[10];
	t_list	stack;
}				t_stack;
typedef struct s_parser
{
	int		instruct;
	int		argc;
	char	**argv;
}

#endif
