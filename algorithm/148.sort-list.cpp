/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (33.28%)
 * Total Accepted:    164.1K
 * Total Submissions: 493.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(h1 == NULL)
            return h2;

        if(h2 == NULL)
            return h1;

        ListNode *result = new ListNode(0), *cur = result;
        ListNode *cur1 = h1, *cur2 = h2;

        while(cur1 != NULL && cur2 != NULL){
            if(cur1->val < cur2->val){
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
            }
            else{
                cur->next = cur2;
                cur = cur->next;
                cur2 = cur2->next;
            }
        }

        if(cur1 == NULL){
            cur->next = cur2;
        }
        if(cur2 == NULL){
            cur->next = cur1;
        }

        return result->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *h1 = head, *h2 = head, *pre = head;
        while(h2 != NULL && h2->next != NULL){
            pre = h1;
            h1 = h1->next;
            h2 = h2->next->next;
        }
        pre->next = NULL;
        ListNode *temp1 = sortList(head);
        ListNode *temp2 = sortList(h1);

        return merge(temp1, temp2);
    }
};
