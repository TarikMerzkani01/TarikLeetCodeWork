

int removeElement(int* nums, int numsSize, int val){
    int numvals = 0;
    unsigned short nextEmpty = 0;
    for (int i = 0; i < numsSize; i++) {
        if (val == nums[i]) {
            numvals++;
        } else {
            nums[nextEmpty++] = nums[i];
        }
    }
    return (numsSize - numvals);
}