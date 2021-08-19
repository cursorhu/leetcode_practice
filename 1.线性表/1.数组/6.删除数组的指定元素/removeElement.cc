// Remove Elements

// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度


#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0; //单指针
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != val){
                nums[index++] = nums[i]; //原地覆盖
            }
        }
        return index;
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
   
    std::vector<int> nums = {1,1,2,3};
    dbg_print(nums);
    cout << s.removeElement(nums, 1) << endl; 
    dbg_print(nums);
}