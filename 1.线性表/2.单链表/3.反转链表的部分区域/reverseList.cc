// Reverse Linked List II

// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
// 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

// 翻转链表一定是 dummy节点 + 头左右三指针; 注意边界
// 参考 https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/yi-ge-neng-ying-yong-suo-you-lian-biao-t-vjx6/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //dummy头节点，所有链表题通用
		auto dummyNode = new ListNode(-1);
		auto h = dummyNode;
        dummyNode->next = head;
		//初始化三指针，指向带翻转节点及其左右节点
		// h:左 p:中 q:右
        for(int i = 0; i < left - 1; i++)
			h = h->next; 
        auto p = h->next; 
		auto q = p->next;

        for(int i = 0; i < right - left; i++){
            // 三指针实现翻转，从被翻转的节点, 然后其左右节点依次处理，即p, q, h
			p->next = q->next;
			q->next = h->next;
			h->next = q;
			// 三指针滑动：画图可以看到，只需要更新q, h保持不动
			q = p->next;
        }
        return dummyNode->next;
    }
};

