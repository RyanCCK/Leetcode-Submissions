/*

LEETCODE PROBLEM 28 | Implement strStr() | 5/18/2022

**************************************************************************************************

Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

**************************************************************************************************

Runtime: 3 ms, faster than 54.80% of C++ online submissions for Implement strStr().
Memory Usage: 6.3 MB, less than 70.22% of C++ online submissions for Implement strStr().

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        //Base case
        if(needle.length() > haystack.length()) return -1;
        
        int index = -1; //index of needle in haystack
        
        for(int i=0, j=0; haystack.length()-i >= needle.length(); ++i)
        {
            while(j<needle.length() && haystack[i+j] == needle[j]) ++j;
            if(j == needle.length())
            {
                index = i;
                break;
            }
            else j=0;
        }
        
        return index;
    }
};
