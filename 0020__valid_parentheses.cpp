/*

LEETCODE PROBLEM 20 | Valid Parentheses | 5/11/2022

*****************************************************************************************************************************

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*****************************************************************************************************************************

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.3 MB, less than 79.87% of C++ online submissions for Valid Parentheses.

*/

class Solution {
public:
    bool isValid(string s) {
        //Use a stack to keep track of the most recent open parentheses.
        //When a closing parenthesis appears, there must be a matching open type
        //at the top of the stack. This is then popped from the stack.
        //At the end of string s, the stack must be empty. 
        //Violating any of the above conditions results in a false return value.
        
        stack<char> parens;
        for(char c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                parens.push(c);
            else
            {
                if(parens.empty()) return false;
                else if((c == ')' && parens.top() == '(')
                     || (c == ']' && parens.top() == '[')
                     || (c == '}' && parens.top() == '{')) parens.pop();
                else return false;  //All other cases involve a mismatch of adjacent symbols
            }
        }
        return parens.empty();
    }
};
