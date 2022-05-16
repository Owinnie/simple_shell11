#ifndef SSHELL_H
#define SSHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types>
#include <dirent.h>
#include <stdarg.h>
#include <signal.h>
#define PROMPT "Owinnie@root $ "
/**
  * struct built_inside - for builtins
  * @built: name of command
  * @func: ptr to builtin
  */
typedef struct built_inside
{
	char *built;
	void (*func)(char);
} blt;
extern char **environ;
int _strlen(char *str);
void _parse(char *line, size_t n, int count, char **av);
char **strtok_array(char *line, const char *delim, int tkn_count);
char *_strdup(char *src);
char **tkn_array(int tkn_count, char *line, const char *delim);
int built_ins(char **a_rray, char *line);
void (*list_built_ins(char *str))(char *str);
void _exit_(char *);
void _env(char *);
void _cd(char *);
void _free_(char **freed);
void _free(int n, ...);
int _strcmp(char *s, char *s2);
int print_num(int n);
int find_path(char *s);
void fork_a_child(char **s_array, char *line, int count, char **av);
void exec_err(char *av, int count, char *temp_cmd);
void print_err(char *av, int count, char *cmd);
char **sub_paths(int i, char *s);
char *search_dir(char **path_tkns, char *cmd);
char *build_path(char *dir, char *cmd);

#endif
