#include "core.h"

t_tok *ms_createtoken(int type, int index, char value)
{
    t_tok *tok;

    tok = malloc(sizeof(*tok));
    if (!tok)
        return (NULL);
	tok->value = malloc(sizeof(char) * 2);
    tok->index = index;
    tok->type = type;
	tok->value[0] = value;
	tok->value[1] = '\0';
    return (tok);
}

t_list *ms_tokenize(char *line)
{
	t_list *tokens;

	int i;

    i = -1;
	tokens = 0;
    while (line[++i])
    {
        if (ft_isspace(line[i]))
			ft_lstadd_back(&tokens , ft_lstnew(ms_createtoken(0, i, line[i])));
		else if (line[i] == '|')
			ft_lstadd_back(&tokens, ft_lstnew(ms_createtoken(2, i, line[i])));
		else if (line[i] == '\'')
			ft_lstadd_back(&tokens, ft_lstnew(ms_createtoken(3, i, line[i])));
		else if (line[i] == '\"')
			ft_lstadd_back(&tokens, ft_lstnew(ms_createtoken(4, i, line[i])));
		else if (line[i] == '<')
			ft_lstadd_back(&tokens, ft_lstnew(ms_createtoken(5, i, line[i])));
		else if (line[i] == '>')
			ft_lstadd_back(&tokens, ft_lstnew(ms_createtoken(6, i, line[i])));
		else
			ft_lstadd_back(&tokens, ft_lstnew(ms_createtoken(1, i, line[i])));	
	}
	return (tokens);
}

// void ms_tokenjoining(t_list *list)
// {
// 	t_tok *curr;
// 	t_tok *next;
	
// 	while (list && list -> next)
// 	{
// 		curr =(t_tok *)(list -> content);
// 		next = (t_tok *)(list -> next -> content);
// 		if (curr -> type == 1 && curr -> type == next -> type)

// 	}
// }