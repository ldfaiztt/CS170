CC      = g++
CFLAGS  = 
LDFLAGS = -lpthread

all: cat shell
	
cat: cat.cpp
	$(CC) -o $@ $^ $(LDFLAGS)
shell: shell.cpp
	$(CC) -o $@ $^ $(LDFLAGS) 

run: 
	./shell
