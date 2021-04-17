#
# @lc app=leetcode id=42 lang=python3
#
# [42] Trapping Rain Water
#

# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        water = 0
        level = 0
        left, right = 0, len(height) - 1
        while left < right:
            lower = 0
            if height[left] < height[right]:
                lower = height[left]
                level = max(level, lower)
                water += level - height[left]
                left += 1
            else:
                lower = height[right]
                level = max(level, lower)
                water += level - height[right]
                right -= 1

        return water
        # @lc code=end
