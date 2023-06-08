
def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mydict = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if (complement in mydict):
                return [mydict[complement], i]
            else:
                mydict[nums[i]] = i
        return []
