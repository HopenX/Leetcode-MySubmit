/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.85%)
 * Total Accepted:    42.7K
 * Total Submissions: 98.5K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
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
class Solution1 {  //O(n)复杂度
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curSum = 0;
        for(int num : nums){
            curSum = max(num, curSum+num);  //curSum是记录：必须包含当前位的情况下，最大的和
            res = max(curSum, res);  //res是绝对变量，历史最大的数，和位置无关
        }
        return res;
    }
};

class Solution {  //O(nlogn)复杂度
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        return helper(nums, 0, nums.size()-1);
    }

    int helper(vector<int> &nums, int left, int right){
        if(left >= right) return nums[left];
        int mid = left + (right-left)/2;
        int lmax = helper(nums, left, mid-1);
        int rmax = helper(nums, mid+1, right);

        int mmax = nums[mid], tempSum = mmax;
        for(int i = mid-1; i >= left; i--)
        {
            tempSum += nums[i];         //t始终是从中间加过去的sum
            mmax = max(mmax, tempSum);  //和上面两次max的区别就是，这里的mmax是必须包含mid的情况
        }
        tempSum = mmax;  //关键！以已经得到的mmax为基础
        for(int i = mid+1; i <= right; i++)
        {
            tempSum += nums[i];
            mmax = max(mmax, tempSum);
        }
        return max(mmax, max(lmax, rmax));
    }
};

/*
1.仅包含左半部分的最大子序列
2.仅包含右半部分的最大子序列
3.一定包含中间数字的序列（先向左探测，得到一个往左的mmax，再基于这个mmax向右探测）
*/
