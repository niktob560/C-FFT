all: main.o codecheck.sh

main.o:
	@gcc --std=c89 -Werror -Wall -Wextra -pedantic -pedantic-errors -Og -lm main.c -o main
	@echo -e '\033[1;33mCC\033[0m'

.PHONY: codecheck.sh
codecheck.sh:
	@./codecheck.sh

clean:
	@rm -f main
	@echo -e '\033[0;31mCleaned\033[0m'

run: clean all
	@./main