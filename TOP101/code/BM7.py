# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        if not pHead or not pHead.next:
            return None
        slow = pHead
        fast = pHead
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                # 成环
                break
        if not fast or not fast.next:
            return None
        # 找环起点
        fast = pHead
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return slow