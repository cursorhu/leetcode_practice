// Reverse Linked List

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表

// 反转必须保留节点前后位置，用双指针
// 注意，p->next 操作一定要考虑边界情况，p是否为空

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
    ListNode* reverseList(ListNode* head) {
    	//此处不判空，head->next非法
        if(head == nullptr)
            return head;
        ListNode *pleft = NULL; //左指针，初始值是头节点左侧节点，即空节点
    	ListNode *pright = head->next; //右指针，初始值是head右侧节点
    	while(head != nullptr)
    	{
            //反转当前节点链接
    		head->next = pleft; 
    		//依次更新左中右指针
            pleft = head;
    		head = pright;
            pright = (head == nullptr)? nullptr: head->next; //pright最终和head一样都是nullptr
    	}
    	return pleft; //此时head为链表尾:null
    }
};
