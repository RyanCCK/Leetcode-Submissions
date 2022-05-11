/*

LEETCODE PROBLEM 17 | Letter Combinations of a Phone Number | 5/11/2022

*****************************************************************************************************************************

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

2 = {a, b, c}
3 = {d, e, f}
4 = {g, h, i}
5 = {j, k, l}
6 = {m, n, o}
7 = {p, q, r, s}
8 = {t, u, v}
9 = {w, x, y, z}


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*****************************************************************************************************************************

Runtime: 2 ms, faster than 45.05% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.6 MB, less than 35.09% of C++ online submissions for Letter Combinations of a Phone Number.

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        int numDigits = digits.length();
        
        //Check the base case
        if(numDigits == 0) return combinations;
        
        //Create 2D vector for chars corresponding to digit = index + 2
        vector<vector<char>> chars = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, 
                               {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
        
        //Determine number of character combinations (size of combinations vector)
        int size = 1;
        for(char c : digits) size *= chars[c-'2'].size();
        
        string temp("");
        
        //Push back each combination to the vector
        for(int i=0; i<chars[digits[0]-'2'].size(); ++i)
        {
            temp = "";
            temp += chars[digits[0]-'2'][i];
            if(numDigits > 1)
            {
                for(int j=0; j<chars[digits[1]-'2'].size(); ++j)
                {
                    temp += chars[digits[1]-'2'][j];
                    if(numDigits > 2)
                    {
                        for(int k=0; k<chars[digits[2]-'2'].size(); ++k)
                        {
                            temp += chars[digits[2]-'2'][k];
                            if(numDigits > 3)
                            {
                                for(int l=0; l<chars[digits[3]-'2'].size(); ++l)
                                {
                                    temp += chars[digits[3]-'2'][l];
                                    combinations.push_back(temp);
                                    temp.pop_back();
                                }
                            }
                            else combinations.push_back(temp);
                            temp.pop_back();
                        }
                    }
                    else combinations.push_back(temp);
                    temp.pop_back();
                }
            }
            else combinations.push_back(temp);
        }
        return combinations;
    }    
};
