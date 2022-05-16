# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param lists ListNode类一维数组 
# @return ListNode类
#
import heapq

class Node:
    def __init__(self, node):
        self.node = node
        
    def __lt__(self, other):
        return self.node.val < other.node.val

class Solution:
    def mergeKLists(self , lists: List[ListNode]) -> ListNode:
        # write code here
        pq = []
        
        for l in lists:
            if l:
                heapq.heappush(pq, Node(l))
                
        res = ListNode(0)
        cur = res
        while pq:
            n = heapq.heappop(pq)
            if n.node.next:
                heapq.heappush(pq, Node(n.node.next))
            cur.next = n.node
            cur = cur.next
        return res.next