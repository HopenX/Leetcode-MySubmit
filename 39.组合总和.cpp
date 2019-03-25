/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (62.39%)
 * Total Accepted:    13.4K
 * Total Submissions: 21.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        combinationDFS(candidates, 0, target, {}, res);
        return res;
    }
    void combinationDFS(vector<int> candidates, int start, int target, vector<int> out, vector<vector<int> > &res){
        if(target < 0) return;     //已经失败
        if(target == 0) {res.push_back(out); return; }   //已经成功
        for(int i = start; i < candidates.size(); i++)   //必须每次从start开始
        {
            out.push_back(candidates[i]);     //回溯法
            combinationDFS(candidates, i, target-candidates[i], out, res); //从当前i开始，一直到底
            out.pop_back();     //最后一个出栈，无需传参数
        }
        //注意 本题是无重复数组
    }
};

