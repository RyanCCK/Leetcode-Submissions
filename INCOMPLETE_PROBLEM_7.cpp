/*

LEETCODE PROBLEM 7 | Reverse Integer | 5/2/2022

*****************************************************************************************************************************

1029/1032 Test Cases Passed

Fails on:
Input:
-2147483412
Output:
0
Expected:
-2143847412

*/
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
        
        //AD-HOC: Guard against value that cannot be multiplied by -1 (see below)
        if(x == -2147483648) return 0;
        
        //Determine if x is negative, and remove sign
        if(x<0)
        {
            negative = true;
            x *= -1;
        }
        else negative = false;
        
        //Insert each digit of x into result in reverse order
        //  except for 10th digit (needed for bounds checking)
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
                if(negative && result>147483648) outOfBounds = true;
                else if(negative && result==147483648)
                {
                    increment = true;
                    --result;
                }
                else if(!negative && result>147483647) outOfBounds = true;
            }
            else result = result*10+x;
        }
        if(outOfBounds) return 0;
        
        //Reset sign and increment if necessary
        if(negative) result *= -1;
        if(increment) ++result;
        
        return result;
    }
};
