#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/*Global environment*/
extern char **environ;

void free_tokens(char **tokens);
int _execute(char *args, struct stat *statbuffer, char **envp);
bool check_status(char *path, struct stat *statbuffer);
void handle_error(pid_t pid);
char *get_location(const char *cmd);
int my_exit(int argc, char **argv);
void shell_env(void);
int _putchar(char c);
char **tokenize(char *str);

#endif
