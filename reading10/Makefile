CC=		gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=		gcc
LDFLAGS=	-L.
AR=		ar
ARFLAGS=	rcs
TARGETS=	walk

all:		$(TARGETS)

#-------------------------------------------------------------------------------

walk.o: walk.c
	@echo Compiling walk.o...
	@$(CC) $(CFLAGS) -o $@ -c $<

walk: walk.o
	@echo Linking walk...
	@$(LD) $(LDFLAGS) -o $@ walk.o


# TODO: Add rules for test_entry, test_fnv, test_map, freq, measure

#-------------------------------------------------------------------------------


clean:
	@echo Cleaning...
	@rm -f $(TARGETS)  *.a *.o *.log *.input

.PHONY:		all test benchmark clean
