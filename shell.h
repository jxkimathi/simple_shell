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

#define BUFF_SIZE 1024

/*Global environment*/
extern char **environ;

void free_tokens(char **tokens);
int _execute(char *argv, char **av);
int main(int argc, char **argv);
char *get_location(const char *cmd);
void shell_env(void);
int _putchar(char c);
char **tokenize(char *str);
void free_tokens(char **args);
void prompt(void);
int bettyStyle(int a, int b);

#endif
