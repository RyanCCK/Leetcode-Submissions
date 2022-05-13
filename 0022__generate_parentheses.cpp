/*

LEETCODE PROBLEM 22 | Generate Parentheses | 5/12/2022

*****************************************************************************************************************************

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


Constraints:

1 <= n <= 8

*****************************************************************************************************************************

Runtime: 3 ms, faster than 83.78% of C++ online submissions for Generate Parentheses.
Memory Usage: 7.2 MB, less than 96.79% of C++ online submissions for Generate

*/

class Solution {
public:
    //Helper function to create vector (using binary tree structure) with only valid parenthesis combinations as elements
    void buildVectorAsTree(vector<string>& vec, int currIndex, int openParens, int maxSize)
    {
        //Return if the current string is at max size
        if(vec[currIndex].length() == maxSize) 
        {
            return;
        }
    
        //Determine what characters (if any) would be valid if appended to the current string:
        //  If both '(' and ')' are possible
        if(openParens > 0 && openParens < maxSize-vec[currIndex].length() && maxSize-vec[currIndex].length() > 2)
        {
            string copy = vec[currIndex];   //Preserve a copy of the current string up to this point
            
            //Continue building current string given '(' as next character
            vec[currIndex] += '(';
            buildVectorAsTree(vec, currIndex, ++openParens, maxSize);
            
            vec.push_back(copy);    //Create new vector element
            --openParens;   //Resets openParens to its correct current value
            currIndex = vec.size()-1;   //Update current index based on new size of vector
            
            //Finish building new string given ')' as next character
            vec[currIndex] += ')';
            buildVectorAsTree(vec, currIndex, --openParens, maxSize);
        }
        //  If only '(' is possible
        else if(openParens == 0)
        {
            //Continue building current string given '(' as next character
            vec[currIndex] += '(';
            buildVectorAsTree(vec, currIndex, ++openParens, maxSize);
        }
        //  If only ')' is possible
        else if(openParens == maxSize-vec[currIndex].length())
        {
            //Continue building current string given ')' as next character
            vec[currIndex] += ')';
            buildVectorAsTree(vec, currIndex, --openParens, maxSize);
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        //validParentheses holds all valid parenthesis combinations.
        //maxSize is the required size of each element of validParentheses.
        vector<string> validParentheses {"("};
        int maxSize = n*2;
        
        //Build vector to hold valid parenthesis combinations
        buildVectorAsTree(validParentheses, 0, 1, maxSize);
        
        //Return vector holding all valid parenthesis combinations
        return validParentheses;
    }    
};
