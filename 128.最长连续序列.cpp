/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (41.43%)
 * Total Accepted:    5.2K
 * Total Submissions: 12.5K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
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
#include <unordered_set>
#include <math.h>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int val : nums){
            if(!s.count(val)) continue;
            int pre = val-1, nex = val+1;
            while(s.count(pre)) s.erase(pre--);
            while(s.count(nex)) s.erase(nex++);
            res = max(res, nex-pre-1);
        }
        return res;
    }
};
//为啥当检测某数字在集合中存在当时候，都要移除数字。这是为了避免大量的重复计算
//HashSet 存取高效O(1)复杂度

