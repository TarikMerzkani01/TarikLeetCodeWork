#include <string.h>

int lengthOfLastWord(char * s){
    short mylen = strlen(s);
    short lencount = 0;
    for(short i = mylen-1; i > -1; i--) {
        if (s[i] != ' ') {
            lencount++;
        }
        if (s[i] == ' ' && lencount != 0) {
            return lencount;
        }
    }
    return lencount;
}