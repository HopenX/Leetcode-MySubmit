/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.72%)
 * Total Accepted:    25.5K
 * Total Submissions: 39.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
class Solution1 {   //递归写法
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    void inorder(TreeNode* root, vector<int> &res){
        if(!root) return;
        if(root->left) inorder(root->left, res);
        res.push_back(root->val);
        if(root->right) inorder(root->right, res);
    }
};

class Solution {  //迭代写法
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(!st.empty() || node){   //满足条件的并集
            while(node){
                st.push(node);
                node = node -> left;  //每个新的node，不断把左孩子入栈
            }
            if(!st.empty()){
                node = st.top(); st.pop();
                res.push_back(node->val);
                node = node -> right;
            }
        }
        return res;
    }
};
