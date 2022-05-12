/*

LEETCODE PROBLEM 5 | Longest Palindromic Substring | 4/26/2022

*****************************************************************************************************************************

Given a string s, return the longest palindromic substring in s.


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

*****************************************************************************************************************************

Runtime: 354 ms, faster than 32.10% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 7.3 MB, less than 70.59% of C++ online submissions for Longest Palindromic Substring.

*/

class Solution {
public:
    string longestPalindrome(string s) {
        string palindrome;
        
        //If s has only 1 character
        if(s.length() == 1) palindrome = s;
        
        //If s has only 2 characters
        else if(s.length() == 2)
        {
            if(s[0] == s[1]) palindrome = s;
            else palindrome = s[0];
        }
        
        //If s has 3 or more characters
        else
        {
            bool found = false;
            bool equal = true;
            int gap = 0;
            int windowStart, windowEnd, windowStartTemp, windowEndTemp;
            
            //Use a top-down search to find the first largest palindrome
            while(!found)
            {
                windowStart = 0;
                windowEnd = s.length()-1-gap;
                windowStartTemp = windowStart;
                windowEndTemp = windowEnd;
                
                for(int i=0; i<=gap; ++i)
                {
                    equal = true;
                    windowStartTemp = windowStart;
                    windowEndTemp = windowEnd;
                    while(equal && (windowEndTemp-windowStartTemp)>=0)
                    {
                        if(s[windowStartTemp] != s[windowEndTemp]) equal = false;
                        windowStartTemp++;
                        windowEndTemp--;
                    }
                    if(equal)
                    {
                        for(int i=windowStart; i<=windowEnd; ++i)
                            palindrome += s[i];
                        found = true;
                        break;
                    }
                    windowStart++;
                    windowEnd++;
                }
                gap++;
            }
        }
        
        return palindrome;
    }
};
