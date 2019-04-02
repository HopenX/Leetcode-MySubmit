/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (44.21%)
 * Total Accepted:    3.2K
 * Total Submissions: 7.2K
 * Testcase Example:  '[1,3,5]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 注意数组中可能存在重复的元素。
 * 
 * 示例 1：
 * 
 * 输入: [1,3,5]
 * 输出: 1
 * 
 * 示例 2：
 * 
 * 输入: [2,2,2,0,1]
 * 输出: 0
 * 
 * 说明：
 * 
 * 
 * 这道题是 寻找旋转排序数组中的最小值 的延伸题目。
 * 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
 * 
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
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, res = nums[0];
        while(left < right - 1){   //一般不需要夹出中间的元素
            int mid = left + (right-left)/2;
            if(nums[left] < nums[mid]){
                res = min(res, nums[left]);
                left = mid + 1;   //left肯定不是，可以舍弃
            }else if(nums[left] > nums[mid]){
                res = min(res, nums[right]);
                right = mid;      //mid需要保留
            }else left++;         //重复则不断移动剔除‰
        }
        //结束时，left和right相邻
        res = min(res, nums[left]);
        res = min(res, nums[right]);
        return res;
    }
};

