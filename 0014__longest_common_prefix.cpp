/*

LEETCODE PROBLEM 14 | Longest Common Prefix | 5/9/2022

*****************************************************************************************************************************

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*****************************************************************************************************************************

Runtime: 3 ms, faster than 87.93% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.3 MB, less than 44.37% of C++ online submissions for Longest Common Prefix.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool fail = false;
        string prefix("");
        char testChar;
        
        //Find shortest string in strs to constrain max number of comparisons
        int shortestStringSize = strs[0].length();
        for(int i=0; i<strs.size(); ++i)
        {
            if(strs[i].length() < shortestStringSize)
                shortestStringSize = strs[i].length();
        }
        
        //Build prefix
        for(int i=0; i<shortestStringSize && !fail; ++i)
        {
            char testChar = strs[0][i];
            for(int j=1; j<strs.size() && !fail; ++j)
            {
                if(strs[j][i] != testChar) fail = true;
            }
            if(!fail) prefix += testChar;
        }
        return prefix;
    }
};
