CC=		gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=		gcc
LDFLAGS=	-L.
AR=		ar
ARFLAGS=	rcs
TARGETS=	lsort

all:		$(TARGETS)

# TODO: Add rules for liblist.a, test_node, test_list, lsort, and any intermediate objects


test_node: liblist.a test_node.o
	$(LD) $(LDFLAGS) -o $@ test_node.o -llist

test_list: liblist.a test_list.o
	$(LD) $(LDFLAGS) -o $@ test_list.o -llist

test_node.o: node.h list.h test_node.c
	$(CC) $(CFLAGS) -o $@ -c test_node.c

test_list.o: node.h list.h test_list.c
	$(CC) $(CFLAGS) -o $@ -c test_list.c

lsort.o: lsort.c list.h node.h
	@echo Compiling lsort.o...
	$(CC) $(CFLAGS) -o $@ -c $<

node.o: node.c node.h list.h
	@echo Compiling node.o...
	$(CC) $(CFLAGS) -o $@  -c $<

list.o: node.h list.h list.c
	@echo Compiling list.o
	$(CC) $(CFLAGS) -o $@ -c list.c

liblist.a: node.o list.o
	@echo Linking liblist.a
	$(AR) $(ARFLAGS) $@ node.o list.o

lsort: liblist.a lsort.o
	@echo Linking lsort
	$(LD) $(LDFLAGS) -o $@ lsort.o -llist



test:		test-node test-list test-lsort

test-node:	test_node
	@echo Testing node...
	@[ `valgrind --leak-check=full ./test_node 2>&1 | tee test_node.log | grep ERROR | awk '{print $$4}'` = 0 ] || cat test_node.log

test-list:	test_list
	@echo Testing list...
	@[ `valgrind --leak-check=full ./test_list 2>&1 | tee test_list.log | grep ERROR | awk '{print $$4}'` = 0 ] || cat test_list.log

test-lsort:	lsort test_lsort.sh
	@echo Testing lsort...
	@./test_lsort.sh

clean:
	@echo Cleaning...
	@rm -f $(TARGETS) test_node test_list *.a *.o *.log *.input

.PHONY:		all test test-node test-list test-lsort clean
