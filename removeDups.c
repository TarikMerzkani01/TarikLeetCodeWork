

int removeDuplicates(int* nums, int numsSize){
    int numdups = 0;
    char curnum = nums[0];
    unsigned short nextEmpty = 1;
    
    //Keep track of two spots in array
    // (1) nextEmpty for unique nums
    // (2) iterator
    
    // We have a variable curnum that stores the last unique number
    // As you iterate, check if same as last unique number
    // If same, continue, increase numdups
    // if diff, place number in next empty, update curnum, increase nextEmpty
    for (int i = 1; i < numsSize; i++) {
        if (curnum == nums[i]) {
            numdups++;
        } else {
            nums[nextEmpty++] = nums[i];
            curnum = nums[i];
        }
    }
    return (numsSize - numdups);
}