// plusOne

// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字

// 算法分析
// 一般情况：最低位加一，结束；可能情况：有进位，进位值加到高位；边界情况，9999 + 1 数组需要扩张； 
// 需要从右向左遍历并将进位值加到高位
// 反向遍历： rbegin 到 rend

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1; //carry bit, 进位值；初始为 1 作为下面循环初始值
        for(auto iter = digits.rbegin(); iter != digits.rend(); ++iter){
            *iter += c; //加上一轮的进位
            c = *iter/10;  //判断此轮有没有进位
            *iter %= 10; 
        }
        if(c > 0) //边界情况 
            digits.insert(digits.begin(), c); //insert是在左侧插入
        
        return digits;
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
    vector<int> vec = {9,9,9,9,9};
    vec = s.plusOne(vec);
    dbg_print(vec);
}