PROJECT_NAME = grep
FLAGS = -Werror -Wextra -Wall
CC = gcc
VERSION = -std=c11

all: s21_$(PROJECT_NAME)

s21_$(PROJECT_NAME): clean
	$(CC) s21_$(PROJECT_NAME).c $(VERSION) $(FLAGS) -o s21_$(PROJECT_NAME)

clean: 
	rm -rf s21_$(PROJECT_NAME)

test:
	sh test_$(PROJECT_NAME).sh

check:
	clang-format -style=Google -n *.c
	clang-format -style=Google -i *.c
	leaks -atExit — ./s21_$(PROJECT_NAME)
	leaks -atExit — ./s21_$(PROJECT_NAME) -t ./test/test.txt