
//给定一个链表，判断链表中是否有环

// 分析：重点是如何表示有环：遍历链表，如果一个节点被访问两次，表示有环
// 对应两种解法：1.哈希表记录节点访问次数(unordered_set存储节点指针)； 2.快慢指针，在某节点相遇说明有环

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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next; //一次两步
            slow = slow->next;  //一次一步
            if(fast == slow)
                return true;
        }
        return false; //只要 fast->next == null 就说明链表有尾部，没环
    }
};

#include <unordered_set>
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> vis;
        while (head != NULL) {
            if (vis.count(head)) {
                return true;
            }
            vis.insert(head);
            head = head->next;
        }
        return false;
    }
};
