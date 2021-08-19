// Two Sum

// 给定一个整数数组 nums 和一个整数目标值 target，
// 在该数组中找出 和 为目标值 target 的那两个整数，并返回它们的数组下标

// 分析：
// 哈希存下标，foreach 遍历 hash 找符合条件的成员

#include <algorithm> 
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(auto iter = nums.begin(); iter != nums.end(); ++iter){
            hash[*iter] = distance(nums.begin(), iter);
        } 

        vector<int> vecout;
        // for(auto e : hash){ //for-each遍历支持hashmap
        //     auto iter = hash.find(target - e.first); //find 返回 iterator
        //     if(iter != hash.end()){ //存在此数
        //         vecout.push_back(e.second); //second即index
        //         vecout.push_back(iter->second);
        //         break; //找到立即返回
        //     }
        // }
        
        for(int i = 0; i < nums.size(); ++i){ //遍历数组而不是遍历hash，因为可能有重复成员
            auto iter = hash.find(target - nums[i]);
            if(iter != hash.end() && (iter->second > i)){ //顺序排列
                vecout.push_back(i);
                vecout.push_back(iter->second);
                break; //找到立即返回
            }
        }
        return vecout; //没找到返回空
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

    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {1,1};

    std::vector<int> tempvec(s.twoSum(nums1, 3));
    dbg_print(tempvec);
    tempvec = s.twoSum(nums2, 2);
    dbg_print(tempvec);
}