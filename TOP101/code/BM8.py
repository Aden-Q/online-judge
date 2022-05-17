# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param pHead ListNode类 
# @param k int整型 
# @return ListNode类
#
class Solution:
    def FindKthToTail(self , pHead: ListNode, k: int) -> ListNode:
        # write code here
        n = 0
        ptr = pHead
        while ptr:
            ptr = ptr.next
            n += 1
        if n < k:
            return None
        ptr = pHead
        for _ in range(n - k):
            ptr = ptr.next
        return ptr