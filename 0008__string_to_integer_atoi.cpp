/*

LEETCODE PROBLEM 8 | String to Integer (atoi) | 5/3/2022

*****************************************************************************************************************************

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. 
   This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3. Read in next the characters until the next non-digit character or the end of the input is reached. 
   The rest of the string is ignored.
4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. 
   Change the sign as necessary (from step 2).
5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it 
  remains in the range. Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 
  should be clamped to 2^31 - 1.
6. Return the integer as the final result.

Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.


Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

*****************************************************************************************************************************

Runtime: 8 ms, faster than 25.17% of C++ online submissions for String to Integer (atoi).
Memory Usage: 7.2 MB, less than 12.91% of C++ online submissions for String to Integer (atoi).

*/

class Solution {
public:
    int myAtoi(string s) 
    {
        stringstream str(s);
        signed char ch, sign = 1;
        long result = 0;
        bool valid = true;
    
        //Process first (possible sign) character
        str >> ch;
        if(ch == '-' || ch == '+')
        {
            if(ch == '-') sign = -1; 
        }
        else if(ch-'0' >= 0 && ch-'0' <= 9)
            result = result * 10 + (ch-'0');
        else valid = false;
        
        //Stop skipping white space 
        str >> noskipws;
    
        //Process remainder of int values or until overflow
        while(str >> ch && valid)
        {
            //If character read is an integer
            if(ch-'0' >= 0 && ch-'0' <= 9)
            {
                result = result * 10 + (ch-'0');
                //If the current value of result is now out of bounds
                if(result*sign < INT_MIN || result*sign > INT_MAX)
                {
                    if(sign == -1) result = INT_MIN;
                    else result = INT_MAX;
                    valid = false;
                }
            }
            //If not an integer, exit the loop
            else
            {
                result *= sign;
                valid = false;
            }
        }
        if(valid) result *= sign;
    
        return (int) result; 
    }
};
