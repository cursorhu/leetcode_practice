// Trapping Rain Water

// 示例参考 trapwater.jpg

// 算法分析
// 知识点：单调递减栈, 出栈时更新
// https://leetcode-cn.com/problems/trapping-rain-water/solution/trapping-rain-water-by-ikaruga/

#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[st.top()] < height[i])
            {
                int cur = st.top();
                st.pop();
                if (st.empty()) break;
                int l = st.top();
                int r = i;
                int h = min(height[r], height[l]) - height[cur];
                ans += (r - l - 1) * h;
            }
            st.push(i);
        }
        return ans;
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
    vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(vec) << endl;
}