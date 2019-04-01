/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (36.34%)
 * Total Accepted:    7.8K
 * Total Submissions: 21.5K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 * 
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
class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size(), idx = 0;
        vector<vector<char> > visited(m, vector<char>(n, false));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(searchDFS(board, word, i, j, visited, idx)) return true;
            }
        }
        return false;
    }
    //DFS要回溯
    bool searchDFS(vector<vector<char> >& board, string word, int i, int j, vector<vector<char> > &visited, int idx){
        if(idx == word.size()) return true;   //idx走到这一步，前面n个字母全都成功找到了
        int m = board.size(), n = board[0].size();
        //此路搜索失败的情况
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;

        visited[i][j] = true;  //成功找到一个字母，添加访问
        //搜寻四个方向
        bool res = (searchDFS(board, word, i+1, j, visited, idx+1)
        || searchDFS(board, word, i-1, j, visited, idx+1)
        || searchDFS(board, word, i, j+1, visited, idx+1)
        || searchDFS(board, word, i, j-1, visited, idx+1));
        
        visited[i][j] = false;  //探测完毕，取消该条路的标记，回溯

        return res;
    }
};

