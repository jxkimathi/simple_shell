#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int _execute(char *args, struct stat *statbuffer, char **envp);
bool check_status(char *path, struct stat *statbuffer);
void handle_error(pid_t pid);

#endif
