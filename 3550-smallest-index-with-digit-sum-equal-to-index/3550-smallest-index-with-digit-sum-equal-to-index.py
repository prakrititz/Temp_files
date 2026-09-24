class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            n = 0
            while nums[i]:
                n += nums[i]%10
                nums[i]//=10
            if n == i:
                return i
        return -1