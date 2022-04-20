class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        double nums1Med, nums1Index, nums2Index, median, shift;
        
        //Get median and index of median for nums1
        nums1Index = (nums1Size/2)-0.5;
        if(nums1Index-floor(nums1Index) == 0)
            nums1Med = nums1[nums1Index];
        else nums1Med = (nums1[ceil(nums1Index)]+nums1[floor(nums1Index)])/2;
        
        //Find highest index in nums2 with value less than median of nums1
        nums2Index = nums2Size-1;
        while(nums2Index>=0 && nums2[nums2Index]>=nums1Med)
            nums2Index--;
        
        //Set current median, shift, and valid indices
        double nextElement;
        median = nums1Med;
        shift = (nums2Size - 2*(nums2Index+1))/2;
        if(nums2Index<0) nums2Index = 0;
        if(nums1Index-floor(nums1Index) != 0)
        {
            if(shift<0) 
            {
                nums1Index = floor(nums1Index);
                shift -= 0.5;
            }
            else if(shift>0)
            {
                nums1Index = ceil(nums1Index);
                shift += 0.5;
            }
        }
        
        //Find median in hypothetical merged array
        while(shift<=-1 || shift>=1)
        {
            if(shift <= -1)
            {
                if(nums1[nums1Index] > nums2[nums2Index])
                {
                    median = nums1[nums1Index];
                    --nums1Index;
                }
                else
                {
                    median = nums2[nums2Index];
                    --nums2Index;
                }
                ++shift;
            }
            else if(shift >= 1)
            {
                if(nums1[nums1Index] < nums2[nums2Index])
                {
                    median = nums1[nums1Index];
                    ++nums1Index;
                }
                else
                {
                    median = nums2[nums2Index];
                    ++nums2Index;
                }
                --shift;
            }
        }
        
        //If median is between two numbers, calculate median
        if(shift == -0.5)
        {
            bool nums1OOB = false;
            bool nums2OOB = false;
            
            //Bounds correcting
            if(nums1Index >= nums1Size)
            {
                nums1Index = nums1Size-1;
                nums1OOB = true;
            }
            else if(nums1Index < 0)
            {
                nums1Index = 0;
                nums1OOB = true;
            }
            if(nums2Index >= nums2Size)
            {
                nums2Index = nums2Size-1;
                nums2OOB = true;
            }
            else if(nums2Index < 0)
            {
                nums2Index = 0;
                nums2OOB = true;
            }
            
            if(!nums1OOB && nums1[nums1Index] > nums2[nums2Index])
            {
                median = (median+nums1[nums1Index])/2;
            }
            //the first condition here might be unnecessary.
            else if(nums1OOB && nums1[nums1Index] > nums2[nums2Index])
            {
                median = (median+nums2[nums2Index])/2;
            }
            else if(!nums2OOB)
            {
                median = (median+nums2[nums2Index])/2;
            }
            else
            {
                median = (median+nums1[nums1Index])/2;
            }
        }
        else if(shift == 0.5)
        {
            bool nums1OOB = false;
            bool nums2OOB = false;
            
            //Bounds correcting
            if(nums1Index >= nums1Size)
            {
                nums1Index = nums1Size-1;
                nums1OOB = true;
            }
            else if(nums1Index < 0)
            {
                nums1Index = 0;
                nums1OOB = true;
            }
            if(nums2Index >= nums2Size)
            {
                nums2Index = nums2Size-1;
                nums2OOB = true;
            }
            else if(nums2Index < 0)
            {
                nums2Index = 0;
                nums2OOB = true;
            }
            
            if(!nums1OOB && nums1[nums1Index] < nums2[nums2Index])
            {
                median = (median+nums1[nums1Index])/2;
            }
            //the first condition here might be unnecessary.
            else if(nums1OOB && nums1[nums1Index] < nums2[nums2Index])
            {
                median = (median+nums2[nums2Index])/2;
            }
            else if(!nums2OOB)
            {
                median = (median+nums2[nums2Index])/2;
            }
            else
            {
                median = (median+nums1[nums1Index])/2;
            }
        }
        
        return median;
    }
};
