/*
POSSIBLE ISSUE:

Incrementing nums1index and nums2index before shifting up the hypothetical merge array
MAY cause skipping of elements that should not be skipped.  Look into this further.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double nums1size = nums1.size();
        double nums2size = nums2.size();
        double median, nums1median, nums2median, nums1index, nums2index, nums1middle, nums2middle;
        int shift;
        
        //If either array is empty (It is specified that both cannot be simultaneously empty)
        if(nums1.empty() || nums2.empty())
        {
            if(nums1.empty())
            {
                if(fmod(nums2size/2, 1) != 0)
                    median = nums2[floor((nums2size-1)/2.0)];
                else median = (nums2[floor((nums2size-1)/2.0)] + nums2[ceil((nums2size-1)/2.0)])/2.0;
            }
            else if(nums2.empty())
            {
                if(fmod(nums1size/2, 1) != 0)
                    median = nums1[floor((nums1size-1)/2.0)];
                else median = (nums1[floor((nums1size-1)/2.0)] + nums1[ceil((nums1size-1)/2.0)])/2.0;
            }
        }
        
        //If both arrays have only a single element
        else if(nums1size == 1 && nums2size == 1)
            median = (nums1[0]+nums2[0])/2.0;
        
        //If the size of one array is odd and the size of the other is even
        else if((fmod(nums1size/2.0, 1)!=0 && fmod(nums2size/2.0, 1)==0) || (fmod(nums1size/2.0, 1)==0 && fmod(nums2size/2.0, 1)!=0))
        {
            //If nums1 is odd and nums2 is even
            if(fmod(nums1size/2.0, 1)!=0 && fmod(nums2size/2.0, 1)==0)
            {
                //Set median = median of nums1
                nums1index = floor(nums1size/2.0);
                median = nums1[nums1index];
                //Find index in nums2 that is less than median
                nums2index = nums2size-1;
                while(nums2Index >= 0 && nums2[nums2index] >= median)
                    nums2Index--;
                nums2middle = (nums2size/2.0)-1;
                //If nums2index is below nums2middle, shift upward to find median of merged array
                if(nums2index<nums2middle)
                {
                    shift = nums2middle-nums2index;
                    nums1index++;
                    nums2index++;
                    for(int i=0; i<shift; ++i)
                    {
                        if(nums1index<nums1size && nums2index<nums2size)
                            median = (nums1[nums1index] < nums2[nums2index]) ? nums1[nums1index++] : nums2[nums2index++];
                        else if(nums1index<nums1size && nums2index>=nums2size)
                            median = nums1[nums1index++];
                        else if(nums1index>=nums1size && nums2index<nums2size)
                            median = nums2[nums2index++];
                    }
                }
                //If nums2index is above nums2middle, shift downward to find median of merged array
                else if(nums2index>nums2middle)
                {
                    shift = nums2index-nums2middle;
                    nums1index--;
                    for(int i=0; i<shift; ++i)
                    {
                        if(nums1index>0 && nums2index>0)
                            median = (nums1[nums1index]>nums2[nums2index]) ? nums1[nums1index--] : nums2[nums2index--];
                        else if(nums1index>0 && nums2index<=0)
                            median = nums1[nums1index--];
                        else if(nums1index<=0 && nums2index>0)
                            median = nums2[nums2index--];
                    }
                }
            }
            //If nums2 is odd and nums1 is even
            else if(fmod(nums1size/2.0, 1)==0 && fmod(nums2size/2.0, 1)!=0)
            {
                //Set median = median of nums2
                nums2index = floor(nums2size/2.0);
                median = nums2[nums2index];
                //Find index in nums1 that is less than median
                nums1index = nums1size-1;
                while(nums1Index >= 0 && nums1[nums1index] >= median)
                    nums1Index--;
                nums1middle = (nums1size/2.0)-1;
                //If nums1index is below nums1middle, shift upward to find median of merged array
                if(nums1index<nums1middle)
                {
                    shift = nums1middle-nums1index;
                    nums2index++;
                    nums1index++;
                    for(int i=0; i<shift; ++i)
                    {
                        if(nums2index<nums2size && nums1index<nums1size)
                            median = (nums2[nums2index] < nums1[nums1index]) ? nums2[nums2index++] : nums1[nums1index++];
                        else if(nums2index<nums2size && nums1index>=nums1size)
                            median = nums2[nums2index++];
                        else if(nums2index>=nums2size && nums1index<nums1size)
                            median = nums1[nums1index++];
                    }
                }
                //If nums1index is above nums1middle, shift downward to find median of merged array
                else if(nums1index>nums1middle)
                {
                    shift = nums1index-nums1middle;
                    nums2index--;
                    for(int i=0; i<shift; ++i)
                    {
                        if(nums2index>0 && nums1index>0)
                            median = (nums2[nums2index]>nums1[nums1index]) ? nums2[nums2index--] : nums1[nums1index--];
                        else if(nums2index>0 && nums1index<=0)
                            median = nums2[nums2index--];
                        else if(nums2index<=0 && nums1index>0)
                            median = nums1[nums1index--];
                    }
                }
            }
        }
        
        //If the size of each array is odd
        else if(fmod(nums1size/2.0, 1)!=0 && fmod(nums2size/2.0, 1)!=0)
        {
            nums1middle = floor(nums1size/2.0);
            nums2middle = floor(nums2size/2.0);
            //Set median = median of nums1
            median = nums1[nums1middle];
            nums1index = nums1middle;
            //Set nums2 index to greatest index of an element less than the median
            nums2index = nums2size-1;
            while(nums2Index >= 0 && nums2[nums2index] >= median)
                nums2Index--;
            if(nums2index<nums2middle)
            {
                shift = nums2middle-nums2index;
                //for-loop to shift requisite number of times up through the hypothetical merge array
                //After loop terminates, one final update to median must be performed,
                //  since it is not any particular element - but the average of the middle two. 
            }
        }
        
        //If the size of each array is even
        /*
        else
        {
            
        }
        */
        
        return median;
    }
};
