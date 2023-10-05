class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        countsdict = {}
        mylen = len(nums)
        thresh = mylen // 3
        majorityarr = []
        for i in range(mylen):
            if nums[i] in countsdict:
                countsdict[nums[i]] += 1
            else:
                countsdict[nums[i]] = 1
            if countsdict[nums[i]] > thresh and not (nums[i] in majorityarr):
                majorityarr.append(nums[i])
        return majorityarr
