/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (51.61%)
 * Total Accepted:    2.6K
 * Total Submissions: 5K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 * 
 * 请在不改变其结构的情况下，恢复这棵树。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * 输出: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * 输出: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 进阶:
 * 
 * 
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
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
/*
说是其中有两个的顺序被调换了，题目要求上说O(n)的解法很直观，这种解法需要用到递归，用中序遍历树，
并将所有节点存到一个一维向量中，把所有节点值存到另一个一维向量中，然后对存节点值的一维向量排序，
在将排好的数组按顺序赋给节点。这种最一般的解法可针对任意个数目的节点错乱的情况
因为节点也是有顺序的！不能直接把vals排序！
*/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> vals;
        vector<TreeNode*> nodeList;
        inorder(root, vals, nodeList);
        sort(vals.begin(), vals.end());
        for(int i = 0; i < vals.size(); i++)
        {
            nodeList[i]->val = vals[i];
        }
        
        
    }
    void inorder(TreeNode* node, vector<int> &vals, vector<TreeNode*> &nodeList){
        if(node->left) inorder(node->left, vals, nodeList);
        vals.push_back(node->val);
        nodeList.push_back(node);
        if(node->right) inorder(node->right, vals, nodeList);
    }
};
//这道题的真正符合要求的解法应该用的Morris遍历，这是一种非递归且不使用栈，空间复杂度为O(1)的遍历方法
