/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.97%)
 * Total Accepted:    92K
 * Total Submissions: 279K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 */
/**
 * Definition for singly-linked list.
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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
//  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lCon = new ListNode(0), *p=lCon;
        int buy = 0;
        int x,y;  //存储l1和l2临时的值
        while(l1||l2){
            x = l1 ? l1->val : 0;
            y = l2 ? l2->val : 0;

            p->val = (x+y+buy) % 10;
            buy = (x+y+buy) > 9;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;    //本来是NULL的话，就继续NULL

            //判断是否还需要下一位，下一位有计算的话会更新，没有计算就默认0或1
            p->next = ((l1||l2) || (buy!=0)) ? new ListNode(buy) : NULL;
            p ? p=p->next : 0;    //很精髓的写法，代替了短if语句，0什么都不干
        }

        return lCon;
    }
};

