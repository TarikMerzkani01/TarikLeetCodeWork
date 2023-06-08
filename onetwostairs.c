
#include <stdio.h>
#include <stdlib.h>


int climbStairs(int n){
    if (n<2) return 1;
    else if (n == 2) return 2;
    //figure out (n-1)th term in fibonacci sequence\
    //now use fast doubling method
    unsigned long long a = 0;
	unsigned long long b = 1;
    for (char i = 31; i >= 0; i--) {
        unsigned long long temp1 = a * (b * 2 - a);
        unsigned long long temp2 = a * a + b * b;
        a = temp1;
        b = temp2;
        if (((unsigned int)n >> i) & 1) {
            unsigned long long c = a + b;
            a = b;
            b = c;
        }
    }
    return b;
    //variables that we need:
    //one for f(k), one for f(k)^2
    //one for for f(k+1)
    
    //We get these fast:
    // Given: f(1), f(2), f(3)
    // We get fast: 6th, 12th, 24th, 48th, if we start with 3
    // OR, 2, 4, 8, 16, 32, if we start with 2
    
    // f(2k) = f(k)*(2*f(k+1) - f(k))
    // f(2k) = 2*f(k+1)*f(k) - f(k)^2
    
    // f(2k+1) = f(k+1)^2 + f(k)^2
    /*
    int minusone = 2;
    int minustwo = 1;
    int temp = 2;
    for(char i = 3; i < n; i*=2) {
        temp = minusone;
        minusone += minustwo;
        minustwo = temp;
    }
    return minusone + minustwo;   
    */
}

int main() {
    fread(int arr[3], sizeof(int), 3, std.in);
    printf("Answer to climbstairs at 5: %d\n", climbStairs(5));
    return 0;
}