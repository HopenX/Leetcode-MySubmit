/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (66.55%)
 * Total Accepted:    18.4K
 * Total Submissions: 27.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
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
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> out, visited(nums.size(), 0);
        nextHelper(res, out, nums, visited, 0);
        return res;
    }
    void nextHelper(vector<vector<int> > &res, vector<int> &out, vector<int> nums, vector<int> &visited, int level){
        if(level == nums.size()) {res.push_back(out); return;}
        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            nextHelper(res, out, nums, visited, level+1);
            out.pop_back();
            visited[i] = 0;    //pop之后，回溯，当做没访问过
        }
    }
};
/*
这里我们需要用到一个visited数组来标记某个数字是否访问过，然后在DFS递归函数从的循环应从头开始，
而不是从level开始，这是和 Combinations 不同的地方，其余思路大体相同。这里再说下level吧，
其本质是记录当前已经拼出的个数，一旦其达到了nums数组的长度，说明此时已经是一个全排列了
*/

