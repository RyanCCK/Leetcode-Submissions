/*

LEETCODE PROBLEM 3 | Longest Substring Without Repeating Characters | 4/17/2022

***********************************************************************************************************************

Given a string s, find the length of the longest substring without repeating characters.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

***********************************************************************************************************************

Runtime: 680 ms, faster than 8.97% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 7.1 MB, less than 87.19% of C++ online submissions for Longest Substring Without Repeating Characters.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> str(s.begin(), s.end());
        vector<char> substr;
        int duplicateIndexInSubstr;
        int maxSize = 0; 
        int offset = 0;
        int i=0;
        bool duplicateFound = false;
        
        while(i<str.size())
        {
            for(int j=0; j<substr.size(); ++j)
            {
                if(str[i] == substr[j])
                {
                    duplicateFound = true;
                    duplicateIndexInSubstr = j;
                    break;
                }
            }
            if(duplicateFound)
            {
                if(substr.size()>maxSize) maxSize = substr.size();
                i = duplicateIndexInSubstr + offset + 1;
                offset = i;
                substr.clear();
                duplicateFound = false;
            }
            else
            {
                if(!str.empty())
                    substr.push_back(str[i]);
                if(substr.size()>maxSize) maxSize = substr.size();
                ++i;
            }
        }
        
        return maxSize;
    }
};
