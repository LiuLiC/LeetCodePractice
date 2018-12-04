/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.64%)
 * Total Accepted:    318.2K
 * Total Submissions: 946.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
            
        ListNode *slow = head, *fast = head;
        ListNode *prev_head = new ListNode(0), *prev = prev_head;
        prev_head->next = head;

        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
            prev = prev->next;
        }

        prev->next = slow->next;

        return prev_head->next;
    }
};