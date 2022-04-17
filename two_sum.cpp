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
