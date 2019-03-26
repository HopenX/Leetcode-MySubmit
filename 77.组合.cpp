/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (65.63%)
 * Total Accepted:    8.2K
 * Total Submissions: 12.3K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
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
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> out;
        nextHelper(res, out, 1, k, n);
        return res;
    }
    void nextHelper(vector<vector<int> > &res, vector<int> &out, int level, int k, int n){
        if(out.size() == k) {res.push_back(out); return;}   //已经满k个，达到输出条件
        for(int i = level; i <= n; i++)       //而且从当前level之后开始，可以保证out中有序、不重复
        {
            out.push_back(i);
            nextHelper(res, out, i+1, k, n);  //递归i+1 让helper解决i之后的所有情况
            out.pop_back();
        }
        
    }
};
//组合中level是标记不同的数。out.size 达到 k 才输出
//排列中level标记out已添加的个数。level(即out.size) 达到 nums.size 才输出
//排列中每次从0开始遍历，用 visited 保证不重复，不能有序
