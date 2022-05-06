/*

LEETCODE PROBLEM 6 | Zigzag Conversion | 5/1/2022

*****************************************************************************************************************************

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

*****************************************************************************************************************************

Runtime: 11 ms, faster than 73.24% of C++ online submissions for Zigzag Conversion.
Memory Usage: 8.2 MB, less than 77.92% of C++ online submissions for Zigzag Conversion.

*/

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        //The converted string to be returned
        string result = "";
        //The current index in the parameter string s
        int curr;
        //The size of a "Zag", defined as the characters in the converted
        //  zig-zag string from one top level character (inclusive) to the
        //  next (exclusive)
        int zagSize = (numRows*2)-2;
        if(numRows == 1) zagSize = 1;
        
        //For each row in the zig zag string, 
        //  concatenate the characters in that row to the result string
        for(int currRow=1; currRow<=numRows; ++currRow)
        {
            curr = currRow-1;
            //Find the characters belonging to current row in each Zag,
            // and concatenate to result string
            while(curr < s.length())
            {
                //If we are in the first or last row
                if(currRow == 1 || currRow == numRows)
                {
                    result += s[curr];
                    curr += zagSize;
                }
                //Otherwise
                else
                {
                    result += s[curr];
                    //Set two incrementation variables
                    int inc1, inc2;
                    inc1 = (numRows-currRow)*2;
                    inc2 = currRow*2-2;
                    //increment curr
                    curr += inc1;
                    //if in bounds, concatenate s[curr]
                    if(curr < s.length())
                        result += s[curr];
                    //finish incrementing curr
                    curr += inc2;
                }
            }
        }
        return result;
    }
};
