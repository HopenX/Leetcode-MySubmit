/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (61.93%)
 * Total Accepted:    16K
 * Total Submissions: 25.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <set>
#include <iterator>
#include <map>
#include <math.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int> &nums, int left, int right){
        if(left > right) return NULL;  //等于的时候，刚好夹出一个mid
        int mid = left+(right-left)/2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = helper(nums, left, mid-1);
        cur->right = helper(nums, mid+1, right);
        return cur;
    }
};
//根节点应该是有序数组的中间点，从中间点分开为左右两个有序数组，
//再分别找出其中间点作为原中间点的左右两个子节点，所以这道题考的就是二分查找法

//也可以在一个函数中完成递归(创建两个新数组)
class Solution1 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        int mid = nums.size() / 2;
        TreeNode *cur = new TreeNode(nums[mid]);  //这个赋值是关键，把mid赋给cur
        vector<int> left(nums.begin(), nums.begin() + mid), right(nums.begin() + mid + 1, nums.end());
        cur->left = sortedArrayToBST(left);
        cur->right = sortedArrayToBST(right);
        return cur;
    }
};
