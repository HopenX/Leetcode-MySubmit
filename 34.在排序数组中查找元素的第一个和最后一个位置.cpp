/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (35.24%)
 * Total Accepted:    13.2K
 * Total Submissions: 37.4K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
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
    vector<int> searchRange(vector<int>& nums, int target) {
          int n= nums.size();
          if(n == 0) return {-1, -1};
          int idx = bin_search(nums, 0, n-1, target);
          if(idx == -1) return {-1, -1};
          int low = idx, high = idx;
          while(low>0 && nums[low-1] == nums[idx]) low--;
          while(high<n-1 && nums[high+1] == nums[idx]) high++;
          return {low, high};
          
    }

    int bin_search(vector<int>& nums, int left, int right, int target){
        if(left > right) return -1;
        int mid = left+(right-left)/2;
        if (nums[mid] == target) {
            return mid;
        }else if (nums[mid] < target) {
            return bin_search(nums, mid+1, right, target);
        }else
        {
            return bin_search(nums, left, mid-1, target);
        }
    }
};

