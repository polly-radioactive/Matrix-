CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++17
TST_LIBS=-lgtest -lm -g
GCOV_LIBS=--coverage
SOURCES=s21_matrix_oop.cc
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LTEST=-lgtest
LIBO=s21_matrix_oop.o
NAME=s21_matrix_oop.a
BUILD_PATH=./
EXE=test
TEST_SRC=tests.cc
STYLE=clang-format --style=google
all:clean s21_matrix_oop.a

clean:
	rm -rf *.o *.g* *.info *.out report *.a test *.log gcov*

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) $(LTEST) -o test -pthread
	./test

gcov_report: 
	$(CC) $(GCOV_LIBS) $(TEST_SRC) $(SOURCES) -o gcov_report -lgtest -lstdc++ -std=c++17 -pthread
	./gcov_report
	lcov --no-external -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

s21_matrix_oop.a: clean
	$(CC) $(CFLAGS) -c $(SOURCES) -o $(LIBO) -pthread
	ar rcs $(NAME) $(LIBO)
	ranlib $(NAME)

check_style:
	$(STYLE) -n $(TEST_SRC) $(SOURCES) *.h

style:
	$(STYLE) -i $(TEST_SRC) $(SOURCES) *.h