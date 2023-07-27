#**Project**'Simple Shell'

## Introduction
> This README is for the simple shell project at Holberton. It countains the requirements, allowed functions and system calls, prototypes, compiler used, and a list of files.

### Requirements
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS
- Your code should use the Betty style.
- Shell should not have memory leaks
- No more than 5 functions per file
- Header files should be include guarded
- Only use system calls when needed

### Allowed Functions and System Calls
- access
- chdir
- close
- closedir
- execve
- exit
- _exit
- fflush
- fork
- free
- getcwd
- getline
- getpid
- isatty
- kill
- malloc
- open
- opendir
- perror
- printf
- fprintf
- vprintf
- sprintf
- putchar
- read
- readdir
- signal
- stat (_xstat)
- lstat (_lxstat)
- fstat (_fxstat)
- strtok
- wait
- waitpd
- wait3
- wait4
- write

##### Prototypes
'size_t print_dlistint(const dlistint_t *h);'

##### Compilation
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh'

### Repo Files
| **File** | *__Description__* |
|----------|----------------:|
|AUTHORS| File containing all Contributors to the Repo|
|man_1_simple_shell|Man page for the simphell function|
|main.h|Header file containing all structs and prototypes used|
|simphell| File that creates a simple shell to execute inputs|
|||
