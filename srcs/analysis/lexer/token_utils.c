#include "sh21.h"
#include "analyse.h"

void	token_error(const char *token)
{
	ft_putstr_fd("missing token : ", 2);
 	ft_putendl_fd(token, 2);
}

t_token	*create_node_input(const char *data, int begin, int stop)
{
	t_token *new;

	if (!(new = (t_token*)malloc(sizeof(t_token))))
		malloc_error("error in func create_token", -1);
	if (data == NULL)
	{
		new->data = NULL;
		new->type = 0;
	}
	else
	{
		new->data = ft_strndup(data + begin, stop - begin);
		new->type = 0;
	}
	new->next = NULL;
	return (new);
}

void	add_node_input(const char *data, int begin, int stop, t_token **token)
{
	t_token	*tmp;

	tmp = NULL;
	if (!(*token))
		(*token) = create_node_input(data, begin, stop);
	else
	{
		tmp = (*token);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_node_input(data, begin, stop);
	}
}

int		count_list(t_token **token)
{
	int		count;
	t_token	*tmp;

	count = 0;
	if ((*token) != NULL)
	{
		tmp = (*token);
		while (tmp != NULL)
		{
			++count;
			tmp = tmp->next;
		}
	}
	return (count);
}

char	**list_to_tab(t_token **token)
{
	int		count;
	char	**ret;
	t_token *tmp;

	ret = NULL;
	if ((*token) != NULL)
	{
		count = 0;
		if (!(ret = (char**)malloc(sizeof(char*) * (count_list(token) + 1))))
			malloc_error("error in func list_to_tab", -1);
		tmp = (*token);
		while (tmp != NULL)
		{
			ret[count] = ft_strdup(tmp->data);
			++count;
			tmp = tmp->next;
		}
		ret[count] = NULL;
	}
	return (ret);
}
