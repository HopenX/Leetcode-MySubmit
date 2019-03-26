/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (41.80%)
 * Total Accepted:    10.4K
 * Total Submissions: 24.6K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
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
    int trap(vector<int>& height) {
        int n = height.size(), mx = 0, res = 0;
        vector<int> dp(n, 0);
        //此时mx表示柱子i往左边所有柱子的最大值，初始为0，地面
        //dp[i]负责存储每一个mx
        for(int i = 0; i < n; i++)
        {
            dp[i] = mx;  //保存上一个mx，即左边的
            mx = max(mx, height[i]);
        }
        mx = 0;
        //此时 mx 表示右边的最大值，初始为0，地面
        //左边最大的+右边最大的 -> 得知本柱子最大高度 -> 存储在dp[i]中
        for(int i = n-1; i > 0; i--)
        {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if(dp[i] > height[i]) res += (dp[i]-height[i]);
        }
        return res;
    }
};

class Solution1 {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            int mn = min(height[l], height[r]);
            if (mn == height[l]) {
                ++l;
                while (l < r && height[l] < mn) {
                    res += mn - height[l++];
                }
            } else {
                --r;
                while (l < r && height[r] < mn) {
                    res += mn - height[r--];
                }
            }
        }
        return res;
    }
};
/*
最后我们来看一种只需要遍历一次即可的解法，这个算法需要left和right两个指针分别指向数组的首尾位置，
从两边向中间扫描，在当前两指针确定的范围内，先比较两头找出较小值，如果较小值是left指向的值，
则从左向右扫描，如果较小值是right指向的值，则从右向左扫描，若遇到的值比当较小值小，
则将差值存入结果，如遇到的值大，则重新确定新的窗口范围，以此类推直至left和right指针重合，具体参见代码如下：
*/
