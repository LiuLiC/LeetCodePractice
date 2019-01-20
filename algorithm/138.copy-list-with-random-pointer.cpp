/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.64%)
 * Total Accepted:    210.6K
 * Total Submissions: 821.4K
 * Testcase Example:  '{}'
 *
 * 
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * 
 * 
 * Return a deep copy of the list.
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return head;

        RandomListNode* cur = head;
        while(cur != NULL){
            RandomListNode* temp = cur->next;
            RandomListNode* deplicate_node = new RandomListNode(cur->label);
            cur->next = deplicate_node;
            deplicate_node->next = temp;
            deplicate_node->random = cur->random;
            cur = cur->next->next;
        }

        cur = head->next;
        while(cur != NULL){
            if(cur->random != NULL)
                cur->random = cur->random->next;

            if(cur->next != NULL)
                cur = cur->next->next;
            else
                break;
        }

        cur = head;
        RandomListNode* result = head->next;

        while(cur != NULL){
            RandomListNode* temp = cur->next; 
            if(cur->next != NULL)
                cur->next = cur->next->next;
            cur = temp;
        }

        return result;
    }
};
