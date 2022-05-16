#include "sshell.c"
/**
  * built_ins - check for buitins
  * @a_rray: list of args passed
  * @line: user input
  *
  * Return: 0 on success, -1 on failure
  */
int built_ins(char **a_rray, char *line)
{
	void (*built)(char *);

	built = list_built_ins(a_rray[0]);
	if (built == NULL)
		return (-1);
	if (_strcmp("exit", a_rray[0]) == 0)
		_free_(a_rray);
	built(line);
	return (0);
}
/**
  * list_built_ins - list of builtins
  * @str: name of function
  * Return: NULL, or ptr to void funct.
  */
void (*list_built_ins(char *str))(char *str)
{
	int i;

	blt builD[] = {
		{"exit", _exit_},
		{"env", _env},
		{"cd", _cd},
		{NULL, NULL}
	};
	for (i = 0; builD[i].built != NULL; i++)
	{
		if (_strcmp(str, builD[i].built) == 0)
		{
			return (builD[i].func);
		}
	}
	return (NULL);
}
/**
  * _exit_ - exit owshell
  * @line: free line before exiting
  */
void _exit_(char *line)
{
	free(line);
	write(1, "\n", 1);
	exit(1);
}
/**
  * _env - print environment vars
  * @line: user_input
  */
void _env(__attribute__((unused))char *line)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(1, &environ[i][j], 1);
		write(1, "\n", 1);
	}
}
/**
  * _cd - change dir
  * @line: user input
  */
void _cd(char *line)
{
	int i, tkn_count = 0;
	char **s_array;
	const char *delim = " \n\t";

	s_array = strtok_array(line, delim, tkn_count);
	if (s_array[0] == NULL)
	{
		_free(2, s_array, line);
		return;
	}
	if (s_array[1] == NULL)
	{
		i = find_path("HOME");
		chdir((environ[i]) + 5);
	}
	else if (_strcmp(s_array[1], "-") == 0)
	{
		write(1, s_array[1], _strlen(s_array[1]));
		write(1, "\n", 1);
	}
	else
		chdir(s_array[1]);
	_free_(s_array);
}
