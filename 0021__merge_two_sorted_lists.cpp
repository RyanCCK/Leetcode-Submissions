/*

LEETCODE PROBLEM 21 | Merge Two Sorted Lists | 5/11/2022

*****************************************************************************************************************************

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*****************************************************************************************************************************

Runtime: 11 ms, faster than 51.57% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 14.7 MB, less than 98.05% of C++ online submissions for Merge Two Sorted Lists.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * p1 = list1;
        ListNode * p2 = list2;
        ListNode * prev, * head;
        
        //Base cases
        if(!list1 && !list2) return nullptr;
        if(!list1) return list2;
        if(!list2) return list1;
        
        //Set head of list and pointer to previous node
        if(p1->val <= p2->val)
        {
            head = prev = p1;
            p1 = p1->next;
        }
        else
        {
            head = prev = p2;
            p2 = p2->next; 
        }
        
        //Merge lists in non-decreasing order
        while(p1 || p2)
        {
            if(p1 && p2)
            {
                if(p1->val <= p2->val)
                {
                    prev->next = p1;
                    prev = p1;
                    p1 = p1->next;
                }
                else
                {
                    prev->next = p2;
                    prev = p2;
                    p2 = p2->next;
                }
                    
            }
            else if(p1)
            {
                prev->next = p1;
                prev = p1;
                p1 = p1->next;
            }
            else if(p2)
            {
                prev->next = p2;
                prev = p2;
                p2 = p2->next;
            }
        }
        return head;
    }
};
