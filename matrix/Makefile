GCC = gcc
LFLAGS = -c
SOURCE := $(shell find ./source -iname "*.c" )
TEST_SOURCE := $(shell find ./tests -iname "*.c" )
HEADER_SOURCE := $(shell find ./ -iname "*.h" )
ALL := $(shell find ./ -iname "*.c" )

ifeq ($(shell uname -s),Darwin)
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lpthread -lm
else
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lgcov -lpthread -lm -lsubunit 
endif

all: clean s21_matrix.a test

s21_matrix.a: ${SOURCE} clean
	$(GCC) $(LFLAGS) $(SOURCE)
	ar rc $@  *.o
	ranlib $@

test: ${SOURCE} ${TEST_SOURCE}
	$(GCC) $(TEST_FLAGS) 
	./$@

gcov_report: test
	lcov --directory ./ --capture --output-file coverage.info
	mkdir -p report
	genhtml -o report coverage.info
	open report/index.html
	rm -f *.gcda *.gcno

cppcheck: $(ALL)
	cppcheck $^;

format: ${ALL} ${HEADER_SOURCE}
	cp .././materials/linters/.clang-format .
	clang-format -i -style=google $^;
	rm .clang-format

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test

clean:
	-rm -rf *.o *.gcno *.a *.gcda *.info *.gcov ./test ./report/ test.dSYM