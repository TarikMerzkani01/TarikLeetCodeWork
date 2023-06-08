

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    char idx = digitsSize-1;
    //char res = digits[idx] + 1;
    //first find out if we need an extra digit
    int* returndigs = NULL;
    char j = 0;
    while(digits[j] == 9) { 
        j++; 
        if (j == digitsSize) {break;}
    }
    if (j == digitsSize) {
        //all 9s throughout
        //we add a digit
        //guaranteed that there is a 9 at the end.
        digitsSize++;
        //put answer in returnSize
        *returnSize = digitsSize;
        returndigs = malloc((digitsSize)*4);
        returndigs[0] = 1;
        idx = 1;
        while(idx < digitsSize) {
            returndigs[idx++] = 0;
        }
    } else {
        //same amount of digits
        *returnSize = digitsSize;
        returndigs = malloc((digitsSize)*4);
        while(digits[idx] == 9) {
            returndigs[idx--] = 0;
        }
        //guaranteed it doesn't have a 9 at the end
        //guaranteed idx is not 0
        returndigs[idx--] = digits[idx] + 1;
        while(idx >= 0) {
            //copy rest of number into returnSize
            returndigs[idx] = digits[idx];
            idx--;
        }
    }
    return returndigs;
}