#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        s = []
        for token in tokens:
            if token == '+':
                temp = s.pop() + s.pop()
                s.append(temp)
            elif token == '-':
                temp = -s.pop() + s.pop()
                s.append(temp)
            elif token == '*':
                temp = s.pop() * s.pop()
                s.append(temp)
            elif token == '/':
                temp = int(1/s.pop() * s.pop())
                s.append(temp)
            else:
                s.append(int(token))
        return s[0]

# @lc code=end

