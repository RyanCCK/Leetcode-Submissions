/*

LEETCODE PROBLEM 26 | Remove Duplicates from Sorted Array | 5/18/2022

**************************************************************************************************

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place 
such that each unique element appears only once. The relative order of the elements should be 
kept the same.

Since it is impossible to change the length of the array in some languages, you must instead 
have the result be placed in the first part of the array nums. More formally, if there are k elements 
after removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array 
in-place with O(1) extra memory.


Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

**************************************************************************************************

Runtime: 15 ms, faster than 63.35% of C++ online submissions for Remove Duplicates from Sorted Array.
Memory Usage: 18.3 MB, less than 75.10% of C++ online submissions for Remove Duplicates from Sorted Array.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Base case
        if(nums.size() == 1) return 1;
        
        //Variable declarations
        int fi = 1;  //Forward index
        int k = 0;  //Return value (num unique elements)
        
        while(fi < nums.size())
        {
            while(fi < nums.size() && nums[k] == nums[fi]) ++fi;
            if(k+1 < nums.size() && fi < nums.size()) nums[k+1] = nums[fi];
            ++k;
        }
        
        return k;
    }
};
