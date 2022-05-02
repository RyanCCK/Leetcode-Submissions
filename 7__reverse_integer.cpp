/*

LEETCODE PROBLEM 7 | Reverse Integer | 5/2/2022

*****************************************************************************************************************************

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the 
signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

*****************************************************************************************************************************

Runtime: 4 ms, faster than 43.44% of C++ online submissions for Reverse Integer.
Memory Usage: 6 MB, less than 8.67% of C++ online submissions for Reverse Integer.

*/

//Define constants used in bounds checking
//  based off of signed 32-bit integer max/min values
#define SIGNED_32_INT_LOWER_BOUND -2147483648
#define SIGNED_32_INT_UPPER_BOUND 2147483647
#define PARTIAL_UPPER_BOUND 14748364

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        bool negative;
        bool outOfBounds = false;
        //Used in the case that the reversed integer is 2147483648,
        //  and is supposed to be negative
        bool increment = false;
        
        //Check for simplest base case
        if(x>-10 && x<10)
            return x;
        
        //Determine if x is negative, and remove sign
        if(x<0)
        {
            //This value cannot be safely multiplied by -1. Its reversed digits
            //  would be out-of-bounds, so return 0.
            if(x == SIGNED_32_INT_LOWER_BOUND) return 0;
            negative = true;
            x *= -1;
        }
        else negative = false;
        
        //Insert each digit of x into result in reverse order
        //  except for final digit OR 10th digit (needed for bounds checking)
        int size = 1;
        while(size<10 && x>=10)
        {
            result = result*10 + (x%10);
            x /= 10;
            if(result != 0) ++size;
        }
        //Include final digit
        if(size<10) result = result*10+x;
        
        //If there is a 10th digit, use for bounds checking
        else if(size==10)
        {
            if((result/100000000)>2) outOfBounds = true;
            else if((result/100000000)==2)
            {
                if((result%200000000) > PARTIAL_UPPER_BOUND) outOfBounds = true;
                else if((result%200000000) == PARTIAL_UPPER_BOUND)
                {
                    //IF result needs to be negative
                    if(negative)
                    {
                        if(x > 8) outOfBounds = true;
                        //If result can only be represented as negative (positive is out of bounds)
                        else if(x == 8)
                        {
                            increment = true;
                            --x;
                            result = result*10+x;
                        }
                        else result = result*10+x;
                    }
                    //If positive
                    else
                    {
                        if(x > 7) outOfBounds = true;
                        else result = result*10+x;
                    }
                }
                else result = result*10+x;
            }
            else result = result*10+x;
        }
        
        //Reset sign and increment if necessary
        if(negative) result *= -1;
        if(increment) ++result;
        
        //Return 0 if result is larger/smaller than a 32-bit signed integer max/min value
        if(outOfBounds) result=0;
        
        return result;
    }
};
