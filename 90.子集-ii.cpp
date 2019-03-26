/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (52.30%)
 * Total Accepted:    5.1K
 * Total Submissions: 9.6K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
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
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int> > res(1);
        sort(nums.begin(), nums.end());
        int last = INT_MAX, sz = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            int tempSize = res.size();
            if(last != nums[i]){  //重复则此句跳过，sz未能更新
                last = nums[i];
                sz = res.size();
            }
            
            for(int j = tempSize-sz; j < tempSize; j++)  //如果为重复，则从j=0开始。重复则减去上一个sz
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

