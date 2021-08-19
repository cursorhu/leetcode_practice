// Next Permutation

// 实现 下一个排列 的函数，算法需要将给定数字序列重新排列,重新排列的数字序列是原序列的下一个更大的字典序排列
// 等价于：
// 给定若干个数字，将其组合为一个整数。将这些数字重新排列，以得到下一个更大的整数。
// 如 123 下一个更大的字典序数为 132，注意要字典序要求相邻的，不能是 213 也不是 312

// 归纳分析：
// 以 1,2,3,4,5,6 为例，其字典排列依次为：
// 123456
// 123465
// 123546
// ...
// 654321
// 可见有这样的关系：123456 < 123465 < 123546 < ... < 654321
 
// 算法推导
// 我们希望下一个数比当前数大，这样才满足“下一个排列”的定义。因此只需要将后面的「大数」与前面的「小数」交换，就能得到一个更大的数。
// 比如 123456，将 5 和 6 交换就能得到一个更大的数 123465。
// 我们还希望下一个数增加的幅度尽可能的小，这样才满足“下一个排列与当前排列紧邻“的要求。为了满足这个要求，我们需要：
// 在尽可能靠右的低位进行交换，需要从后向前查找
// 将一个 尽可能小的「大数」 与前面的「小数」交换。比如 123465，下一个排列应该把 5 和 4 交换而不是把 6 和 4 交换
// 将「大数」换到前面后，需要将「大数」后面的所有数重置为升序，升序排列就是最小的排列。以 123465 为例：
// 交换 5 和 4，得到 123564；然后需要将 5 之后的数重置为升序，得到 123546。显然 123546 比 123564 更小，123546 就是 123465 的下一个排列
// 考虑边界情况，排序到最后，一定是逆序的；在排序过程中，从右到左有动态的“从正序到逆序”的过程；
// 因此如果右侧子序列已经完全逆序，要交换的数一定是子序列以外左侧的第一个数，因为“低位优先”
// 以上就是求“下一个排列”的分析过程。

// 作者：imageslr
// 链接：https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool compare(int a, int b){
    return a < b;
}

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int index = nums.size() - 2; //表示逆序子序列左侧的第一个位置
        while(index >= 0 && nums[index] >= nums[index+1]){ //向左搜索逆序(或相等)子序列的左边界位置
            index--;
        }
        if(index < 0){ //整个数组已经逆序，按题目要求返回正序数组
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j = nums.size() - 1; j > index; j--){ //只需遍历子序列，找到可交换数
            if(nums[index] < nums[j]){ 
                swap(nums[index], nums[j]);
                sort(nums.begin() + index + 1, nums.end());
                return ;
            }
        }
        return ;
    }
};


void dbg_print(std::vector<int>& nums){
    cout << "dbg_print:" << endl;
    for(auto iter = nums.begin(); iter != nums.end(); ++iter){
        cout << *iter << endl;
    }
    cout << "dbg_print end" << endl;
}

int main(){
    Solution s;
   
    std::vector<int> nums = {1,2,5,4,3};
    dbg_print(nums);
    s.nextPermutation(nums);
    dbg_print(nums); 

    std::vector<int> nums2 = {1,2,2,3,3};
    dbg_print(nums2);
    s.nextPermutation(nums2);
    dbg_print(nums2); 
}