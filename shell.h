#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

/* Global environemnt */
extern char **environ;

/**
 * struct shell_data - Global data structure
 * @line: the line input
 * @args: the arguments token
 * @error_msg: the global path
 * @cmd: the parsed command
 * @index: the command index
 * @oldpwd: the old path visited
 * @env: the environnment
 *
 * Description: contains the variables needed to handle the program
 */

typedef struct shell_data
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} shell_t;

/**
 * struct builtin - handle the builtin functions
 * @cmd: the command line on string form
 * @f: the associated function
 *
 * Description: it handles the built in commands
 */

typedef struct builtin
{
	char *cmd;
	int (*f)(shell_t *data);
} blt_t;

#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))

/* string functions */
int _strlen(char *s);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, const char *src, size_t n);
char *_strdup(char *str);
char *_strcat(char *str1, char *str2);
int _isalpha(int c);

/* memory functions */
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
int datafree(shell_t *data);
void *_realloc(void *ptr, unsigned int presize, unsigned int postsize);

int get_line(shell_t *data);
int cmdpro(shell_t *data);
void *arrayf(void *ary, int num, unsigned int len);
void handlesig(int sigId);
int linesplit(shell_t *data);

int lparse(shell_t *data);
int filepath(shell_t *data);
void shortfile(shell_t *data);
int built_in(shell_t *data);

char *_getenv(char *path_name);
int builtinhdl(shell_t *data);
int proexit(shell_t *data __attribute__((unused)));
int dirchan(shell_t *data);
int printerr(shell_t *data);

char *_itoa(unsigned int n);
int _atoi(char *c);
void reva(char *ary, int len);
int ilen(int num);

void cmdId(shell_t *data);
int helpp(shell_t *data);
int write_history(shell_t *data __attribute__((unused)));

#endif
