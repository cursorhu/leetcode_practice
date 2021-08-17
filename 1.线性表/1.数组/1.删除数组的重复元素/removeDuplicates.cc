// Remove Duplicates from Sorted Array

// Given a sorted array, remove the duplicates in place such that each element appear only once
// and return the new length.
// Do not allocate extra space for another array, you must do this in place with constant memory.
// For example, Given input array A = [1,1,2],
// Your function should return length = 2, and A is now [1,2]

// 注意：不允许开新空间，只能在原数组操作
// 为什么一定要有序：有序代表重复元素一定挨在一起；如果无序，例如 [1,2,3,2,3]，以下算法会输出 5
// 如果题目没有给出有序，可以把数组先变成有序 std::sort(nums.begin(), nums.end());
// 如果不允许修改原数组，没有开辟内存的限制，用哈希表；对于是否有重复元素的问题是通用

#include <algorithm>  //std::unique
#include <iterator> //std::distance
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 使用 STL 的 unique 和 distance; 时间O(n), 空间O(1)
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        //原地移除重复的元素，要求数组有序
        //返回iterator指向最后一个不重复元素的位置，重复的元素被移动到了返回位置到末尾位置的范围
        auto end_iter = std::unique(nums.begin(), nums.end()); 
        return std::distance(nums.begin(), end_iter); //获取指定范围内包含元素的个数
    }
};

// 双指针在原数组覆盖，与 std::unique 的区别是不是挪动，而是覆盖; 时间O(n), 空间O(1)
class Solution2 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.empty())
            return 0;
        //双指针(下标)遍历
        int idx = 0;
        for(int i = 1; i != nums.size(); i++){
            if(nums[idx] != nums[i]){
                nums[++idx] = nums[i]; //把不同的元素覆盖掉当前idx右边的成员，即从左向右增长unique部分
            }
        }
        return idx + 1; //返回长度
    }
};

// 哈希表保证不重复的键，数组的元素作为键;
class Solution3 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        std::unordered_map<int, int> hash;
        for(auto iter = nums.begin(); iter != nums.end(); ++iter){
            hash[*iter] = 1;
        }
        return hash.size(); //hash表的元素个数，即不重复个数
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
    Solution2 s2;
    Solution3 s3;

    std::vector<int> nums = {1,1,2,2,3};
    dbg_print(nums);
    cout << s.removeDuplicates(nums) << endl; //输出 3
    dbg_print(nums);
    cout << s.removeDuplicates(nums) << endl; //输出 5
    
    //此时nums已经变成[1,2,3,2,3], 因此需要sort一下
    sort(nums.begin(), nums.end());
    dbg_print(nums);
    
    cout << s2.removeDuplicates(nums) << endl; //输出 3
    dbg_print(nums); //此时nums变成[1,2,3,3,3]
    //哈希表方式不需要数组有序
    cout << s3.removeDuplicates(nums) << endl; //输出 3
}