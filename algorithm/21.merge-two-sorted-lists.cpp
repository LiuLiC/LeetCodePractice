/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (44.22%)
 * Total Accepted:    450.4K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *cur = head;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val > l2->val){
                ListNode *temp = new ListNode(l2->val);
                cur->next = temp;
                cur = temp;
                l2 = l2->next;
            }
            else{
                ListNode *temp = new ListNode(l1->val);
                cur->next = temp;
                cur = temp;
                l1 = l1->next;
            }
        }

        while(l2 != nullptr){
            ListNode *temp = new ListNode(l2->val);
            cur->next = temp;
            cur = temp;
            l2 = l2->next;
        }

        while(l1 != nullptr){
            ListNode *temp = new ListNode(l1->val);
            cur->next = temp;
            cur = temp;
            l1 = l1->next;
        }

        return head->next;
    }
};
