/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (33.90%)
 * Total Accepted:    7.6K
 * Total Submissions: 22.4K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 
 * 
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * 输出: false
 * 
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <iterator>
#include <map>
#include <math.h>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        if(target < matrix[0][0] || target > matrix.back().back()) return false;  //勿忘边界条件
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m - 1;
        while(left <= right){   //边界条件是关键，<=
            int mid = (left+right)/2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target) left = mid + 1;
            else right = mid - 1;
        }
        int tmp = right;
        left = 0;
        right = n - 1;
        while(left <= right){  //此处也一样，允许left right 重合，重合就等于mid
            int mid = (left+right)/2;
            if(matrix[tmp][mid] == target) return true;
            else if(matrix[tmp][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

//使用 <= 是因为即使left和right重合，中间也还有很多数，要继续
//15 16 17 18 19
//20 21 22 23 24
//25 26 27 28 29
//此处的 mid = 0 时，[mid]为15，但是大于mid有两种情况，18和22，需要再把[mid]为20，再判断
