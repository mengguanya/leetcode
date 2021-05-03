#
# @lc app=leetcode id=31 lang=python3
#
# [31] Next Permutation
#

# @lc code=start
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        Max = float("-inf")
        flag = False
        for i in range(-1, -len(nums) - 1, -1):
            if nums[i] < Max:
                flag = True
                t = nums[i]
                for j in range(i + 1, 0, 1):
                    if nums[j] < t:
                        nums[i] = nums[j - 1]
                        nums[j] = t
                        break
                break
            Max = nums[i]
        if not flag:
            nums.reverse()
# @lc code=end

