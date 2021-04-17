#
# @lc app=leetcode id=316 lang=python3
#
# [316] Remove Duplicate Letters
#

# @lc code=start
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stack = []
        nums = [0] * 26
        exists = [0] * 26
        for ch in s:
            nums[ord(ch) - ord('a')] += 1
        for ch in s:
            nums[ord(ch) - ord('a')] -= 1
            if exists[ord(ch) - ord('a')] == 0:
                while len(stack) > 0 and stack[-1] > ch and nums[ord(stack[-1]) - ord('a')] != 0:
                    exists[ord(stack[-1]) - ord('a')] = 0
                    stack.pop()
                stack.append(ch)
                exists[ord(ch) - ord('a')] = 1
        return ''.join(stack)    

# @lc code=end

