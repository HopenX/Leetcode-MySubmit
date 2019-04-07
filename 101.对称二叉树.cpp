/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.70%)
 * Total Accepted:    27.4K
 * Total Submissions: 59.8K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
//递归写法 在与调用的时候 比较「左左」和「右右」,「左右」和「右左」
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if((!left && right) || (!right && left) || left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

//迭代写法，两条队列，插入顺序：左右右左
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left); 
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            TreeNode* node1 = q1.front(); q1.pop();
            TreeNode* node2 = q2.front(); q2.pop();
            if(!node1 && !node2) continue;
            if((!node1 && node2) || (!node2 && node1)) return false;
            if(node1->val != node2->val) return false;
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->right);
            q2.push(node2->left);
        }
        return true;
    }
};

