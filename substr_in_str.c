#include <string.h>

int strStr(char * haystack, char * needle){
    short lenhay = strlen(haystack);
    short lenneed = strlen(needle);
    if (lenneed == 0) return 0;
    short comcounter = 0;
    for(short i = 0; i < lenhay; i++) {
        if (haystack[i] == needle[comcounter]) {
            //begin a scan
            //index of first occurrence is at any point: i - lenneed + 1
            //
            comcounter++;
        } else {
            i -= comcounter;
            comcounter = 0;
        }
        if (comcounter == lenneed) {
            return i - comcounter + 1;
        }
    }
    return -1;
}