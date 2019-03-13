/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.04%)
 * Total Accepted:    39.7K
 * Total Submissions: 186.1K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
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
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        if(nums.empty() || nums.front() > 0 || nums.back() < 0 ) return {};

        for(int k = 0; k < nums.size(); k++)  //对每一个元素，从它之后开始找，维护一个区域
        {
            if(nums[k] > 0) break;
            if(k>0 && nums[k] == nums[k-1]) continue;
            int target = 0-nums[k];
            int i = k+1, j = nums.size()-1;
            while(i<j){
                if(nums[i] + nums[j] == target){
                    res.push_back({nums[k], nums[i], nums[j]});
                    while(i<j && nums[i] == nums[i+1]) i++;  //跳过后方重复的
                    while(i<j && nums[j] == nums[j-1]) j--;
                    i++; j--;   //同时缩小两边，继续寻找
                }else if (nums[i] + nums[j] < target) {
                    i++;
                }else{
                    j--;
                }
            }
        }
        return res;
    }
};

