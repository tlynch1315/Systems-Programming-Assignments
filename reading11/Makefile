CC=			gcc
CFLAGS= 	-g -gdwarf-2 -Wall -std=gnu99
LDFLAGS= 	-L.
LD=			gcc
TARGETS=	ncat

all: $(TARGETS)

ncat.o: ncat.c
	@echo Compiling ncat.c...
	@$(CC) $(CFLAGS) -c -o $@ $^

ncat: ncat.o
	@echo Linking ncat...
	@$(LD) $(LDFLAGS) -o $@ $^

clean:
	@echo Cleaning...
	@rm -f $(TARGETS) ncat *.o


