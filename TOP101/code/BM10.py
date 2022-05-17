# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#
# 
# @param pHead1 ListNode类 
# @param pHead2 ListNode类 
# @return ListNode类
#
class Solution:
    def FindFirstCommonNode(self , pHead1 , pHead2 ):
        # write code here
        len1 = 0
        cur = pHead1
        while cur:
            cur = cur.next
            len1 += 1
        len2 = 0
        cur = pHead2
        while cur:
            cur = cur.next
            len2 += 1
        if len1 < len2:
            len1, len2 = len2, len1
            pHead1, pHead2 = pHead2, pHead1
        p1 = pHead1
        p2 = pHead2
        for _ in range(len1 - len2):
            p1 = p1.next
        while p1 and p2 and p1 != p2:
            p1 = p1.next
            p2 = p2.next
        if not p1 or not p2:
            return None
        return p1