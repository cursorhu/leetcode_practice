// Longest Consecutive Sequence

// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
// 实现时间复杂度为 O(n) 的算法解决此问题
// 示例： nums = [100,4,200,1,3,2] 输出 4

// 分析：
// 如果数组有序那么连续序列一定在一起，找出最长的即可，但是排序复杂度至少 O(nlogn)，不符合此题要求
// 无序不连续的 且要求 O(n)，首选哈希表; 
// 遍历数组，每轮遍历以当前元素值为中心，哈希表中 find 其左右值，同时迭代连续值的长度

// 注意这题的连续是值连续，和动态规划解法的连续上升子序列的下标连续不同

#include <algorithm> 
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;
        for(auto e : nums) 
            used[e] = false; //哈希表记录是否有某个值
        int longest = 0; //记录最长序列

        //遍历一遍，同时在哈希表查找左右值
        for(auto e : nums){
            if(used[e]) continue; //避免重复搜索

            int length = 1; //以当前元素的值为中心搜索的连续序列长度
            used[e] = true;

            //以当前值为中心，查找哈希表的左右相邻值，同时更新连续值的长度
            for(int v = e + 1; used.find(v) != used.end(); ++v){
                length++;
                used[v] = true; //避免重复搜索
            }
            for(int v = e - 1; used.find(v) != used.end(); --v){
                length++;
                used[v] = true; 
            }

            longest = max(length, longest);
        }
        return longest;
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

    std::vector<int> nums = {1,2,3,0,2,3,4,5};
    dbg_print(nums);
    
    cout << s.longestConsecutive(nums) << endl;
}