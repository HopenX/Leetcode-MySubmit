/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (37.53%)
 * Total Accepted:    12.6K
 * Total Submissions: 33.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *cur = head; int n = 0;
        while (cur){
            ++n;
            cur = cur->next;
        }
        ListNode *fast = head, *slow = head;
        k %= n;
        for (int i = 0; i < k; i++){
            fast = fast->next;
        }
        if(!fast) return head;  //刚好不旋转
        while (fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;      //fast已经到达尾部，指向头部
        fast = slow->next;      //这就是新的头结点
        slow->next = NULL;      //作为尾节点
        return fast;
    }
};
//快慢指针，精髓在于△k，从head走过△k，就是新的头结点所在。△k=n-k
//各种边界一点要考虑好，比如head为空，cur还是cur->next
