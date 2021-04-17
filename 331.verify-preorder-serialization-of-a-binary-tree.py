#
# @lc app=leetcode id=331 lang=python3
#
# [331] Verify Preorder Serialization of a Binary Tree
#

# @lc code=start
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        stack = []
        nodes = preorder.split(',')
        for node in nodes:
            if node == '#':
                while len(stack) > 1 and stack[-1] == '#' and stack[-2] != '#':
                    stack.pop()
                    stack.pop()
            stack.append(node)
        if len(stack) == 1 and stack[0] == '#':
            return True
        return False
# @lc code=end
