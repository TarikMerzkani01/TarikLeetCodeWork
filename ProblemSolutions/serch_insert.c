

int searchInsert(int* nums, int numsSize, int target){
    //Divide and conquer
    //This is just binary search
    short low = 0;
    short high = numsSize - 1;
    short idxmid = 0;
    while (low <= high) {
        short idxmid = (low + high)/2;
        if (nums[idxmid] == target) {
            return idxmid;
        } else if (nums[idxmid] < target) {
            low = idxmid+1;
        } else {
            high = idxmid -1;
        }
    }
    return low;
}