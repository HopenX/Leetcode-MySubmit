/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (52.15%)
 * Total Accepted:    4.2K
 * Total Submissions: 8.1K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return *generateDFS(1, n);
    }
    vector<TreeNode*> *generateDFS(int start, int end){
        vector<TreeNode*> *subTree = new vector<TreeNode*>();       //指针才有的动态分配内存
        if(start > end) subTree->push_back(NULL);
        else for(int i = start; i <= end; i++){   //所有i轮流做顶部
            vector<TreeNode*> *leftSub = generateDFS(start, i-1);   //递归后，假定当前i左右两子树的所有情况以及生成好了
            vector<TreeNode*> *rightSub = generateDFS(i+1, end);
            for(int j = 0; j < leftSub->size(); j++){               //双层循环，把当前i对应的左右两子树的所有情况遍历
                for(int k = 0; k < rightSub->size(); k++){
                    TreeNode* node = new TreeNode(i);   //每一新生成一个i，对应一种新的情况
                    node->left = (*leftSub)[j];
                    node->right = (*rightSub)[k];
                    subTree->push_back(node);   //当前i的一种情况
                }
            }
        }
        return subTree;
    }
};
