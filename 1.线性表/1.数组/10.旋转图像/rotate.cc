// rotate

// 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵

// 算法分析
// 知识点：n*n 矩阵旋转 = 沿着 (副)对角线 + 水平线 翻转，或者 水平线 + (主)对角线 翻转
// 参考 rotate.jpg

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size() ; //边长
        for(int i = 0; i < N; i++){ //行
            for(int j = 0; j < N - i; j++){ //列
                swap(matrix[i][j], matrix[N-1-j][N-1-i]); //沿着(副)对角线，对角替换
            } 
        }
        for(int i = 0; i < N/2; i++){ 
            for(int j = 0; j < N; j++){
                swap(matrix[i][j], matrix[N-1-i][j]); //上下替换
            } 
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
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(matrix);
    for(int i = 0; i < matrix.size(); i++)
        dbg_print(matrix[i]);
}