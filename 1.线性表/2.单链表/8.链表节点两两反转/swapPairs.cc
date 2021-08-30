
// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换
// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]

// 分析：实际是反转链表的子类题目，基本套路还是左中右三指针

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *dummy = new ListNode(-1, head); //创建dummy链接到head
        ListNode *left = dummy, *mid = head, *right = head->next; //初始化左中右指针

        //边遍历边处理
        while(right != nullptr){
            left->next = right;
            mid->next = right->next;
            right->next = mid;

            //滑动指针，要画图理解; 注意右指针“撞墙(null)”
            left = mid;
            mid = mid->next;
            right = (mid == nullptr)? nullptr: mid->next;
        }
        return dummy->next;
    }     
};