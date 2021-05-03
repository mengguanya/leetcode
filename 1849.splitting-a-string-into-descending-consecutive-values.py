#
# @lc app=leetcode id=1849 lang=python3
#
# [1849] Splitting a String Into Descending Consecutive Values
#

# @lc code=start
class Solution:
    def judge(self, s, start, last, cnt) -> int:
        if start == len(s) and cnt > 0:
            return True
        for i in range(start, len(s)):
            t_d = int(s[start:i + 1])
            if t_d == 0 and last == 0:
                return self.judge(s, i + 1, t_d, cnt)
            if t_d + 1 == last:
                return self.judge(s, i + 1, t_d, cnt + 1)
            elif t_d + 1 > last:
                return False
        return False

    def splitString(self, s: str) -> bool:
        for i in range(0, len(s)):
            if self.judge(s, i + 1, int(s[0:i + 1]), 0) > 0:
                return True
        return False
        
# @lc code=end

