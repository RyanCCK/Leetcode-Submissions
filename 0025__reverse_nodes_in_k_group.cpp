/*

LEETCODE PROBLEM 25 | Reverse Nodes in k-Group | 5/16/2022

**************************************************************************************************

Given the head of a linked list, reverse the nodes of the list k at a time, 
and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

**************************************************************************************************

Runtime: 25 ms, faster than 30.16% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 11.4 MB, less than 73.01% of C++ online submissions for Reverse Nodes in k-Group.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Base cases (0-element list or no reversal)
        if(head->next == nullptr || k == 1) return head;
        
        //Variable declarations
        ListNode * first = head;                //Tracks left node used in each swap
        ListNode * second = head;               //Tracks right node used in each swap   
                                                //  (initialized to be correct value AFTER node advancement in main loop)
        ListNode * nextNode = second->next;     //Tracks node past right node   
                                                //  (initialized to be correct value AFTER node advancement in main loop)
        ListNode * prevTail = nullptr;          //Tracks final node in previous sub-list
        ListNode * subHead = head;              //Tracks head node of current sub-list
        int size = 0;                           //Size of whole linked list
        
        //Determine size of linked list
        while(first != nullptr)
        {
            ++size;
            first = first->next;
        }
        
        //Another base case (no nodes need to be reversed if size < k)
        if(size < k) return head;
        
        //Loop through every complete sublist
        for(int i=1; i<=k*(size/k); ++i)
        {
            //Advance nodes
            first = second;
            second = nextNode;
            if(nextNode) nextNode = nextNode->next;
            
            //If at end of sub-list
            if(i%k == 0)
            {
                if(i==k) head = first;  //Set head of entire list to final node in first sub-list
                subHead->next = second; 
                if(prevTail) prevTail->next = first;    
                prevTail = subHead;
                subHead = second;
            }
            //Normal case
            else second->next = first;
        }
        
        return head;
    }
};
