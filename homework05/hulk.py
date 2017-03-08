#!/usr/bin/env python2.7

import functools
import hashlib
import itertools
import multiprocessing
import os
import string
import sys

# Constants

ALPHABET    = string.ascii_lowercase + string.digits
ARGUMENTS   = sys.argv[1:]
CORES       = 1
HASHES      = 'hashes.txt'
LENGTH      = 1
PREFIX      = ''

# Functions

def usage(exit_code=0):
    print '''Usage: {} [-a alphabet -c CORES -l LENGTH -p PATH -s HASHES]
    -a ALPHABET Alphabet to use in permutations
    -c CORES    CPU Cores to use
    -l LENGTH   Length of permutations
    -p PREFIX   Prefix for all permutations
    -s HASHES   Path of hashes file'''.format(os.path.basename(sys.argv[0]))
    sys.exit(exit_code)

def md5sum(s):
    ''' Generate MD5 digest for given string.

    >>> md5sum('abc')
    '900150983cd24fb0d6963f7d28e17f72'

    >>> md5sum('wake me up inside')
    '223a947ce000ce88e263a4357cca2b4b'
    '''
    # TODO: Implement

    return hashlib.md5(s).hexdigest()
    pass
def permutations(length, alphabet=ALPHABET):
    ''' Yield all permutations of alphabet of specified length.

    >>> list(permutations(1, 'ab'))
    ['a', 'b']

    >>> list(permutations(2, 'ab'))
    ['aa', 'ab', 'ba', 'bb']

    >>> list(permutations(1))       # doctest: +ELLIPSIS
    ['a', 'b', ..., '9']

    >>> list(permutations(2))       # doctest: +ELLIPSIS
    ['aa', 'ab', ..., '99']
    '''
    # TODO: Implement

    if length == 1:
        for i in alphabet:
            yield i
    else:
        for j in alphabet:
            for k in permutations(length-1, alphabet):
                yield j + k

def smash(hashes, length, alphabet=ALPHABET, prefix=''):
    ''' Return all password permutations of specified length that are in hashes

    >>> smash([md5sum('ab')], 2)
    ['ab']

    >>> smash([md5sum('abc')], 2, prefix='a')
    ['abc']

    >>> smash(map(md5sum, 'abc'), 1, 'abc')
    ['a', 'b', 'c']
    '''
    # TODO: Implement
    return [prefix + perm for perm in list(permutations(length, alphabet)) if md5sum(prefix + perm) in hashes]

# Main Execution

if __name__ == '__main__':
    # TODO: Parse command line arguments
    args = sys.argv[1:]
    while len(args) and args[0].startswith('-') and len(args[0]) > 1:
        arg = args.pop(0)
        if arg == '-a':
            ALPHABET = args.pop(0)
        elif arg == '-c':
            CORES = int(args.pop(0))
        elif arg == '-l':
            LENGTH = int(args.pop(0))
        elif arg == '-p':
            PREFIX = args.pop(0)
        elif arg == '-s':
            HASHES = args.pop(0)
        elif arg == '-h':
            usage(0)
        else:
            usage(1)
    
    # TODO: Load hashes set
    if LENGTH > 1 and CORES > 1:
        if LENGTH > 4:
            PrefixLength = 2
        else:
            PrefixLength = 1
        SubPrefix = list(permutations(PrefixLength, ALPHABET))
        NewPrefix = [PREFIX + i for i in SubPrefix]




    passwords = set(line.rstrip() for line in open(HASHES))
    
    # TODO: Execute smash function to get passwords

    if LENGTH > 1 and CORES > 1:
        subSmash = functools.partial(smash, passwords, (LENGTH - PrefixLength), ALPHABET)
        pool = multiprocessing.Pool(CORES)
        confirmed = itertools.chain.from_iterable(pool.imap(subSmash, NewPrefix))
    else:
        confirmed = smash(passwords, LENGTH, ALPHABET, PREFIX)

    # TODO: Print passwords

    print '\n'.join(confirmed)
    pass

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
