CC=			gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=			gcc
LDFLAGS=	-L.
AR=			ar
ARFLAGS=	rcs

TARGETS=	libstringutils.a \
			libstringutils.so \
			translate-static \
			translate-dynamic

all:		$(TARGETS)

# TODO: Add rules for libstringutils.a libstringutils.so

libstringutils.a: stringutils.o
	$(AR) $(ARFLAGS) $@ $^

libstringutils.so: stringutils.o
	$(LD) $(LDFLAGS) -shared -o $@ $^

stringutils.o:	stringutils.c stringutils.h
	$(CC) $(CFLAGS) -fPIC -o stringutils.o -c stringutils.c

translate.o:	translate.c
	$(CC) $(CFLAGS) -fPIC -o translate.o -c translate.c

translate-dynamic:	translate.o libstringutils.so
	$(LD) $(LDFLAGS) -o translate-dynamic translate.o -lstringutils

translate-static:	translate.o libstringutils.a
	$(LD) $(LDFLAGS) -static -o translate-static translate.o -lstringutils


test:			test-libstringutils test-translate

test-libstringutils:	libstringutils.so test_stringutils.py
	./test_stringutils.py -v

test-translate:	libstringutils.so test_translate.py
	./test_translate.py -v

clean:
	rm -f $(TARGETS) *.o
