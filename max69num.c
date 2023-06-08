#include <math.h>

int maximum69Number (int num){
    char ndigs = log10(num)+1;
    short displace, thresh;
    displace = 3000;
    thresh = 10000;
    switch(ndigs) {
        case 1:
            displace = 3;
            thresh = 10;
            break;
        case 2:
            displace = 30;
            thresh = 100;
            break;
        case 3:
            displace = 300;
            thresh = 1000;
            break;
    }
    for(char i = 0; i < ndigs; i++) {
        if (num + displace < thresh) {
            return num+displace;
        }
        displace = displace/10;
    }
    return num;
}