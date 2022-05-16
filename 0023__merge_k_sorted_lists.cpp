/*

LEETCODE PROBLEM 23 | Merge k Sorted Lists | 5/15/2022

**************************************************************************************************

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

**************************************************************************************************

Runtime: 891 ms, faster than 6.80% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 13 MB, less than 95.14% of C++ online submissions for Merge k Sorted Lists.

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Guard against base cases
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];;
        
        
        //Declare variables
        bool allEmpty = true;       //Will determine if lists is filled entirely with null pointers
        ListNode * head, * curr;    //Pointers to head of merged list and current node
        int least;                  //Least value between all nodes being compared,
        int leastIndex;             //Least value between all nodes being compared, and index in lists of that node's list
        int numNull = 0;            //Number of null pointers in lists (each indicating end of list)
        
        
        //Find least-valued node in lists 
        for(int i=0; i<lists.size(); ++i)
        {
            if(lists[i] != nullptr)
            {
                if(allEmpty)
                {
                    allEmpty = false;
                    least = lists[i]->val;
                    leastIndex = i;
                }
                else if(lists[i]->val < least)
                {
                    least = lists[i]->val;
                    leastIndex = i;
                }
            }
            else ++numNull;
        }
        
        
        //If all pointers in lists were null, return nullptr
        if(allEmpty) return nullptr;
        
        
        //Set head and curr
        head = curr = lists[leastIndex];
        //Move pointer to least-valued node forward
        lists[leastIndex] = lists[leastIndex]->next;
        //Check if pointer is now null
        if(lists[leastIndex] == nullptr) ++numNull;
        
        
        //Repeat this process until all lists have been merged (every pointer in lists points to null)
        while(numNull < lists.size())
        {
            leastIndex = 0; //Reset leastIndex for each iteration
            //Move leastIndex forward to index of first non-null pointer
            while(lists[leastIndex] == nullptr) ++leastIndex;
            least = lists[leastIndex]->val; //Reset least to value of first non-null node pointer in lists
            
            //Find actual least-valued node and the index of its list in lists
            for(int i=0; i<lists.size(); ++i)
            {
                if(lists[i] != nullptr && lists[i]->val < least)
                {
                    least = lists[i]->val;
                    leastIndex = i;
                }
            }
            
            curr->next = lists[leastIndex];
            lists[leastIndex] = lists[leastIndex]->next; 
            if(lists[leastIndex] == nullptr) ++numNull;
            curr = curr->next;  
        }
        
        
        //Return merged list
        return head;
    }
};
