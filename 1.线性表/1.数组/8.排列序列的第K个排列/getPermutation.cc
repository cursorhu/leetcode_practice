// Permutation Sequence

// 这题可以调用“下一个字典序排列的函数”，但是需要一个个更新到第 K 个序列。

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

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

    //int vector to string
    void ivec_to_string(vector<int>& nums, string & s){
        char ch;
        for (int i = 0; i < nums.size(); i++) {
            ch = nums[i] + '0';
            s += ch;
        }
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; ++i){
            nums.push_back(i);
        }
        for(int i = 1; i < k; ++i){
            nextPermutation(nums);
        }
        string result;
        ivec_to_string(nums, result);
        return result;
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
   
    cout << s.getPermutation(3, 6) << endl;
}