/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (25.00%)
 * Total Accepted:    18.8K
 * Total Submissions: 74.8K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);  //空树是二叉搜索树
    }

    bool isValidBST(TreeNode* node, long mn, long mx){   //重载,mn是node应该有的下界，mx是node应该有的上界
        if(!node) return true;
        if(node->val >= mx || node->val <= mn) return false;
        return isValidBST(node->left, mn, node->val) && isValidBST(node->right, node->val, mx);
    }
};

//利用性质，中序遍历是有序的
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> res;
        inorder(root, res);
        for(int i = 0; i < res.size()-1; i++)
        {
            if(res[i+1] <= res[i]) return false;
        }
        return true;
        
    }
    void inorder(TreeNode* node, vector<int> &res){
        if(node->left) inorder(node->left, res);
        res.push_back(node->val);
        if(node->right) inorder(node->right, res);
    }
};

