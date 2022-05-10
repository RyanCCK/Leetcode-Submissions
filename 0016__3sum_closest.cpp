/*

LEETCODE PROBLEM 16 | 3Sum Closest | 5/10/2022

*****************************************************************************************************************************

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is 
closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.


Constraints:

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104

*****************************************************************************************************************************

Runtime: 31 ms, faster than 30.27% of C++ online submissions for 3Sum Closest.
Memory Usage: 10.1 MB, less than 5.51% of C++ online submissions for 3Sum Closest.

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //Check for simplest base case
        if(nums.size() == 3) 
            return nums[0] + nums[1] + nums[2];
        
        //Sort nums in non-decreasing order
        sort(nums.begin(), nums.end());
        
        //Used to hold the closest sum
        int sum = nums[0] + nums[1] + nums[2];
        //Indices used to scan nums above lowest fixed point
        int l, r;
        
        //Fix the first number at each index throughout nums, then scan the remainder of nums
        //  using a two-pointer approach, moving inward and skipping over duplicate values.
        for(int i=0; i<nums.size()-2; ++i)
        {
            l = i+1; r = nums.size()-1;
            
            //If this is true, a closer value to target can no longer be found.
            if(nums[i] > target && abs(target-(nums[i]+nums[i+1]+nums[i+2])) > abs(target-sum))
                break;
            
            while(l<r)
            {
                if(abs(target-(nums[i]+nums[l]+nums[r])) < abs(target-sum))
                    sum = nums[i] + nums[l] + nums[r];
                
                //Update l and r, skip duplicates
                if(nums[i]+nums[l]+nums[r] > target)
				{
					while(r>0 && nums[r-1] == nums[r]) --r;
					--r;
				}
				else if(nums[i]+nums[l]+nums[r] < target)
				{
					while(l<nums.size()-1 && nums[l+1] == nums[l]) ++l;
					++l;
				}
				else return nums[i]+nums[l]+nums[r];
            }
        }
        return sum;
    }
};
