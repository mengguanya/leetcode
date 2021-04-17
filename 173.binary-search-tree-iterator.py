#
# @lc app=leetcode id=173 lang=python3
#
# [173] Binary Search Tree Iterator
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    s = []
    def __init__(self, root: TreeNode):
        self.add(root)

    def add(self, node: TreeNode):
        p = node
        while p:
            self.s.append(p)
            p = p.left
            
    def next(self) -> int:
        res = self.s.pop()
        self.add(res.right)
        return res.val

    def hasNext(self) -> bool:
        return len(self.s) != 0

        # Your BSTIterator object will be instantiated and called as such:
        # obj = BSTIterator(root)
        # param_1 = obj.next()
        # param_2 = obj.hasNext()
        # @lc code=end
