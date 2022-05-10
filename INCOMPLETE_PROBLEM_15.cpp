class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Vector to hold all valid triplets
        vector<vector<int>> triplets {};
        
        //Simple guard cases
        if(nums.size() < 3) return triplets;
        else if(nums.size() == 3 && nums[0] + nums[1] + nums[2] != 0) 
            return triplets;
        else if(nums.size() == 3 && nums[0] + nums[1] + nums[2] == 0)
        {
            triplets.push_back({nums[0], nums[1], nums[2]});
            return triplets;
        }
        
        //Map to increase speed of element lookup. Value is index, key is value in nums at that index.
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); ++i)
            umap[nums[i]] = i;
        
        //Temporary vector to hold a triplet
        vector<int> temp;
        
        //Fix first element, then fix second element, then use map to lookup if valid third element exists.
        //  If so, ensure that it's not a duplicate of either of the first two.
        int diff;
        for(int index1=0; index1<nums.size()-1; ++index1)
        {
            for(int index2=index1+1; index2<nums.size(); ++index2)
            {
                diff = -1 * (nums[index1] + nums[index2]);
                //If third value is found in the map
                if(umap.count(diff) != 0)
                {
                    //If index of third value is different from index1 and index2
                    if(umap.find(diff) -> second != index1 && umap.find(diff) -> second != index2)
                    {
                        temp = {nums[index1], nums[index2], diff};
                        sort(temp.begin(), temp.end());
                        //Check that this is not a duplicate triplet
                        bool duplicate = false;
                        for(int i=0; i<triplets.size() && !duplicate; ++i)
                        {
                            if(temp == triplets[i]) duplicate = true;
                        }
                        if(!duplicate) triplets.push_back(temp);
                    }
                }
            }
        }
        return triplets;
    }
};
