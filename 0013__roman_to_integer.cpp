/*

LEETCODE PROBLEM 13 | Roman to Integer | 5/9/2022

*****************************************************************************************************************************

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.


Constraints:

1 <= num <= 3999

*****************************************************************************************************************************

Runtime: 11 ms, faster than 70.30% of C++ online submissions for Roman to Integer.
Memory Usage: 8.3 MB, less than 21.34% of C++ online submissions for Roman to Integer.

*/

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> romanToInt = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int result = 0, size = s.length();
    
        for(int i=size-1; i>=0; --i)
        {
            result += (romanToInt.at(s[i]));
            //Perform subtraction when necessary
            if(i-1 >= 0 && romanToInt.at(s[i-1]) < romanToInt.at(s[i]))
            {
                result -= (romanToInt.at(s[i-1]));
                --i;
            }
        }
        return result;
    }
};
