/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (31.42%)
 * Total Accepted:    303.1K
 * Total Submissions: 962.5K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0), *cur = head;
        int NULL_number = 0;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] == NULL)
                NULL_number ++;
        }

        while(NULL_number != lists.size()) {
            int min_val = INT_MAX, min_index = 0;
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] != NULL && lists[i]->val < min_val){
                    min_index = i;
                    min_val = lists[i]->val;
                }
            }

            lists[min_index] = lists[min_index]->next;
            if(lists[min_index] == NULL)
                NULL_number ++;

            ListNode *temp = new ListNode(min_val);
            cur->next = temp;
            cur = temp;
        }

        return head->next;
    }
};
