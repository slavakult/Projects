#ifndef S21_GREP_H_
#define S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1000

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int o;
  int f;
  int c_flag;
  char str[BUFFER];
  char str_o[BUFFER];
  char filename[BUFFER];
  char str_regexec[BUFFER];
} flags;

void parser(int argc, char *argv[], flags *A);
void f_flag(flags *A);
void output(char *argv[], flags *A);

#endif