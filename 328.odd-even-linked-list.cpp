/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;

        ListNode *h1= head, *h2 = head->next;
        ListNode *cur1 = h1, *cur2 = h2;
        while(cur2->next != NULL){
            cur1->next = cur2->next;
            cur1 = cur1->next;
            if(cur1->next != NULL){
                cur2->next = cur1->next;
                cur2 = cur2->next;
            }
            else
                break;
        }
        cur1->next = h2;
        cur2->next = NULL;

        return h1;
    }
};

