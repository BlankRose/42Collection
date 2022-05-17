/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:35 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 17:38:31 by flcollar         ###   ########.fr       */
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
	int		exit;
	int		fds[2];
	pid_t	running;
	t_byte	last_exit_code;
	char	**envp;
	char	*prompt_msg;
	t_plist	*envplist;
	int		in_file;
	int		out_file;
	int		out_file_app;
	int		in_file_here;
	char	***cmds;
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

typedef int (builtin_ft)(int, char **, char **);

/*********************************************************/
/*                                                       */
/*                   PROGRAMM FUNCTIONS                  */
/*    Specifics functions to run properly the program    */
/*                                                       */
/*********************************************************/

/* Handles a signal SIG, with its INFO and CONTEXT */
void	ms_signal_handler(int sig);

/* Duplicates the whole ARRAY of chars
Return: newly created array */
char	**ms_array_cpy(char **arr);

/* Finds the length of the ARRAY
Return: length of ARRAY */
int		ms_arraylen(char **arr);

/* Converts the ENVP ARRAY into a list
Return: newly created list */
t_plist	*ms_envptolist(char **envp);

/* Gets the prompt ready */
void	ms_prompt_run(void);

t_plist	*ms_lstlocate(t_plist *lst, size_t n);
t_plist	*ms_lstlast(t_plist *lst);
size_t	ms_lstsize(t_plist *lst);
t_plist	*ms_lstnew(char *key, char *value);
void	ms_lstadd_front(t_plist **lst, t_plist *new);
void	ms_lstadd_back(t_plist **lst, t_plist *new);
int		ms_printlist(t_plist *lst);
void	ms_plstclear(t_plist **lst, void (*del)(void*));
void	ms_plstdelone(t_plist *lst, void (*del)(void*));

char	*ms_getfromenvp(char *str);
char	*ms_strjoin(char *s1, char *s2);
char	*ms_parsedunquotes(char *str);
char	*ms_parsedbquotes(char *str);
char	*ms_parsequotes(char *str);
char	*ms_charjoin(char *str, char c);
char	*ms_parseline(char *line);
char	**ms_appendtoarr(char **arr, char *str);
void	ms_tokjoining(t_list *list);
void	ms_printtoken(t_list **lst);
void	ms_spacetokdel(t_list **list);
void	ms_parse_words(t_list **tokens);

int		ms_redircheck(t_list *list);
int		ms_redirdbcheck(t_list *list);
void	ms_wqjoining(t_list *list);
void	ms_wordquotesjoining(t_list *list);
int		ms_redirdbcheck(t_list *list);
void	ms_wqjoining(t_list *list);
void	ms_wordquotesjoining(t_list *list);
int		ms_pipecheck(t_list *list);

char	**ms_splitadv(const char *s, char c);
char	***ms_split_cmd(char *line);
void	ms_print_cmd(char ***cmd);
char	***ms_free_cmd(char ***cmd);

int		ms_checkquote(char c, int hasquote);
int		ms_isquote(int c);
int		ms_isoperator(int c);

t_list	**ms_tokenize(char *line);

#endif