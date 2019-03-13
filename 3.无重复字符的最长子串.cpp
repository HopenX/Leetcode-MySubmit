/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.36%)
 * Total Accepted:    86.1K
 * Total Submissions: 303.5K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 示例 1:
 *
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
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

class Solution {  //滑动窗口法
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> m;  //存储每个字符最后出现的位置
        int left=-1, res=0, n=s.length();  //窗口的最左边,无重复窗口的历史最大值
        for(int i = 0; i < n; i++)
        {
            if(m.count(s[i]) && m[s[i]]>left){
                left = m[s[i]];  //窗口左边界更新，保证窗口内无重复
            }
            m[s[i]] = i;  //字符最后出现的位置
            res = max(res, i-left);
        }
        return res;
    }
};

