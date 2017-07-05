#include "analyse.h"

t_pipe		*create_pipe(char **cmd)
{
	t_pipe *new;

	new = NULL;
	if (!(new = (t_pipe*)malloc(sizeof(t_pipe))))
		malloc_error("error in func create_pipe", -1);
	new->cmd = ft_arrdup((const char **)cmd);
	new->next = NULL;
	return (new);
}

void		add_pipe(char **cmd, t_pipe **pipe)
{
	t_pipe *tmp;

	if ((*pipe) == NULL)
		(*pipe) = create_pipe(cmd);
	else
	{
		tmp = (*pipe);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_pipe(cmd);
	}
}
