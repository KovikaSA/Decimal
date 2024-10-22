CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS = -lcheck -lpthread -lrt -lm -lsubunit
EXECUTABLE = test

SRC_ARITHMETIC = $(wildcard arithmetics/*.c)
SRC_COMPARISON = $(wildcard comparisons/*.c)
SRC_CONVERTER = $(wildcard converters/*.c)
SRC_HELPER = $(wildcard helpers/*.c)
SRC_OTHER = $(wildcard others/*.c)
SRC_TESTS = $(wildcard tests/*.c)

OBJ_ARITHMETIC = $(patsubst %.c, %.o, $(SRC_ARITHMETIC))
OBJ_COMPARISON = $(patsubst %.c, %.o, $(SRC_COMPARISON))
OBJ_CONVERTER = $(patsubst %.c, %.o, $(SRC_CONVERTER))
OBJ_HELPER = $(patsubst %.c, %.o, $(SRC_HELPER))
OBJ_OTHER = $(patsubst %.c, %.o, $(SRC_OTHER))
OBJ_TESTS = $(patsubst %.c, %.o, $(SRC_TESTS))

HEADERS = s21_decimal.h

all: test clean

s21_decimal.a: $(OBJ_ARITHMETIC) $(OBJ_COMPARISON) $(OBJ_CONVERTER) $(OBJ_HELPER) $(OBJ_OTHER)
	ar rc s21_decimal.a $(OBJ_ARITHMETIC) $(OBJ_COMPARISON) $(OBJ_CONVERTER) $(OBJ_HELPER) $(OBJ_OTHER)
	ranlib s21_decimal.a

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

test: s21_decimal.a $(OBJ_TESTS)
	@$(CC) $(CFLAGS) $(OBJ_TESTS) s21_decimal.a $(LDFLAGS) -o $(EXECUTABLE)
	@./$(EXECUTABLE)

gcov_report: s21_decimal.a
	$(CC) $(CFLAGS) --coverage  $(SRC_ARITHMETIC) $(SRC_COMPARISON) $(SRC_CONVERTER) $(SRC_HELPER) $(SRC_OTHER) s21_decimal.a tests/*.c $(LDFLAGS)  -o gcov_report
	./gcov_report
	lcov -t "gcov_report" -o report.info --no-external -c -d .
	genhtml -o report/ report.info
	open report/index.html

clean:
	@rm -rf s21_decimal.a
	@rm -rf $(EXECUTABLE)
	@rm -rf ./report
	@rm -rf gcov_report
	@rm -rf *.gcno *.gcda *.gcov *.info
	@rm -rf $(OBJ_ARITHMETIC) $(OBJ_COMPARISON) $(OBJ_CONVERTER) $(OBJ_HELPER) $(OBJ_TESTS) $(OBJ_OTHER)

valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./test

clang:
	clang-format -n ./**/*.c ./**/*.h -style=Google
	