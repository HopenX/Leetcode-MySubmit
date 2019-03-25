/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (53.46%)
 * Total Accepted:    9.6K
 * Total Submissions: 17.8K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
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
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        combinationDFS(candidates, 0, target, {}, res);
        return res;
    }
    void combinationDFS(vector<int> candidates, int start, int target, vector<int> out, vector<vector<int> > &res){
        if(target < 0) return;     //已经失败
        if (target == 0) {res.push_back(out); return;}   //已经成功
        for(int i = start; i < candidates.size(); i++)   //必须每次从start开始
        {
            if(i > start && candidates[i] == candidates[i-1]) continue;
            out.push_back(candidates[i]);     //回溯法
            combinationDFS(candidates, i+1, target-candidates[i], out, res); //从i+1开始，一直到底
            out.pop_back();     //最后一个出栈，无需传参数
        }
        
        
        //注意 本题是有重复数组.修改的地方有：
        //1.递归调用i+1，防止重复使用当前i
        //2.最开始要sort，然后能利用 candidates[i] == candidates[i-1] 判断重复
    }
};


