/*

LEETCODE PROBLEM 27 | Remove Element | 5/18/2022

**************************************************************************************************

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead 
have the result be placed in the first part of the array nums. More formally, if there are k elements 
after removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. 
You must do this by modifying the input array in-place with O(1) extra memory.


Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

**************************************************************************************************

Runtime: 4 ms, faster than 41.73% of C++ online submissions for Remove Element.
Memory Usage: 8.8 MB, less than 36.74% of C++ online submissions for Remove Element.

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //Base cases
        if(nums.size() == 0 || val > 50) return nums.size();
        
        int numVals = 0;  //number of occurrences of val 
        
        for(int back = 0, front = 0; front < nums.size(); ++front)
        {
            while(front < nums.size() && nums[front] == val)
            {
                ++numVals; ++front;
            }
            if(back < nums.size() && front < nums.size())
                nums[back++] = nums[front];
        }
        
        return nums.size() - numVals;
    }
};
