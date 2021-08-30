// Remove Duplicates from Sorted List

// 存在一个按升序排列的链表，给你这个链表的头节点 head ，
// 请你删除所有重复的元素，使每个元素 只出现一次 。
// 返回同样按升序排列的结果链表

// 解析：有序链表的重复元素一定在一起，双指针边遍历边删除节点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) 
        	return nullptr;
	    // 删除节点只需要双指针指向相邻节点
	    ListNode *p = head, *q = head->next;
	    while (q != nullptr) {
	    	// 删除节点标准操作
	        if (p->val == q->val) {
                p->next = q->next;
                delete q;
                q = p->next;
	        }else{  // 滑动双指针
                p = q;
                q = q->next;
            }
	    }
	    return head;
	}
};
