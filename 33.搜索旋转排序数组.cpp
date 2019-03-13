/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (35.68%)
 * Total Accepted:    16.6K
 * Total Submissions: 46.3K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
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

class Solution {  //比较中间与首尾->判断哪边有序就和哪边比较->判断保留哪边
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < nums[right]){  //右边有序
                if(nums[mid] < target && nums[right] >= target){
                    left = mid+1;
                }else
                {
                    right = mid-1;
                }
            }else  //左边有序
            {
                if(nums[mid] > target && nums[left] <= target){
                    right = mid-1;
                }else
                {
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};

