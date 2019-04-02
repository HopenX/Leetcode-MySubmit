/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode-cn.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (58.35%)
 * Total Accepted:    7.9K
 * Total Submissions: 13.5K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和
 * n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,4,2,2]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,3,4,2]
 * 输出: 3
 * 
 * 
 * 说明：
 * 
 * 
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n^2) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次。
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
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1;  //这里size 或者 size-1 都通过
        while(left < right){
            int mid = (left+right)/2, cnt = 0;
            for(int num : nums) if(num <= mid) cnt++;
            if(cnt <= mid) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};

//1-n的范围，1+n个数字，类比抽屉原理
//特殊的二分搜索，不是对位置搜索，而是对数值

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        while(true){
            slow = nums[slow];
            t = nums[t];
            if(slow == t) break;
        }
        return slow;
    }
};
//利用成环的骚操作，类比于环形链表的快慢指针。利用坐标与数值相互转换，模拟实现next->next效果
