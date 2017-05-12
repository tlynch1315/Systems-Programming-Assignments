CC=			gcc
CFLAGS= 	-g -gdwarf-2 -Wall -std=gnu99
LDFLAGS= 	-L.
LD=			gcc
TARGETS=	final	

all: $(TARGETS)

final.o: final.c
	@echo Compiling final.c...
	@$(CC) $(CFLAGS) -c -o $@ $^

ncat: ncat.o
	@echo Linking final...
	@$(LD) $(LDFLAGS) -o $@ $^

clean:
	@echo Cleaning...
	@rm -f $(TARGETS) final *.o


