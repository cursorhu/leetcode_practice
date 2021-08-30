// 给你一个链表的头节点 head，旋转链表，将链表节点向右循环移动 k 个位置

// 输入：head = [1,2,3,4,5], k = 2
// 输出：[4,5,1,2,3]

// 分析: 实际考察的是反向遍历找到第 K 个节点; 
// 解法一：可以先求长度，再求正向偏移 len - k; 首尾相连从 ken - k 处断开即可
// 解法二（通用）：链表反向找第 K 个节点，都可以用固定 K 间隔的双指针，只需一次遍历就可找到反向 K节点
// 解法二在 输入[1,2,3] k = 2000000000 会超时

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) 
            return head;
        
        int len = 0;
        ListNode *tail;
        for(ListNode *p = head; p != nullptr; p = p->next){
            ++len;
            //记录 tail node
            if(p->next == nullptr)
                tail = p;
        }
        // 链表头到反向k节点的偏移；取余是防止 k > len
        int offset = len - k % len;
        
        // 形成环
        tail->next = head;
        while(offset-- != 0){
            tail = tail->next; // 更新尾结点
        }
        head = tail->next; // 更新头节点
        tail->next = nullptr;

        return head;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) 
            return head;
   
        ListNode *p = head, *q = head; //固定 K 距离的快慢双指针, q快 p慢
        // 形成窗口
        for(int i = 0; i < k; ++i){
             q = q->next;
             if(q == nullptr) // 处理 K > 链表长度 的情况!!
                q = head;
        }
           
        // 同速度滑动
        while(q->next){
            p = p->next;
            q = q->next;
        }

        q->next = head; // 形成环
        head = p->next; // 新头
        p->next = nullptr; // 新尾

        return head;
    }
};