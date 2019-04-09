/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (43.23%)
 * Total Accepted:    3.3K
 * Total Submissions: 7.5K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给出一个完全二叉树，求出该树的节点个数。
 * 
 * 说明：
 * 
 * 
 * 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第
 * h 层，则该层包含 1~ 2^h 个节点。
 * 
 * 示例:
 * 
 * 输入: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * 输出: 6
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hLeft = 0, hRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while(pLeft){  //深层遍历or计算高度 常用，不断左赋值/右赋值
            hLeft++;
            pLeft = pLeft->left;
        }
        while(pRight){
            hRight++;
            pRight = pRight->right;
        }
        if(hLeft == hRight) return pow(2, hLeft)-1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
/*
分别找出以当前节点为根节点的左子树和右子树的高度并对比，如果相等，则说明是满二叉树，直接返回节点个数，
如果不相等，则节点个数为左子树的节点个数加上右子树的节点个数再加1(根节点)，其中左右子树节点个数的计算可以使用递归来计算
*/
