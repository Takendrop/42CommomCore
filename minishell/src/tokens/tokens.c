#include "../../headers/minishell.h"

void	create_array(char *s, t_attr *att, t_toki tok)
{
	int	count;

	att->index = 0;
	att->beforet = malloc((att->nb_tokens + 1) * sizeof(char *));
	att->beforet[att->nb_tokens] = NULL;
	if (!att->beforet)
		return ;
	count = 0;
	while (count < att->nb_tokens)
	{
		while (*s == ' ')
			s++;
		att->beforet[count] = get_token(s, att, tok);
		if (att->beforet[count] == 0 && count < att->nb_tokens)
		{
			s = NULL;
			return ;
		}
		s += att->tok_arr_i;
		count++;
	}
}

char	**get_tokens(char *str, t_attr *att, t_toki tok)
{
	if (!str)
		return (NULL);
	count_tokens(str, att);
	create_array(str, att, tok);
	return (att->beforet);
}