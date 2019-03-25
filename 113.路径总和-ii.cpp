/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (52.30%)
 * Total Accepted:    6.6K
 * Total Submissions: 12.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> out;
        searchHelper(root, sum, out, res);
        return res;
    }
    void searchHelper(TreeNode* node, int sum, vector<int> &out, vector<vector<int> > &res){
        if(!node) return;
        out.push_back(node->val);
        if(node->val == sum && !node->left && !node->right){
            res.push_back(out);
        }
        else    //加个else更好，已经成功后，下面不用执行（已经是根节点）
        {
            searchHelper(node->left, sum - node->val, out, res);
            searchHelper(node->right, sum - node->val, out, res);
        }
        out.pop_back();   
        //能到这里，两个helper都经过了，说明上面已经是根节点了，或者仍没有return，移除该节点（对应上面从left换到right）
        //如果从left换到right还没有，再pop一层
        //如果成功了，也要pop，不管成功失败，都要换一条路继续搜
    }
};

