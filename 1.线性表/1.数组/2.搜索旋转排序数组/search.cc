// Search in Rotated Sorted Array

// 整数数组 nums 按升序排列，数组中的值 互不相同 。
// 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
// 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
// 例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
// 给你 旋转后的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。


#include <iterator> //std::distance
#include <vector>
#include <iostream>
using namespace std;

// STL: 直接iterator枚举
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(auto iter = nums.begin(); iter != nums.end(); ++iter){
            if(*iter == target){
                return distance(nums.begin(), iter); //用 iterator 获得下标的方法
            }
        }
        return -1;
    }
};

// 二分
class Solution2 {
public:
    int search(const vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while (first != last) {
            const int mid = first + (last - first) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[first] <= nums[mid]) {
                if (nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[last-1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }
        return -1;
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

    std::vector<int> nums = {4,5,6,7,0,1,2};
    dbg_print(nums);
    
    cout << s.search(nums, 0) << endl;
    cout << s.search(nums, -1) << endl;
    
    cout << s2.search(nums, 7) << endl;
    cout << s2.search(nums, -1) << endl;
}