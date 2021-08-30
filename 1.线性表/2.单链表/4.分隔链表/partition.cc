// Partition List

// 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，
// 使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置

// 输入：head = [1,4,3,2,5,2], x = 3
// 输出：[1,2,2,4,3,5]

// 解析：典型题。链表根据某条件拆分后重组，拆分的链表可称为左右子链表
// 用双指针在遍历原链表时生成左右子链表, 最后链接

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
    ListNode* partition(ListNode* head, int x) {
        //原dummy头节点要记录, 最后要用
        auto dummy_left = new ListNode(-1);
        auto dummy_right = new ListNode(-1);
        //滑动指针另外定义
        auto pleft = dummy_left;
        auto pright = dummy_right;
        for(ListNode *h = head; h != nullptr; h = h->next){
            if(h->val < x){
                pleft->next = h; //左子链表添加节点
                pleft = h; //更新滑动指针
            }else{
                pright->next = h;
                pright = h;
            }
        }
        //链接左右子链表
        pleft->next = dummy_right->next;
        pright->next = nullptr;

        return dummy_left->next;
    }
};
