#include "analyse.h"

static void	search_next_quote(int *stop, const char *line)
{
	char	quote;

	quote = 0;
	if (line[(*stop)] == DQUOTE)
		quote = DQUOTE;
	else if (line[(*stop)] == SQUOTE)
		quote = SQUOTE;
	while (line[(*stop)] != '\0')
	{
		if (line[(*stop)] == quote)
			break ;
		(*stop)++;
	}
	while (line[(*stop)] != '\0')
	{
		if (line[(*stop)] == PIPE)
			break ;
		(*stop)++;
	}
}

static int			how_many_pipe(const char *line)
{
	int ret;
	int	stop;

	ret = 1;
	stop = 0;
	while (line[stop] != '\0')
	{
		if (line[stop] == DQUOTE || line[stop] == SQUOTE)
			search_next_quote(&stop, line);
		if (line[stop] == '|')
			ret++;
		stop++;
	}
	return (ret);
}

char		**shell_split(const char *line, const char c)
{
	int		beg;
	int		end;
	int		count;
	char	**ret;

	beg = 0;
	end = -1;
	count = 0;
	if (!(ret = (char**)malloc(sizeof(char*) * (how_many_pipe(line) + 1))))
		malloc_error("error in func shell_split", -1);
	while (line[++end] != '\0')
	{
		if (line[end] == DQUOTE || line[end] == SQUOTE)
		{
			search_next_quote(&end, line);
			ret[count++] = ft_strsub(line, beg, end - beg);
			beg = ++end;
		}
		if (line[end] == c)
		{
			ret[count++] = ft_strsub(line, beg, end - beg);
			ret[count] = ft_strftrim(ret[count]);
			beg = ++end;
		}
	}
	if (beg == 0 || end == (int)ft_strlen(line))
		ret[count++] = ft_strsub(line, beg, end - beg);
	ret[count] = NULL;
	return (ret);
}
