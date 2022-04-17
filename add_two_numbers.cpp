/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*****************************************************************************************

Runtime: 40 ms, faster than 70.74% of C++ online submissions for Add Two Numbers.
Memory Usage: 72.9 MB, less than 12.10% of C++ online submissions for Add Two Numbers.

*/

//Definition for singly-linked list.
/*
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  }; 
*/
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode;
        ListNode * node = head;
        vector<int> v1, v2, sum;
        int size;
        
        //Populate first vector with first linked list elements
        while(l1 != nullptr)
        {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
                                         
        //Populate second vector with second linked list elements
        while(l2!=nullptr)
        {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        
        //Fill in back of smaller vector with 0s until same size as larger vector
        //(Simplifies adding their elements)
        if(v1.size() > v2.size())
        {
            int diff = v1.size() - v2.size();
            for(int i=1; i<=diff; ++i) v2.push_back(0);
        }
        else
        {
            int diff = v2.size() - v1.size();
            for(int i=1; i<=diff; ++i) v1.push_back(0);
        }
        
        //Increase size of both vectors by 1, in case of carry-over on the last digit
        size = v1.size()+1;
        v1.push_back(0);
        v2.push_back(0);
        
        //Populate sum vector with sum of digits at each index in previous two vectors
        for(int i=0; i<size; ++i)
        {
            sum.push_back(v1[i]+v2[i]);
            if(sum[i]>9)
            {
                sum[i] = sum[i]-10;
                v1[i+1] += 1;
            }
        }
        
        //In case of no carry-over on last digit
        if(sum[size-1] == 0) sum.pop_back();
        
        //Create linked list containing sum
        for(int i=0; i<sum.size(); ++i)
        {
            node->val = sum[i];
            if(i!=sum.size()-1)
            {
                node->next = new ListNode;
                node = node->next;
            }
        }
        
        return head;
    }
};
