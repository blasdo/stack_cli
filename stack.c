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
        if (!ft_strncmp(((t_stack *)(current->content))->identifier, identifier, 9))
            return(current->content);
        current = current->next;
    }
    return (NULL);
}

t_stack *newstack(char *identifier, t_list *contents)
{
    t_stack *result;
    result = malloc(sizeof(t_stack));
    if (!result)
        return (NULL);
    ft_strlcpy(result->identifier, identifier, 10);
    result->stack = contents;
    ft_lstadd_back(&stacks, ft_lstnew(result));
    return (result);
}

void	print_node(void *content)
{
	int *content_i = content;
	ft_printf("%i ", *content_i);
}
