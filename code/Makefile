# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

MAKE = make
LPR = lpr

#NACHOS_DIRS = threads userprog vm filesys network
NACHOS_DIRS = vm filesys 
DIRS = bin testvm testfile

all: 
	-for d in $(NACHOS_DIRS); do \
		(cd $$d; $(MAKE) depend; $(MAKE) nachos); done
	-for d in $(DIRS); do (cd $$d; $(MAKE) all ); done

# don't delete executables in "test" in case there is no cross-compiler
clean:
	-for d in $(NACHOS_DIRS) $(DIRS); do (cd $$d; $(MAKE) clean ); done
