/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.08%)
 * Total Accepted:    226K
 * Total Submissions: 643K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    ListNode* reverse(ListNode* head){
        ListNode *pre = head, *node = head, *cur = head->next;
        while(cur != NULL){
            pre->next = cur->next;
            cur->next = node;
            node = cur;
            cur = pre->next;
        }

        return node;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;

        ListNode *slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast != NULL){
            slow = slow->next;
        }

        ListNode *p = reverse(slow), *cur = head;
        while(p != NULL && cur != NULL){
            if(p->val != cur->val)
                return false;
            
            p = p->next;
            cur = cur->next;
        }

        return true;
    }
};
