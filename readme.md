小白刷题，简单记录。

| 序号 | 名称                                                         | 难度   | 知识点                     | 思路                                                         | 相关题目 |
| ---- | ------------------------------------------------------------ | ------ | -------------------------- | ------------------------------------------------------------ | -------- |
| 14   | [Longest Common Prefix](./14.longest-common-prefix.cpp)      | easy   | 字符串                     | 判断最长公共前缀。用相同序号同步扫描n个字符串即可。          |          |
| 347  | [Top K Frequent Elements](./347.top-k-frequent-elements.cpp) | medium | 无序字典（哈希表）、小顶堆 | 小于O（nlog（n））时间内找出一组n个数中出现次数最多的K个元素。首先用无序字典建立元素和个数的映射（O（n）），然后建立小顶堆。依次把元素映射加入堆，直到堆大小等于K。之后，把元素出现次数和堆顶比较，如果该元素更多，则弹出堆顶，压入该元素。最后返回堆中的元素即可。复杂度：O（nlog(K)） |          |
| 42   | [Trapping Rain Water](./42.trapping-rain-water.py)           | hard   | 双向指针                   | 柱状图形状的二维蓄水池。两个指针分别指向两头，从较小的一端往里收缩，并同时用收缩端的高度更新当前水平面（如果高于水平面），同时用水平面高度减去该端的高度，作为该柱子的蓄水量。最后左右端点相遇即可结束。 |          |
| 84   | [Largest Rectangle in Histogram](./84.largest-rectangle-in-histogram.py) | hard   | 单调栈                     | 柱状图里最大长方形。维护一个递增单调栈，保存递增高度的索引。从左至右依次遍历柱状图的高度，如果高度大于栈顶的高度，则压栈；如果高度小于栈顶的高度则弹出栈顶P，并计算 “以P的高度为高度，当前遍历的柱子的索引-1为右边界，目前栈顶的索引+1为左边界”的矩形的面积，更新最大面积。最后在柱状图的末尾添加0，以弹出（计算）所有栈中的索引。 |          |
| 206  | [Reverse Linked List](./206.reverse-linked-list.py)          | easy   | 链表、递归                 | 反转链表。使用递归方法，从最后一个节点开始把其指向倒数第二个结点，倒数第二个结点指向空。 |          |
| 173  | [Binary Search Tree Iterator](./173.binary-search-tree-iterator.py) | medium | 栈、二叉树遍历             | 实现二叉树迭代器的生成和使用。考察二叉树中序遍历的非递归实现。通过栈依次保存从根节点开始的最左路径的所有节点，每弹出一个节点就把它的右子节点（如有）的最左路径上的所有节点依次压栈。next操作包括：弹栈，并压右子节点的最左路径；exist_next操作包括：判断栈非空。 |          |
| 316  | [Remove Duplicate Letters](316.remove-duplicate-letters.py)  | medium | 单调栈                     | 给定一个字符串，按照字母顺序给出包括所有字符的字符串。按顺序遍历字符串，如果该字符大于栈顶元素则压栈，否则（如果栈顶元素在剩余字符串中还会出现）循环弹出栈顶，压入该字符。最后依次输出栈中的元素即可。 |          |
| 331  | [Verify Preorder Serialization of a Binary Tree](./331.verify-preorder-serialization-of-a-binary-tree.py) | medium | 栈、二叉树遍历             | 验证二叉树的前序遍历序列是否正确。顺序扫描序列，遇到非#直接压栈；遇到#判断是否（栈顶是#，次栈顶非#），如果成立，则弹出它们2个，把#压栈。最后如果栈中只有一个#，则正确。 |          |
| 150  | [Evaluate Reverse Polish Notation](./150.evaluate-reverse-polish-notation.py) | medium | 栈、逆波兰式               | 计算逆波兰式。读到数字则压栈，否则弹出栈顶2个数字，运算结果压栈。最后栈中只有一个元素即为答案。注意除法和减法的运算顺序。 |          |
| 44   | [Wildcard Matching](./44.wildcard-matching.cpp)              | hard   | 字符串、指针               | 字符串通配符。2个指针遍历2个字符串。1. 如果适配或者？适配则分别+1；2.如果通配串扫到了*则记录该位置star，并进入star+1，待配串不动，并记录该位置为ss；3.如果前两者都不符合，那么根据star判断，如果前面有star，则通配串回到star+1，待配串回到ss+1,并把ss自加1（表示必须要把ss这个位置配到star里，才有可能成功匹配），如果无star则返回失败。扫描结束待配串后，如果通配串只剩star或者为空则成功，否则失败。 |          |
| 632  | [Smallest Range Covering Elements from K Lists](./632.smallest-range-covering-elements-from-k-lists.cpp) | hard   | 优先队列、指针             | 给定K个升序列表，找到最小的范围能够覆盖到每个列表至少一个元素。维护K个指针指向列表头(存在小顶堆)，堆顶就是指向最小元素MIN的指针，并记录最大值MAX的指针，记录min_range。每次把最小的指针向前移动一位（增大最小值，减小区间范围），更新最大值MAX，并弹出栈顶MIN，压入新指针, 如果区间更短，更新res。直到某个指针到头。输出范围res。 |          |
| 79   | [Word Search](./79.word-search.cpp)                          | medium | 回溯、递归                 | 在二维数组中，判断是否可以通过临接块组成某个单词。遍历所有的块，如果该块是单词的第一个字母，则以此为起点开始递归查找，直到匹配完所有的字符。 |          |
| 208  | [Implement Trie (Prefix Tree)](./208.implement-trie-prefix-tree.cpp) | medium | trie、forward_list         | 实现trie树的创建、添加数据、查询数据、查询前缀的功能。其中每个树的子树使用了forward_list实现。 |          |
|      |                                                              |        |                            |                                                              |          |
|      |                                                              |        |                            |                                                              |          |
|      |                                                              |        |                            |                                                              |          |
|      |                                                              |        |                            |                                                              |          |
|      |                                                              |        |                            |                                                              |          |
|      |                                                              |        |                            |                                                              |          |

