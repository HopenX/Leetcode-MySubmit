/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (56.76%)
 * Total Accepted:    10.5K
 * Total Submissions: 18.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight){
        if(pLeft>pRight || iLeft>iRight) return NULL;
        int i = 0;
        for(i = iLeft; i <= iRight; i++)  //这个地方千万不能int i，一旦写了就生成临时变量、覆盖了原来的i
        {
            if(preorder[pLeft] == inorder[i]) break;
        }
        TreeNode* cur = new TreeNode(preorder[pLeft]);
        cur->left = buildTree(preorder, pLeft+1, pLeft+i-iLeft, inorder, iLeft, i-1);
        cur->right = buildTree(preorder, pLeft+i-iLeft+1, pRight, inorder, i+1, iRight);
        return cur;
    }
};


/*
[5]　　4　　11　　8　　13　　9　　　　　　=>　　　　　　　　　 5
11　　4　　[5]　　13　　8　　9　　　　　　　　　　　　　　　　/　\
重点就在于递归 left 和 right 时的数组边界。i-iLeft 代表走了多少步
由于先序的顺序的第一个肯定是根，并以根节点的位置将中序遍历拆分为左右两个部分
*/
