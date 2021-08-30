//反向打印链表，不允许使用额外的vector数组，不允许反转链表

// 分析：除了两个不允许，其他的能逆序的方法就是堆栈
// 堆栈的一种实现就是利用函数递归

#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void reverseOutputLinkList (ListNode* head) {
        if(head == nullptr)
            return;

        ListNode *p = head->next; 
        if(p != nullptr){   // 注意递归只需要用if而不是while
           reverseOutputLinkList(p);
        }
        printf("%d\n", head->val);
        return;
    }     
};


void createList(ListNode* phead, vector<int> &nums){
    ListNode* p = phead; //滑动指针
    for (int i = 0; i < nums.size(); ++i) {
        //创建新节点
        ListNode* pnode = new ListNode;
        pnode->val = nums[i];
        pnode->next = nullptr;
        //链接
        p->next = pnode; 
        p = pnode; 
    }
}


int main(){
    Solution s;
    std::vector<int> nums = {1,2,3,4,5};
    
    //用数组创建链表
    ListNode* dummy = new ListNode();
    createList(dummy, nums);

    s.reverseOutputLinkList(dummy->next);

}