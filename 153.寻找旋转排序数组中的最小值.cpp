/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (48.49%)
 * Total Accepted:    7.3K
 * Total Submissions: 15K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 你可以假设数组中不存在重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,4,5,1,2]
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
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
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        if(nums[left] > nums[right]){   //小于的话，没有旋转
            while(left != right-1){     //条件：不重合
                int mid = (left+right)/2;
                if(nums[left] < nums[mid]){  //左边有序
                    left = mid;
                }else right = mid;
            }
            return min(nums[left], nums[right]);
        }
        return nums[0];
    }
};
//本题：找由最高到最低 断崖式下跌的那一个点
//注意这里是 left = mid 和 right = mid,因为没有比较 mid = target这种条件，mid不能舍弃
