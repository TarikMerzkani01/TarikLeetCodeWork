#include <math.h>

int mySqrt(int x){
    //root = 0.5 * (g + x/g)
    double g = x;
    int root = 0;
    double tt = 0;
    while((unsigned long) (x-(tt*tt)) > 0.001) {
        tt = 0.5 * (g + (x/g));
        g = tt;
    }
    //2.5, 6.25, 
    root = (unsigned int) tt;
    return root;
}