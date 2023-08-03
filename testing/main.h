#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>

extern char **environ;


int main(int argc, char **argv);
void free_arg(char **argv);
char *_getenv(const char *command);
void execmd(char **argv);
char *find_location(char *command);
char **tokenize(char *input, const char *delim);
void print_env(void);
void env_cmd(void);

#endif
