/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:35 by flcollar          #+#    #+#             */
/*   Updated: 2022/09/27 20:57:01 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

/*********************************************************/
/*                                                       */
/*                    LIBRARY INCLUDES                   */
/*     Every includes prefined by the library itself     */
/*                                                       */
/*********************************************************/

# include <stdio.h>
# include "../libft/libft.h"
# include "../pipexx/pipex.h"
# include "../builtin/builtin.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

/*********************************************************/
/*                                                       */
/*                      STRUCTURES                       */
/*    Various structures for easier variable handling    */
/*                                                       */
/*********************************************************/

typedef struct s_plist {
	char			*key;
	char			*value;
	struct s_plist	*next;
}	t_plist;

typedef struct s_tok {
	int		type;
	int		index;
	char	*value;
}	t_tok;

typedef struct s_main {
	int		fds[2];
	int		pipecount;
	pid_t	running;
	int		last_exit_code;
	char	**envp;
	char	*prompt_msg;
	t_plist	*envplist;
	t_list	**tokens;
	char	***cmds;
	char	*line;
}	t_main;

extern t_main	*g_main;

/*********************************************************/
/*                                                       */
/*                      DEFINITIONS                      */
/*                                                       */
/*********************************************************/

# define SEP            0
# define WORD           1
# define PIPE           2
# define QUOTE          3
# define DQUOTE         4
# define REDIR_IN       5
# define REDIR_OUT      6
# define HEREDOC        7
# define REDIR_OUT_APP  8

# define HEREDOC_FILE	"/tmp/Heredoc"

typedef int (builtin_ft)(int, char **, char **, int fd);

/*********************************************************/
/*                                                       */
/*                   PROGRAMM FUNCTIONS                  */
/*    Specifics functions to run properly the program    */
/*                                                       */
/*********************************************************/

/* Handles a signal SIG, with its INFO and CONTEXT */
void		ms_signal_handler(int sig);

/* Duplicates the whole ARRAY of chars
Return: newly created array */
char		**ms_array_cpy(char **arr);

/* Finds the length of the ARRAY
Return: length of ARRAY */
int			ms_arraylen(char **arr);

/* Converts the ENVP ARRAY into a list
Return: newly created list */
t_plist		*ms_envptolist(char **envp);

/* Gets the prompt ready */
void		ms_prompt_run(void);

t_plist		*ms_lstlocate(t_plist *lst, size_t n);
t_plist		*ms_lstlast(t_plist *lst);
size_t		ms_lstsize(t_plist *lst);
t_plist		*ms_lstnew(char *key, char *value);
void		ms_lstadd_front(t_plist **lst, t_plist *new);
void		ms_lstadd_back(t_plist **lst, t_plist *new);
int			ms_printlist(t_plist *lst);
void		ms_plstclear(t_plist **lst, void (*del)(void*));
void		ms_plstdelone(t_plist *lst, void (*del)(void*));

char		*ms_getfromenvp(char *str);
char		*ms_strjoin(char *s1, char *s2);
char		*ms_parsedunquotes(char *str);
char		*ms_parsedbquotes(char *str);
char		*ms_parsequotes(char *str);
char		*ms_charjoin(char *str, char c);
char		*ms_parseline(char *line);
char		**ms_appendtoarr(char **arr, char *str);
char		**ms_lsttoarr(t_plist *envplist);
void		ms_tokjoining(t_list *list);
void		ms_printtoken(t_list **lst);
void		ms_spacetokdel(t_list **list);
void		ms_parse_words(t_list **tokens);
char		*ft_testbin(char *command);

int			ms_redircheck(t_list *list);
int			ms_redirdbcheck(t_list *list);
void		ms_wqjoining(t_list *list);
void		ms_wordquotesjoining(t_list *list);
int			ms_redirdbcheck(t_list *list);
void		ms_wqjoining(t_list *list);
void		ms_wordquotesjoining(t_list *list);
int			ms_pipecheck(t_list *list);
void		ms_set_prompt_msg(void);

void		ms_createheredoc(char *end);
char		**ms_splitadv(const char *s, char c);
char		***ms_tokens2args(t_list **tokens);
void		ms_print_cmd(char ***cmd);
char		***ms_free_cmd(char ***cmd);
void		ms_deltoken(void *content);

int			ms_checkquote(char c, int hasquote);
int			ms_isquote(int c);
int			ms_isoperator(int c);

t_list		**ms_tokenize(char *line);
builtin_ft	*ms_is_builtin(char *line);
void		ms_redirset(t_list **list);
void		ms_wordtokjoining(t_list *list);
void		ms_spacetokjoining(t_list *list);
void		ms_redirtokjoining(t_list *list, int rtype);

void		rl_replace_line(const char *str, int n);

#endif