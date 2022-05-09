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
        
        //Sort nums in non-descending order
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        
        //Check if all values are negative
        if(sortedNums[sortedNums.size()-1] < 0) return triplets;
        
        //Determine amount of 0s, and the indices of the first and last occurrences. 
        int numZeros = 0, firstZeroIndex = 0, lastZeroIndex;
        while(firstZeroIndex < sortedNums.size() && sortedNums[firstZeroIndex] != 0)
            ++firstZeroIndex;
        if(firstZeroIndex != sortedNums.size())
        {
            lastZeroIndex = firstZeroIndex;
            while(lastZeroIndex < sortedNums.size() && sortedNums[lastZeroIndex] == 0)
            {
                ++numZeros;
                ++lastZeroIndex;
            }
            --lastZeroIndex;    //This always ends up 1 past the actual index of the last 0
        }
        //Based on number of 0s:
        //  If 0 or 1, do nothing.
        //  If 2, remove 1.
        //  If 3 or greater, append {0,0,0} to triplets, then remove all but 1.
        switch(numZeros)
        {
            case 0:
                //Not really firstZeroIndex; we are finding index of first non-negative value. Will be assigned to correct name further below.
				for(int i=0; i<sortedNums.size(); ++i)
				{
					if(sortedNums[i] >= 0) 
					{
						firstZeroIndex = i;
						break;
					}
				}
                break;
            case 1:
                break;
            case 2:
                sortedNums.erase(next(sortedNums.begin(), lastZeroIndex));
                break;
            default:
                triplets.push_back({0,0,0});
                sortedNums.erase(next(sortedNums.begin(), firstZeroIndex+1), next(sortedNums.begin(), lastZeroIndex+1));
        }
        
        //Perform search and populate solution vector.
        // Search is with respect to partition: firstZeroIndex
        vector<int> temp;
        bool dupFound = false;
        //There may be no zeroes. This is a more accurate variable name.
		int firstNonNegativeIndex = firstZeroIndex;
        for(int index1=0; index1<firstNonNegativeIndex; ++index1)
        {
            for(int index2=index1+1; index2<sortedNums.size()-1; ++index2)
            {
                int index3 = (index2<firstNonNegativeIndex) ? 
                    firstNonNegativeIndex : index2 + 1;
                while(index3 < sortedNums.size())
                {
                    //If valid triplet candidate is found, check if it already exists within triplets.
                    //  If not, append it to triplets.
                    if(sortedNums[index1] + sortedNums[index2] + sortedNums[index3] == 0)
                    {
                        temp = {sortedNums[index1], sortedNums[index2], sortedNums[index3]};
                        sort(temp.begin(), temp.end());
                        for(int i=0; i<triplets.size() && !dupFound; ++i)
                        {
                            if(triplets[i] == temp) dupFound = true;
                        }
                        if(!dupFound) triplets.push_back(temp);
                        dupFound = false;
                    }
                    ++index3;
                }
            }
        }
        return triplets;
    }
};
