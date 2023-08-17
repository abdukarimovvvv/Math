CC=gcc -std=c11 -D_GNU_SOURCE
TEST_LIBS=-lcheck -lm -lpthread 

all_c_files=s21_*.c
static_libr=s21_math.a

CC_FLAGS = -Wall -Werror -Wextra -std=c11
TESTFLAGS := -lcheck -coverage -lpthread -pthread 

C_FILES = s21_*.c 
O_FILES = s21_*.o


ifeq ($(shell uname -s),Linux)
	TESTFLAGS += -lrt -lm -lsubunit
endif

all:  s21_math.a test

rebuild: clean all

leaking:  ./test
	leaks --atExit -- ./test
	
test: s21_math.a
	gcc test.c $(GCCFLAGS) $(TESTFLAGS) -L. s21_math.a -o test
	./test

s21_math.a: all_functions
	ar rcs s21_math.a $(O_FILES)
	ranlib s21_math.a

style: clean
	clang-format --style=google -n s21_*.c *.h

all_functions: $(C_FILES)
	gcc -c $(CC_FLAGS) $(C_FILES)

gcov_report: s21_math.a
	$(CC) --coverage test.c $(all_c_files) $(static_libr) -L. $(static_libr) $(TEST_LIBS) -o ./test.out
	./test.out
	gcov s21_*.gcno > report.html
	make clean
	
clean:
	rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov *.a test
	rm -rf report/
	rm -rf temp/
	rm -rf atest.c
