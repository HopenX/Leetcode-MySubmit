/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 *
 * https://leetcode-cn.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (39.07%)
 * Total Accepted:    7.6K
 * Total Submissions: 19.6K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 峰值元素是指其值大于左右相邻值的元素。
 * 
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 
 * 你可以假设 nums[-1] = nums[n] = -∞。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1]
 * 输出: 2
 * 解释: 3 是峰值元素，你的函数应该返回其索引 2。
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,2,1,3,5,6,4]
 * 输出: 1 或 5 
 * 解释: 你的函数可以返回索引 1，其峰值元素为 2；
 * 或者返回索引 5， 其峰值元素为 6。
 * 
 * 
 * 说明:
 * 
 * 你的解法应该是 O(logN) 时间复杂度的。
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
class Solution1 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //if(n == 1) return 0;  不必
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < nums[i-1]) return i-1;
        }
        return n-1;  //如果len是1，返回0. 如果len是0，返回-1
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int left = 0, right = n-1;

        while(left+1 < right){
            int mid = (left + right)/2;
            if (mid > 0 && nums[mid-1] < nums[mid]) left = mid;
            else right = mid;
        }
        return nums[left] > nums[right] ? left : right;

    }
};

//方法一：首尾垫值，首尾添加一个INT_MIN
//方法二：递增判断，如果某数小于前面某数，前数就是峰值,否则继续遍历
//方法三：传统的二分查找吧，速度快点
