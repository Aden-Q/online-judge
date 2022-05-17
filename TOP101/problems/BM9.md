# BM9. 删除链表的倒数第n个节点
**Difficulty:** Medium

## URL

https://www.nowcoder.com/practice/f95dcdafbde44b22a6d741baf71653f6?tpId=295&tqId=727&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295

## Solution

### Approach 1:

The code is shown below:

```python
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head ListNode类 
# @param n int整型 
# @return ListNode类
#
class Solution:
    def removeNthFromEnd(self , head: ListNode, n: int) -> ListNode:
        # write code here
        dummy = ListNode(0)
        dummy.next = head
        if not head:
            return head
        fast = head
        for _ in range(n):
            fast = fast.next
        prev = dummy
        slow = head
        while fast:
            fast = fast.next
            prev = slow
            slow = slow.next
        prev.next = slow.next
        return dummy.next
```

