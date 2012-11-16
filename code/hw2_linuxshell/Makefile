all: shell cat

shell: shell.c
	gcc -o shell shell.c -I.
     
cat: cat.c
	gcc -o cat cat.c -I.

run: 
	@$(MAKE) && ./shell

clean:
	\rm -f shell cat *~
