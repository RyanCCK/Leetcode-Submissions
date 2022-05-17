/*

LEETCODE PROBLEM 24 | Swap Nodes in Pairs | 5/16/2022

**************************************************************************************************

Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)


Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

**************************************************************************************************

Runtime: 3 ms, faster than 69.25% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 7.6 MB, less than 6.92% of C++ online submissions for Swap Nodes in Pairs.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode * first, * second, * prior;
        
        //Base cases
        if(head == nullptr) return nullptr;
        else if(head->next == nullptr) return head;
        else if(head->next->next == nullptr)
        {
            head->next->next = head;
            head = head->next;
            head->next->next = nullptr;
            return head;
        }
        
        //Set up initial values (if at least 3 nodes exist)
        first = head;
        second = head->next;
        first->next = second->next;
        second->next = first;
        head = second;
        prior = first;
        
        //Loop through remainder of list, as long as at least 2 nodes remain
        while(prior->next && prior->next->next)
        {
            first = prior->next;
            second = prior->next->next;
            
            prior->next = second;
            first->next = second->next;
            second->next = first;
            
            prior = first;
        }
        
        //Return head
        return head;
    }
};
