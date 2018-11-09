/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.42%)
 * Total Accepted:    640.5K
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        bool plus = false;

        while(l1 != nullptr || l2 != nullptr || plus){
            int digit1 = (l1 != nullptr ? l1->val : 0);
            int digit2 = (l2 != nullptr ? l2->val : 0);
            int digit_add = digit1 + digit2;

            if(plus){
                digit_add ++;
                plus = false;
            }

            if(digit_add >= 10){
                plus = true;
                digit_add -= 10;
            }

            cur->next = new ListNode(digit_add);
            cur = cur->next;

            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
        }

        return head->next;
    }
};
