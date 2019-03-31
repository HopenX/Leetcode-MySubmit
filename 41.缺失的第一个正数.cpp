/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (35.38%)
 * Total Accepted:    10.5K
 * Total Submissions: 29.8K
 * Testcase Example:  '[1,2,0]'
 *
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,0]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,4,-1,1]
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,8,9,11,12]
 * 输出: 1
 * 
 * 
 * 说明:
 * 
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
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
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]){  //等于本身则停止循环
                swap(nums[i], nums[nums[i] -1]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i + 1) return i+1;
        }
        return n+1;   
    }
};


/*
O(n)时间 → 一次遍历； 常数级别空间/不使用额外空间 → 原地交换swap
在一个i的位置，对nums[i]反复换位，让每一个数字排列在它数值所在的位置。数值大于n则忽略
-1 4 3 1
-1 1 3 4
1 -1 3 4
*/
