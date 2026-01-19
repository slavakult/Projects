CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
TEST_FLAGS = -lcheck -lpthread -lm
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
DECIMAL = s21_decimal.a 
TESTS_OBJECT = s21_decimal_test

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
 TEST_FLAGS += -lsubunit -lrt
endif

# -lrt -lsubunit
all: s21_decimal.a

s21_decimal.a:
	$(CC) $(CFLAGS) *.c -c
	ar rcs $(DECIMAL) *.o
	ranlib $(DECIMAL)
	rm -rf *.o
	
rebuild: clean s21_decimal.a

test: s21_decimal.a
	gcc $(CFLAGS) tests/*.c *.c  -o $(TESTS_OBJECT) $(TEST_FLAGS) $(GCOV_FLAGS) 
	./$(TESTS_OBJECT)

gcov_report: s21_decimal.a test 
	lcov -t "$(TESTS_OBJECT)" -o $(TESTS_OBJECT).info -c -d .
	genhtml -o report $(TESTS_OBJECT).info
	open report/index.html
	rm -rf *.gcda *.gcno

clean:
	rm -rf *.gcda *.gcno *.info s21_decimal *.a *.o s21_decimal_test report

clang:
	clang-format -n *.c *.h
	clang-format -i *.c *.h
	clang-format -n *.c *.h
	clang-format -n tests/*.c *.h
	clang-format -i tests/*.c *.h
	clang-format -n tests/*.c *.h

cppcheck:
	cppcheck *c tests/*c --enable=all --suppress=missingIncludeSystem

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./$(TESTS_OBJECT)
