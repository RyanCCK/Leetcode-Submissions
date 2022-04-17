/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

*****************************************************************************************************************************

Runtime: 316 ms, faster than 36.84% of C++ online submissions for Two Sum.
Memory Usage: 10.2 MB, less than 66.64% of C++ online submissions for Two Sum.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i1, i2, size;
        i1 = 0;
        i2 = 1;
        size = nums.size();
        
        while(nums[i1]+nums[i2] != target)
        {
            while(i2<size && nums[i1]+nums[i2] != target)
            {
                ++i2;
            }
            if(i2 == size)
            {
                ++i1;
                i2 = i1+1;
            }
        }
        
        vector<int> indices {i1, i2};
        return indices;
    }
};
