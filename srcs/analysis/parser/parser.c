#include "analyse.h"

void		input_error(const char *error)
{
	ft_putstr_fd("erreur de syntaxe blabla: ", 2);
	ft_putstr(error);
	ft_putendl_fd(" abort prog", 2);
	exit (-1);
}

int			verify_input(t_token *token, t_pipe **pipe)
{
	char	**tmp;

	tmp = NULL;
	if (token->data != NULL)
	{
		tmp = shell_split(token->data, '|');
		add_pipe(tmp, pipe);
		ft_arrfree(&tmp);
	}
	else
		return (-1);
	return (0);
}

void		print_pipe(t_pipe **pipe)
{
	t_pipe *tmp;

	tmp = (*pipe);
	while (tmp != NULL)
	{
		ft_arrprint((const char**)tmp->cmd);
		ft_putstr("\n\n");
		tmp = tmp->next;
	}
}

int			core_parser(t_token **token)
{
	int			ret;
	t_token		*tmp;
	t_pipe		*pipe;

	if ((*token) == NULL)
		return (-1);
	pipe = NULL;
	tmp = (*token);
	while (tmp != NULL)
	{
		ret = verify_input(tmp, &pipe);
		tmp = tmp->next;
	}
	print_pipe(&pipe);
	return (ret);
}
