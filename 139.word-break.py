#
# @lc app=leetcode id=139 lang=python3
#
# [139] Word Break
#

# @lc code=start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(1, n + 1):
            for word in wordDict:
                if dp[i - len(word)] and s[i - len(word) : i] == word:
                    dp[i] = True
                    break
        return dp[-1]
# @lc code=end

