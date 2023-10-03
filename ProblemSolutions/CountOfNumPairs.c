int numIdenticalPairs(int* nums, int numsSize){
    // Approach, count every instance of every number
    // Then, do n choose 2
    char counts[101];
    memset(counts, 0, 101);
    // char pairs[100];
    int pairs = 0;
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
        if (counts[nums[i]] > 1) {
            pairs += counts[nums[i]]-1;
        }
    }
    return pairs;
}