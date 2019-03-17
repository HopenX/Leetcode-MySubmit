/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (39.04%)
 * Total Accepted:    18.2K
 * Total Submissions: 46.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
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
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(target-closest);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++)  //每一个i对应一对pointers循环
        {
            int left = i+1, right = nums.size()-1;
            while(left < right){
                int newSum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(newSum - target);

                if (newDiff < diff) {
                    diff = newDiff;
                    closest = newSum;
                }
                
                if(newSum < target) left++;
                else right--;
            }
        }
        return closest;
        
    }
};

