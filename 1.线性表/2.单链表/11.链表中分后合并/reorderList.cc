// 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//  L0 → L1 → … → Ln-1 → Ln 
// 请将其重新排列后变为：
// L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换

// 分析：实际包含三个动作：链表找中点，后半截逆序，链表合并
// 找中点：快慢指针，两倍速指针到尾部，一倍速指针即为中点
// 逆序：左中右三指针，依次遍历反转
// 合并：遍历，依次插入节点，双指针记录被插入的两节点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode *left_tail = findMiddle(head);
        ListNode *right_head = left_tail->next;
        left_tail->next = nullptr; //断开
        right_head = reverseList(right_head);
        mergeList(head, right_head);
    }

    ListNode *findMiddle(ListNode* head){
        if(head == nullptr)
            return head;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){ //考虑奇偶情况
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

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

    ListNode *mergeList(ListNode* head1, ListNode* head2){
        if(head1 == nullptr || head2 == nullptr)
            return nullptr;
        // p: 左节点 q: 右节点 m: 被插入的中间节点
        ListNode *p = head1, *q = head1->next, *m = head2;
        while(q && m){ 
            //由于m->next后面被改写，此处先暂存
            ListNode *tmp = m->next; 
            //插入
            p->next = m;
            m->next = q;
            //更新指针
            p = q;
            m = tmp;
            q = q->next? q->next: m; //右指针一定要考虑"撞墙" !!
            //对于此题,如果head1如果比head2短,q最终链接到m
            //如果head1和head2一样长，q最终链接到null
            //如果head1比head2长，q始终链接到q->next
        }
        return head1;
    }
};