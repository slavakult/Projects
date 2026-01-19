#include "s21_grep.h"

int main(int argc, char *argv[]) {
  flags A = {0};
  parser(argc, argv, &A);
  while (optind < argc) {
    output(argv, &A);
    optind++;
  }
  return 0;
}

void parser(int argc, char *argv[], flags *A) {
  int opt;
  while ((opt = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, 0)) != -1) {
    switch (opt) {
      case 'e':
        A->e = 1;
        strcat(A->str_regexec, optarg);
        strcat(A->str_regexec, "|");
        break;
      case 'i':
        A->i = 1;
        break;
      case 'v':
        A->v = 1;
        break;
      case 'c':
        A->c = 1;
        break;
      case 'l':
        A->l = 1;
        break;
      case 'n':
        A->n = 1;
        break;
      case 'h':
        A->h = 1;
        break;
      case 's':
        A->s = 1;
        break;
      case 'o':
        A->o = 1;
        break;
      case 'f':
        A->f = 1;
        strcpy(A->filename, optarg);
        f_flag(A);
        break;
      default:
        break;
    }
    if (A->v && A->o) {
      A->o = 0;
    }
  }
  if (!A->e && !A->f) {
    if (argc > optind) {
      strcat(A->str_regexec, argv[optind]);
    }
    optind++;
  }
  if (A->e || A->f) {
    A->str_regexec[strlen(A->str_regexec) - 1] = '\0';
  }
  if (argc - optind > 1) A->c_flag = 1;
}

void output(char *argv[], flags *A) {
  FILE *file;
  regex_t reg;
  regmatch_t start;
  int counter = 0;
  int str_number = 0;
  int flag_i = REG_EXTENDED;
  if (A->i) {
    flag_i = REG_EXTENDED | REG_ICASE;
  }
  regcomp(&reg, A->str_regexec, flag_i);
  file = fopen(argv[optind], "r");
  if (file != NULL) {
    while (fgets(A->str, BUFFER, file) != NULL) {
      int match = regexec(&reg, A->str, 1, &start, 0);
      str_number++;
      if (A->o) strcpy(A->str_o, A->str);
      if ((!match || A->v) && A->c_flag && !A->l && !A->h && !A->c && !A->f)
        printf("%s:", argv[optind]);
      if (!match) counter++;
      if (A->v) match = !match;
      if (!match && !A->l && !A->c && !A->n && !A->o) {
        printf("%s", A->str);
        if (A->str[strlen(A->str) - 1] != '\n') printf("\n");
      }
      if (!match && A->n && !A->c && !A->l) {
        if (A->o) {
          printf("%d:", str_number);
        } else
          printf("%d:%s", str_number, A->str);
        if (A->str[strlen(A->str) - 1] != '\n') printf("\n");
      }
      if (!match && A->o && !A->l && !A->c) {
        char *pointer = A->str_o;
        while ((regexec(&reg, pointer, 1, &start, 0) == 0)) {
          printf("%.*s\n", (int)(start.rm_eo - start.rm_so),
                 pointer + start.rm_so);
          pointer += start.rm_eo;
        }
      }
    }
    regfree(&reg);
    if (A->l && counter < 1 && A->v) {
      printf("%s\n", argv[optind]);
    }
    if (A->l && counter > 0 && !A->c) printf("%s\n", argv[optind]);
    if (A->c && A->c_flag && !A->h) printf("%s:", argv[optind]);
    if (A->c && !A->l && !A->v) printf("%d\n", counter);
    if (A->c && !A->l && A->v) printf("%d\n", str_number - counter);
    if (A->c && A->l) {
      if (counter > 0) {
        counter = 1;
        printf("%d\n%s\n", counter, argv[optind]);
      } else
        printf("%d\n", counter);
    }
    fclose(file);
  } else {
    regfree(&reg);
    if (!A->s)
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[optind]);
  }
}

void f_flag(flags *A) {
  FILE *f;
  f = fopen(A->filename, "r");
  if (f != NULL) {
    while (!feof(f)) {
      if (fgets(A->str, 1000, f) != NULL) {
        if (A->str[strlen(A->str) - 1] == '\n' && strlen(A->str) - 1 != 0)
          A->str[strlen(A->str) - 1] = '\0';
        strcat(A->str_regexec, A->str);
        strcat(A->str_regexec, "|");
      }
    }
    fclose(f);
  }
}
