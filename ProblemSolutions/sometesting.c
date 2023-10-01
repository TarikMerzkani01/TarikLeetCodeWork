
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char* myresult = malloc(3);
    char* a = "00";
    myresult[0] = '1';
    printf("%s\n", myresult);
    printf("%s\n", a);
    strcat(myresult, a);
    
    printf("%s\n", myresult);
    free(myresult);
}