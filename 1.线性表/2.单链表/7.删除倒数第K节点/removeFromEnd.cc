
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点

// 解析：链表倒数节点问题，都是双指针滑动窗口

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) 
        	return nullptr;
        
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy, *q = dummy;
        // 快指针先走 n 步，形成窗口
        for(int i = 0; i < n; ++i){
            q = q->next;
        }
        // 同速度滑动
        while(q->next){
            p = p->next;
            q = q->next;
        }
        // 此时p->next即倒数第n节点, q是尾结点
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;

        return dummy->next;
    }
};