#include <string.h>
char * addBinary(char * a, char * b){
    short i = strlen(a)-1, j = strlen(b)-1;
    if (i < j) {   //b is longer
        char* tmp = a;
        a = b;
        b = tmp;
        short tmpid = i;
        i = j;
        j = tmpid;
        //swap pointers and lengths
    }
    // ensures a is now the longer string
    short mylen = i+1;
    char carry = 0;
    //find out length first
    while (i >= 0 && j >= 0) {
        if (a[i] != b[j]) {    //if different
            //since different, one of them has to be a 1
            if (carry) {    //two states
                a[i] = '0';    
            } else {
                a[i] = '1';
            }
        } else {    //if the same
            if (a[i] == '1') {     //both are ones
                if (carry == 0) {
                    a[i] = '0';
                    carry = 1;
                }
            } else {        //both are zeros
                if (carry) {
                    a[i] = '1';
                    carry = 0;
                }
            }
        }
        i--;
        j--;
    }
    // i : 0, j : -1
    //i and j may be both -1, or just i GUARANTEED
    char* res = malloc(mylen+10);
    strcpy(res, "1");
    if (carry) {
        if (i == j) {
            strcat(res, a);
            return res;
        }
        while (carry && i >= 0) {
            if (a[i] == '1') {
                a[i] = '0';
            } else {
                a[i] = '1';
                carry = 0;
            }
            i--;
        }
        if (carry) {         
            strcat(res, a);
            return res;
        }
    }
    free(res);
    return a;
}

// RIGHTMOST IS GUARANTEED FIRST BIT POSITION
// SINCE THERE IS NO LEADING ZEROS, THE LENGTH OF A STRING PRESENTS WHICH
// DIGIT IS THE MOST SIGNIFICANT BIT IN BASE-TWO
// For example: knowing len(a) = 4, we know that a[0] = 1, and that means
// that it adds up 2^3