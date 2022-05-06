/*

LEETCODE PROBLEM 9 | Palindrome Number | 5/4/2022

*****************************************************************************************************************************

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.

*****************************************************************************************************************************

Runtime: 8 ms, faster than 91.24% of C++ online submissions for Palindrome Number.
Memory Usage: 5.9 MB, less than 75.79% of C++ online submissions for Palindrome Number.

*/

class Solution {
public:
    bool isPalindrome(int x) {
        
        //Initialize palindrome to true if 0 or false otherwise
        bool palindrome = !x;
        
        //Guard against negative value and 0 value
        if(x <= 0) return palindrome;
        
        //Otherwise, reverse the integer
        long reversed = 0, tempX = x;
        while(tempX > 0)
        {
            reversed = reversed * 10 + (tempX % 10);
            tempX /= 10;
        }
        
        //Check if reversed integer equals original integer
        palindrome = (reversed == x);
        
        return palindrome;
    }
};
