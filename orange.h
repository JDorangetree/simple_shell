#ifndef ORANGE_H
#define ORANGE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

char **strtow(char *str);
char **own_realloc(char **ptr, size_t *size);
#endif
