// Remove Duplicates from Sorted Array II

// Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
// For example, Given sorted array A = [1,1,1,2,2,3],
// Your function should return length = 5, and A is now [1,1,2,2,3]

// 注意：可拓展到允许重复n个元素


#include <algorithm>  //std::unique
#include <iterator> //std::distance
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 双指针在原数组覆盖，基于数组有序; 时间O(n), 空间O(1)
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        //双指针(下标)遍历
        int idx = 2;
        for(int i = 2; i != nums.size(); i++){
            if(nums[idx - 2] != nums[i]){
                nums[idx++] = nums[i]; //把不同的元素覆盖掉当前idx右边的成员，即从左向右增长unique部分
            }
        }
        return idx; //返回长度
    }
};

// 哈希表计数，此方法不会改变数组，纯粹计数
class Solution2 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        
        int N = 2; //重复2个以下的元素
        int cnt = 0; //记录重复2个以下的元素个数
        std::unordered_map<int, int> hash;
        for(auto iter = nums.begin(); iter != nums.end(); ++iter){
            hash[*iter]++;
            cnt++;
            if(hash[*iter] > N)
                cnt--; //抵消
        }

        // 统计有多少个重复数 < N 的值
        // for(auto iter = hash.begin(); iter != hash.end(); ++iter){
        //     if(iter->second <= N){
        //         cnt++;
        //     }
        // }

        return cnt;
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

    std::vector<int> nums = {1,1,1,2,2,3};
    dbg_print(nums);
    cout << s.removeDuplicates(nums) << endl; //输出 5
    dbg_print(nums);
    
    std::vector<int> nums2 = {1,1,1,2,2,3};
    dbg_print(nums2);
    cout << s2.removeDuplicates(nums2) << endl; //输出 5
    dbg_print(nums2);
}