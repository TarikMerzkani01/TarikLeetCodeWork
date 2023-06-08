
#include <string.h>

// char* myroman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
// short mynums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

int romanToInt(char * s){
    // loop unrolling?
    // [1000 900 500 400 100 90 50 40 10 9 5 4 1]
    // [M CM D CD C XC L XL X IX V IV I]
    // we can segment the program into digits. Get digits first
    // thousand digit: "MMM", "MM", "M"
    // hundred digit: "CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C"
    // ten digit: "XC", "LXXX", "LXX", "LX", "L", "XL", "XXX", "XX", "X"
    // ones digit: "IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I"
    unsigned char mylen = strlen(s);
    unsigned short mytotal = 0, mytotal2 = 0, mymax = 0;
    short myadd = 0, myadd2 = 0;
    //account for odd number length at the end
    for(char i = mylen-1; i > 0; i-=2) {
        switch(s[i]) {
            case 'I':
                myadd = 1;
                break;
            case 'V':
                myadd = 5;
                break;
            case 'X':
                myadd = 10;
                break;
            case 'L':
                myadd = 50;
                break;
            case 'C':
                myadd = 100;
                break;
            case 'D':
                myadd = 500;
                break;
            case 'M':
                myadd = 1000;
                break;
        }
        if (myadd > mymax) mymax = myadd;
        else if (myadd < mymax) myadd = myadd * -1;
        mytotal += myadd;
        switch(s[i-1]) {
            case 'I':
                myadd2 = 1;
                break;
            case 'V':
                myadd2 = 5;
                break;
            case 'X':
                myadd2 = 10;
                break;
            case 'L':
                myadd2 = 50;
                break;
            case 'C':
                myadd2 = 100;
                break;
            case 'D':
                myadd2 = 500;
                break;
            case 'M':
                myadd2 = 1000;
                break;
        }
        if (myadd2 > mymax) mymax = myadd2;
        else if (myadd2 < mymax) myadd2 = myadd2 * -1;
        mytotal2 += myadd2;
    }
    if (mylen&1) {
        switch(s[0]) {
                case 'I':
                    myadd = 1;
                    break;
                case 'V':
                    myadd = 5;
                    break;
                case 'X':
                    myadd = 10;
                    break;
                case 'L':
                    myadd = 50;
                    break;
                case 'C':
                    myadd = 100;
                    break;
                case 'D':
                    myadd = 500;
                    break;
                case 'M':
                    myadd = 1000;
                    break;
        }
        if (myadd < mymax) myadd = myadd * -1;
        mytotal += myadd;
    }
    
    mytotal += mytotal2;
    return mytotal;
}