#include "sshell.h"
/**
  * _free_ - free ptrs
  * @freed: ptrs to be freed
  */
void _free_(char **freed)
{
	int i;

	for (i = 0; freed[i] != NULL; i++)
		free(freed[i]);
	free(freed);
}
/**
  * _free - free ptrs to strs
  * @n: num of ptrs to free
  */
void _free(int n, ...)
{
	int i;
	char *str;
	va_list list;

	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(list, char*);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(list);
}
