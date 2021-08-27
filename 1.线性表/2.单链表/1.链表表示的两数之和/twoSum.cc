// Two Sum

// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
// 这两个数都不会以 0 开头。
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

// 分析：重点是进位处理，然后是链表操作的dummy头节点和滑动指针

#include <algorithm> 
#include <vector>
#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); //链表经常创建虚拟头节点，便于链表遍历
        ListNode *pnode = dummy; //滑动指针对应输出链表，初值是虚拟头节点
        int c = 0; //carry bit, 记录进位值
        ListNode *p1 = l1, *p2 = l2; //双指针对应两个待相加链表
        while( p1 != nullptr || p2 != nullptr){
            //先计算当前位的两数之和
            int v1 = (p1 == nullptr)? 0: p1->val;
            int v2 = (p2 == nullptr)? 0: p2->val;
            int v = v1 + v2;
            //考虑进位
            v += c; //加上一轮的进位
            c = v/10;  //判断此轮有没有进位
            v %= 10;  //此轮的非进位数

            //写入节点
            pnode->next = new ListNode(v);

            //指针移到下一个节点
            if(p1 != nullptr)
                p1 = p1->next;
            if(p2 != nullptr)
                p2 = p2->next;
            pnode = pnode->next;
        }

        if(c > 0) //进位的边界情况 
            pnode->next = new ListNode(c); //进位超出原链表
        
        return dummy->next; //dummy节点的作用：能记录头节点
    }
};

    
void createList(ListNode* phead, vector<int> &nums){
    ListNode* p = phead; //滑动指针
    for (int i = 0; i < nums.size(); ++i) {
        //创建新节点
        ListNode* pnode = new ListNode;
        pnode->val = nums[i];
        pnode->next = NULL;
        //链接
        p->next = pnode; 
        p = pnode; 
    }
}

void dbg_print(ListNode *phead){
    cout << "dbg_print:" << endl;
    ListNode *p = phead;
    while(p != nullptr){
        cout << p->val;
        p = p->next;
    }
    cout << endl;
    cout << "dbg_print end" << endl;
}

int main(){
    Solution s;
    std::vector<int> nums = {9,9,9,9,9};
    
    ListNode* dummy = new ListNode();
    createList(dummy, nums);

    ListNode* dummy2 = new ListNode();
    createList(dummy2, nums);

    ListNode *result = s.addTwoNumbers(dummy->next, dummy2->next);
    dbg_print(result);

}