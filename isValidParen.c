#include <string.h>

#define push(ptr, ltr) (*((ptr)++) = (ltr))
#define pop(ptr) (*--(ptr))

bool isValid(char * s){
    // xor with 1 is a bit flip
    
    char mystack[10000];
    char *myptr = mystack;
    short i;
    short mylen = strlen(s);
    for (i = 0; i < mylen-1; i+=2) {
        switch(s[i]) {
            case('('):
                push(myptr, '(');
                break;
            case('['):
                push(myptr, '[');
                break;
            case('{'):
                push(myptr, '{');
                break;
            case(')'):
                if (myptr == mystack || pop(myptr) != '(') return false;
                break;
            case(']'):
                if (myptr == mystack || pop(myptr) != '[') return false;
                break;
            case('}'):
                if (myptr == mystack || pop(myptr) != '{') return false;
                break;
        }
        switch(s[i+1]) {
            case('('):
                push(myptr, '(');
                break;
            case('['):
                push(myptr, '[');
                break;
            case('{'):
                push(myptr, '{');
                break;
            case(')'):
                if (myptr == mystack || pop(myptr) != '(') return false;
                break;
            case(']'):
                if (myptr == mystack || pop(myptr) != '[') return false;
                break;
            case('}'):
                if (myptr == mystack || pop(myptr) != '{') return false;
                break;
        }
    }
    for (; i < mylen; i++) {
        switch(s[i]) {
            case('('):
                push(myptr, '(');
                break;
            case('['):
                push(myptr, '[');
                break;
            case('{'):
                push(myptr, '{');
                break;
            case(')'):
                if (myptr == mystack || pop(myptr) != '(') return false;
                break;
            case(']'):
                if (myptr == mystack || pop(myptr) != '[') return false;
                break;
            case('}'):
                if (myptr == mystack || pop(myptr) != '{') return false;
                break;
        }
    }
    if (myptr == mystack) return true;
    else return false;
}


// ({[]})
// ([)]
// ([{)]}
// ([{})]}