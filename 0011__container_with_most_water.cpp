/*

LEETCODE PROBLEM 11 | Container With Most Water | 5/6/2022

*****************************************************************************************************************************

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints 
of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.


Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*****************************************************************************************************************************

Runtime: 1506 ms, faster than 5.01% of C++ online submissions for Container With Most Water.
Memory Usage: 59 MB, less than 39.29% of C++ online submissions for Container With Most Water.

*/

//Maximum possible size for an element of height[]
#define MAX_HEIGHT 100000

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
            //Exit loop if an area greater than maxArea can no longer be found
            if(((height.size()-i-1)*MAX_HEIGHT) < maxArea) break;
            //Set terminal index for current front index
            terminalIndex = (height[i] != 0) ? ((maxArea/height[i])-1)+i : i+1;
            //Inner loop to set back index
            for(int j=height.size()-1; j>i; --j)
            {
                //Exit loop if past terminal index
                if(j <= terminalIndex) break;
                //Update inner loop values
                length = abs(i-j);
                currArea = (height[i] < height[j]) ? height[i] * length : height[j] * length;
                //Update terminal index (if possible) based on current area
                if(height[i] != 0 && ((currArea/height[i])-1)+i > terminalIndex) 
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

/*

Faster solution would be to start with two pointers, one at each end of height.
Then move either pointer inward, moving whichever one points to the lesser value.
(If both heights are equal at a given step then both pointers can be moved)
Compute area at each step, and update the current maxArea along the way.

This is guaranteed to find the maximum area in O(N) time.

*/
