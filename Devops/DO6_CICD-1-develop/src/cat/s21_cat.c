#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cat(const char *filename, char flag);

static struct option long_options[] = {{"number-nonblank", 0, NULL, 'b'},
                                       {"number", 0, NULL, 'n'},
                                       {"squeeze-blank", 0, NULL, 's'},
                                       {NULL, 0, NULL, 0}};

int main(int argc, char *argv[]) {
  int opt;
  char flag = '\0';
  while ((opt = getopt_long(argc, argv, "benstvET", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':
        flag = 'b';
        for (int i = 2; i < argc; i++) {
          cat(argv[i], flag);
        }
        break;
      case 'e':
        flag = 'e';
        for (int i = 2; i < argc; i++) {
          cat(argv[i], flag);
        }
        break;
      case 'n':
        flag = 'n';
        for (int i = 2; i < argc; i++) {
          cat(argv[i], flag);
        }
        break;
      case 's':
        flag = 's';
        for (int i = 2; i < argc; i++) {
          cat(argv[i], flag);
        }
        break;
      case 't':
        flag = 't';
        for (int i = 2; i < argc; i++) {
          cat(argv[i], flag);
        }
        break;
      case 'v':
        flag = 'v';
        for (int i = 2; i < argc; i++) {
          cat(argv[i], flag);
        }
        break;
      case 'E':
        flag = 'E';
        for (int i = 2; i < argc; i++) {
          cat(argv[i], flag);
        }
        break;
      case 'T':
        flag = 'T';
        for (int i = 2; i < argc; i++) {
          cat(argv[i], flag);
        }
        break;
      default:
        printf("Incorrect input");
        break;
    }
  }
  if (flag == '\0') {
    for (int i = 1; i < argc; i++) {
      cat(argv[i], flag);
    }
  }
  return 0;
}

void cat(const char *filename, char flag) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("error\n");
    return;
  }
  int c;
  char line[1024];
  int past_line_0 = 1;
  int line_number = 0;
  if (flag == '\0') {
    while (fgets(line, sizeof(line), file) != NULL) {
      printf("%s", line);
    }
  }

  if (flag == 'n') {
    // Увеличиваем номер строки только перед выводом непустой строки
    while (fgets(line, sizeof(line), file) != NULL) {
      if (strlen(line) > 0) {
        printf("%6d\t%s", ++line_number, line);
      } else {
        printf("%6d\n", line_number);  // Не увеличиваем номер строки перед
                                       // выводом пустой строки
      }
    }
  }

  if (flag == 'e') {
    while (fgets(line, sizeof(line), file) != NULL) {
      // Заменяем символ новой строки на символ доллара, если он присутствует
      for (unsigned long int i = 0; i < strlen(line); i++) {
        c = line[strlen(line) - 1];
        if ((c >= 0 && c < 9) || (c > 10 && c < 32) || (c > 126 && c <= 168)) {
          printf("^");
          if (c < 126) {
            c += 64;
          } else {
            c -= 64;
          }
        }
      }
      size_t len = strlen(line);
      if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '$';
      }
      printf("%s\n", line);
    }
  }

  if (flag == 's') {
    while (fgets(line, sizeof(line), file)) {
      int current_line_0 = (strlen(line) == 1 && line[0] == '\n');
      if (!current_line_0 || !past_line_0) {
        printf("%s", line);
      }
      past_line_0 = current_line_0;
    }
  }

  if (flag == 'b') {
    while (fgets(line, sizeof(line), file) != NULL) {
      if (strlen(line) > 1) {
        printf("%6d\t%s", ++line_number, line);
      } else
        printf("\n");
    }
  }

  if (flag == 't') {
    while (fgets(line, sizeof(line), file) != NULL) {
      // Используем символы из строки line
      for (unsigned long int i = 0; i < strlen(line); i++) {
        c = line[strlen(line) - 1];
        if ((c >= 0 && c < 9) || (c > 10 && c < 32) || (c > 126 && c <= 168)) {
          printf("^");
          if (c < 126) {
            c += 64;
          } else {
            c -= 64;
          }
        }
        if (line[i] == '\t') {
          putchar('^');
          putchar('I');
        } else {
          putchar(line[i]);
        }
      }
    }
  }

  if (flag == 'v') {
    while (fgets(line, sizeof(line), file) != NULL) {
      for (unsigned long int i = 0; i < strlen(line); i++) {
        c = line[strlen(line) - 1];
        if ((c >= 0 && c < 9) || (c > 10 && c < 32) || (c > 126 && c <= 168)) {
          printf("^");
          if (c < 126) {
            c += 64;
          } else {
            c -= 64;
          }
        }
      }
      printf("%s", line);
    }
  }

  if (flag == 'T') {
    while (fgets(line, sizeof(line), file) != NULL) {
      // Используем символы из строки line
      for (unsigned long int i = 0; i < strlen(line); i++) {
        if (line[i] == '\t') {
          putchar('^');
          putchar('I');
        } else {
          putchar(line[i]);
        }
      }
    }
  }

  if (flag == 'E') {
    while (fgets(line, sizeof(line), file) != NULL) {
      // Заменяем символ новой строки на символ доллара, если он присутствует
      size_t len = strlen(line);
      if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '$';
      }
      printf("%s\n", line);
    }
  }

  fclose(file);
  return;
}
