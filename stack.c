#include "stack_cli.h"
t_list	*stacks = NULL;

t_stack *stack_finder(char *identifier)
{
    t_list *current;

    if (!stacks)
        return (NULL);
    current = stacks;
    while (current)
    {
        if (!ft_strncmp(((t_stack *)(current->content.oth))->identifier, identifier, 9))
            return(current->content.oth);
        current = current->next;
    }
    return (NULL);
}

t_stack *newstack(char *identifier, t_list *contents)
{
    t_stack *result;
	if (stack_finder(identifier))
		return (0);
    result = malloc(sizeof(t_stack));
    if (!result)
        return (0);
    ft_strlcpy(result->identifier, identifier, 10);
    result->stack = contents;
    ft_lstadd_back(&stacks, ft_lstnew(result));
    return (result);
}

short int	push(char *identifier, int value)
{
	t_stack *stack = stack_finder(identifier);
	void *content = malloc(sizeof(int));
	if (!content)
		return (ERRMEMO);
	ft_memcpy(content, &value, sizeof(int));
	if (!stack)
		return (ERSTACK);
	ft_lstadd_front(&(stack->stack), ft_lstnew(content)); 
	return (0);
}

short int	pop(char *identifier)
{
	t_stack *stack = stack_finder(identifier);
	t_list	*tmp;

	if (!stack)
		return (ERSTACK);
	if (stack->stack == 0)
		return (EREMPTY);
	tmp = stack->stack->next;
	ft_lstdelone(stack->stack, print_n_free);
	stack->stack = tmp;
	return (0);
}

void	print_node(void *content)
{
	int *content_i = content;
	ft_printf("%i\n", *content_i);
}
void	print_n_free(void *content)
{
	print_node(content);
	free(content);
}

void	free_stack(void *to_free)
{
	t_stack *stack = to_free; 

	if (!stack)
		return ;
	ft_lstclear(&(stack->stack), free);
	free(to_free);
}

void	exit_cli(void)
{
	ft_lstclear(&stacks, free_stack);
	exit (0);
}
