// Median of Two Sorted Arrays

// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
// 请你找出并返回这两个正序数组的 中位数 。

// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2

// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：2.50000
// 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

// *** 此题可以拓展到 求合并数组第 K 大的数 ***//

#include <algorithm> 
#include <iterator> //back_inserter
#include <vector>
#include <iostream>
using namespace std;

// 按部就班解决：排序(题目已有)，合并(STL merge)，求中位数；时间复杂度 O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // merge() 函数用于将 2 个有序序列合并为 1 个有序序列，
        // 这 2 个有序序列的排序规则相同（要么都是升序，要么都是降序）。
        // 获得新有序序列，其排序规则也和这 2 个有序序列相同。
        // 需要创建新 vector 存储 merge 的输出, 两种方式：
        // back_inserter不需要提前准备空间, 其中包含了push_back操作
        // 提前resize分配空间：v3.resize(v1.size()+v2.size());
        // 不能直接空vector.begin()传给 merge !
        vector<int> vecout;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(vecout));
        
        // vector<int> vecout;
        // vecout.resize(nums1.size() + nums2.size());
        // merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(vecout.begin()));
        
        //求中位数，考虑奇偶
        if(vecout.size() % 2 != 0){
            return vecout[vecout.size()/ 2];
        }else{
            return (double)( vecout[vecout.size()/ 2 - 1] + vecout[vecout.size()/ 2] )/ 2;
        }
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

    std::vector<int> nums1 = {1,2};
    std::vector<int> nums2 = {3,4};
    std::vector<int> nums3 = {3};
    
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    cout << s.findMedianSortedArrays(nums1, nums3) << endl;
}