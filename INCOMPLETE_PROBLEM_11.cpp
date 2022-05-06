class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> maxPair {0, 1};
        long maxArea = (height[0] < height[1]) ? height[0] * 1 : height[1] * 1;
        int maxLength = 1;
        //The greatest value for the back index at which, within the current inner loop, 
        // it is not possible that the area could be greater than maxArea
        int terminalIndex = 1;
        //Tracks values updated each iteration of inner loop
        int length;
        long currArea;
        
        //Outer loop to set front index 
        for(int i=0; i<height.size(); ++i)
        {
            //Set terminal index for current front index
            terminalIndex = ((maxArea/height[i])-1)+i;
            //Inner loop to set back index
            for(int j=height.size(); j>i; --j)
            {
                //Exit loop if past terminal index
                if(j <= terminalIndex) break;
                //Update inner loop values
                length = abs(i-j)+1;
                currArea = (height[i] < height[j]) ? height[i] * length : height[j] * length;
                //Update terminal index (if possible) based on current area
                if(((currArea/height[i])-1)+i > terminalIndex) 
                    terminalIndex = ((currArea/height[i])-1)+i;
                //If current area is greater than maxArea, update maxArea
                if(currArea > maxArea)
                {
                    maxArea = currArea;
                    maxPair[0] = i;
                    maxPair[1] = j;
                    maxLength = length;
                }
                //Exit loop if heights at both indices are equivalent
                if(height[i] == height[j]) break;
            }
        }
        
        return maxArea;
    }
};
