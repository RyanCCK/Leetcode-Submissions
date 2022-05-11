/*

LEETCODE PROBLEM 18 | 4Sum | 5/11/2022

**************************************************************************************************

Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

**************************************************************************************************

Runtime: 607 ms, faster than 10.97% of C++ online submissions for 4Sum.
Memory Usage: 13 MB, less than 90.49% of C++ online submissions for 4Sum.

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        
        //Used to avoid int overflow
        long sum = 0;
        if(nums.size() <= 4)
            for(long x : nums) sum += x;
        
        //Simplest base cases
        if(nums.size() < 4 || (nums.size() == 4 && sum != target)) 
            return {};
        else if(nums.size() == 4 && (nums.size() == 4 && sum == target)) 
            return{{nums[0], nums[1], nums[2], nums[3]}};
        else if(sum > INT_MAX) return {};
        
        //Sort nums
        sort(nums.begin(), nums.end());
        
        int l, r;
        vector<int> temp;
        
        for(int i=0; i<nums.size()-3; ++i)
        {
            if(nums[i] > target && target > 0) break;
            for(int j=i+1; j<nums.size()-2; ++j)
            {
                if(nums[i]+nums[j] > target && target > 0) break;
                
                //Set left and right indices
                l = j+1; r = nums.size()-1;
                
                //Find all unique quadruplets given 2 fixed initial points i and j
                while(l<r)
                {   
                    temp = {nums[i], nums[j], nums[l], nums[r]};
                    
                    //To avoid overflow:
                    sum = nums[i]+nums[j];
                    sum += nums[l]+nums[r];
                    
                    //Check if quadruplet is found, and decrement/increment r/l
                    if(sum > target) --r;
                    else if(sum < target) ++l;
                    else
                    {
                        bool found = false;
                        for(int i=0; i<quadruplets.size(); ++i)
                        {
                            if(temp == quadruplets[i])
                                found = true;
                        }
                        if(!found) quadruplets.push_back(temp);
                        ++l; --r;
                    }
                }
            }
        }
        return quadruplets;
    }
};
