#ifndef ORANGE_H
#define ORANGE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int word_count(char *str);
int _strlen(char *str);
char **tokenizer(int size, char *buffer);
int _putchar(char c);
void print_unsigned_int(int n);
void print_n(int n);
void prerror(char **argv, char **array, int count);

#endif
