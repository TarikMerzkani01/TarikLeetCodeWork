

int fib(int n){
    if (n<2) return n;
    else if (n == 2) return 1;
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
    return a;
}