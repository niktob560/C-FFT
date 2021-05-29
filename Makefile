all: main.o codecheck.sh

main.o:
	gcc --std=c89 -Werror -Wall -Wextra -pedantic -pedantic-errors -lm main.c

.PHONY: codecheck.sh
codecheck.sh:
	@./codecheck.sh

clean:
	rm a.out

run: all
	./a.out