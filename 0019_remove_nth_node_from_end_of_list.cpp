/*

LEETCODE PROBLEM 19 | Remove Nth Node From End of List | 5/11/2022

**************************************************************************************************

Given the head of a linked list, remove the nth node from the end of the list and return its head.


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

**************************************************************************************************

Runtime: 7 ms, faster than 49.32% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.6 MB, less than 75.97% of C++ online submissions for Remove Nth Node From End of List.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* removalNode = head;
        ListNode* endNode = head;
        
        //Base case
        if(head->next == nullptr) return nullptr;
        
        //Move endNode forward n-1 nodes in front of removalNode
        for(int i=1; i<n; ++i)
        {
            endNode = endNode->next;
        }
        
        ListNode* prev = nullptr;
        //Increment both nodes until endNode->next == nullptr, then remove removalNode
        while(endNode->next != nullptr)
        {
            endNode = endNode->next;
            prev = removalNode;
            removalNode = removalNode->next;
        }
        
        if(prev == nullptr) head = head->next;
        else prev->next = removalNode->next;
        removalNode->next = nullptr;
        
        return head;
    }
};
