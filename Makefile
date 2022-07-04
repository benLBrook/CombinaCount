comb: combifun.c combinacount.c
	gcc combifun.c combinacount.c -o comb -lncurses
run:
	./comb
wcomb: combifun.c combinacount.c
	gcc -Wall combifun.c combinacount.c -o comb -lncurses

clean:
	rm -r comb
