# BM3. 链表中的节点每k个一组翻转
**Difficulty:** Meidum

## URL

https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
# @param k int整型 
# @return ListNode类
#
class Solution:
    def reverseKGroup(self , head: ListNode, k: int) -> ListNode:
        # write code here
        next_head = head
        for _ in range(k):
            if not next_head:
                return head
            next_head = next_head.next
        cur = head
        prev = None
        while cur != next_head:
            next_node = cur.next
            cur.next = prev
            prev = cur
            cur = next_node
        head.next = self.reverseKGroup(next_head, k)
        return prev
```

