# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head ListNode类 
# @param m int整型 
# @param n int整型 
# @return ListNode类
#
class Solution:
    def reverseBetween(self , head: ListNode, m: int, n: int) -> ListNode:
        # write code here
        if m != 1:
            head.next = self.reverseBetween(head.next, m - 1, n - 1)
            return head
        if n == 0:
            return head
        prev_node = None
        cur = head
        for i in range(n):
            next_node = cur.next
            cur.next = prev_node
            prev_node = cur
            cur = next_node
        head.next = cur
        return prev_node