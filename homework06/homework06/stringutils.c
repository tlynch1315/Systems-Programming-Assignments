/* stringutils.c: String Utilities */

#include "stringutils.h"

#include <ctype.h>
#include <string.h>

/**
 * Convert all characters in string to lowercase.
 * @param   s       String to convert
 * @return          Pointer to beginning of modified string
 **/
char *	string_lowercase(char *s) {
    for (char * c = s; *c; c++){
        *c = tolower(*c);
    }
    return s;
}

/**
 * Convert all characters in string to uppercase.
 * @param   s       String to convert
 * @return          Pointer to beginning of modified string
 **/
char *	string_uppercase(char *s) {
    for (char * c = s; *c; c++){
        *c = toupper(*c);
    }
    return s;
}

/**
 * Returns whether or not the 's' string starts with given 't' string.
 * @param   s       String to search within
 * @param   t       String to check for
 * @return          Whether or not 's' starts with 't'
 **/
bool	string_startswith(char *s, char *t) {
    char * j = s;
    for(char * c = t; *c != '\0'; c++){
        if(*c != *j){
            return false;
        }
        j++;
    }
    
    return true;
}

/**
 * Returns whether or not the 's' string ends with given 't' string.
 * @param   s       String to search within
 * @param   t       String to check for
 * @return          Whether or not 's' ends with 't'
 **/
bool	string_endswith(char *s, char *t) {
    int lens = strlen(s);
    int lent = strlen(t);
    if(lens < lent){
        return false;
    }
    
    char * ends;
    ends = s + strlen(s) -1;
    for(char * endt = t + strlen(t) -1; endt != t-1; endt--, ends--){
        if(*ends != *endt) return false;
    }
    return true;
}

/**
 * Removes trailing newline (if present).
 * @param   s       String to modify
 * @return          Pointer to beginning of modified string
 **/
char *	string_chomp(char *s) {
    char * end;
    end = s + strlen(s) -1;
    if(*end == '\n'){
        *end = 0;
    }
    return s;
}

/**
 * Removes whitespace from front and back of string (if present).
 * @param   s       String to modify
 * @return          Pointer to beginning of modified string
 **/
char *	string_strip(char *s) {
    char *c = s;
    char *start = s;
    char * end = s + strlen(s) -1;
    while(*start == ' ') start++;
    while(*end == ' '){
        *end = '\0';
        end--;
    }
    while(c <= end){
        *c = *start;
        c++, start++;
    }
    end = s + strlen(s) -1;
    while(start <=end){
        end = '\0';
        end--;
    }   


    return s;
}

/**
 * Reverses a string given the provided from and to pointers.
 * @param   from    Beginning of string
 * @param   to      End of string
 * @return          Pointer to beginning of modified string
 **/
static char *	string_reverse_range(char *from, char *to) {
    char temp;
    char * help;
    help = from;
    while(help < to){
        temp = *help;
        *help++ = *to;
        *to-- = temp;
    }
    return from;
}

/**
 * Reverses a string.
 * @param   s       String to reverse
 * @return          Pointer to beginning of modified string
 **/
char *	string_reverse(char *s) {
    char * end;
    end = s + strlen(s) - 1;
    s = string_reverse_range(s, end);
    return s;
}

/**
 * Reverses all words in a string.
 * @param   s       String with words to reverse
 * @return          Pointer to beginning of modified string
 **/
char *	string_reverse_words(char *s) {
    s = string_reverse(s);
    char * begin = s;
    char * end = s;
    while (*end != '\0'){
        while(*end == ' ') end++;
        begin = end;
        while(*end != ' ' && *end != '\0') end++;
        string_reverse_range(begin, end-1);
    }
    return s;
}

/**
 * Replaces all instances of 'from' in 's' with corresponding values in 'to'.
 * @param   s       String to translate
 * @param   from    String with letter to replace
 * @param   to      String with corresponding replacment values
 * @return          Pointer to beginning of modified string
 **/
char *	string_translate(char *s, char *from, char *to) {
    if(strlen(from) > strlen(to)) return s;
    while(*from != '\0'){
        for(char * c = s; *c; c++){
            if (*c == *from) *c = *to;
        }
        from++;
        to++;
    }

    return s;
}

/**
 * Converts given string into an integer.
 * @param   s       String to convert
 * @param   base    Integer base
 * @return          Converted integer value
 **/
int	string_to_integer(char *s, int base) {
    char * end = s + strlen(s) -1;
    int result = 0;
    int m = 1;

    while(*end){
        if(isalpha(*end)){
            if(*end >= 'a' && *end <= 'f'){
                result = result + (m*(*end - 'a' + 10));
            }
            else if(*end >= 'A' && *end <= 'F'){
                result = result + (m*(*end - 'A' + 10));
            }
        }
        else{
            result = result + (m*(*end - '0'));
        }
        end--;
        m = m * base;
    }
    return result;


    //return 0;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
