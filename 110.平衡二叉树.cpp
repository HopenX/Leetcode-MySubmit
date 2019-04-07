/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (46.92%)
 * Total Accepted:    13.7K
 * Total Submissions: 29.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
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
class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getDepth(root->left) - getDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getDepth(TreeNode* node){
        if(!node) return 0;
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }
};

//优化方法：对于每一个节点，我们通过checkDepth方法递归获得左右子树的深度
//如果子树是平衡的，则返回真实的深度，若不平衡，直接返回-1
//此方法时间复杂度O(N)，空间复杂度O(H)，参见代码如下：
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(checkDepth(root) == -1) return false;
        else return true;
    }
    int checkDepth(TreeNode *node){
        if(!node) return 0;
        int left = checkDepth(node->left);
        if(left == -1) return -1;   //子树不平衡，则整棵树肯定不平衡
        int right = checkDepth(node->right);
        if(right == -1) return -1;
        if(abs(checkDepth(node->left) - checkDepth(node->right)) > 1) return -1;
        else return 1 + max(left, right);  //否则返回正常的深度
    }
};

