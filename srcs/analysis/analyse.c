#include "sh21.h"
#include "lexer.h"

char		**core_analyse(char *line)
{
	char	**ret;

	if (line == NULL)
		return (NULL);
	ret = core_lexer(line, ft_strlen(line));
	ft_strdel(&line);
	return (ret);
}
