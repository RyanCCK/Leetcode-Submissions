/*

LEETCODE PROBLEM 12 | Integer to Roman | 5/6/2022

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

Given an integer, convert it to a roman numeral.


Constraints:

1 <= num <= 3999

*****************************************************************************************************************************

Runtime: 7 ms, faster than 77.25% of C++ online submissions for Integer to Roman.
Memory Usage: 6 MB, less than 50.11% of C++ online submissions for Integer to Roman.

*/

class Solution {
public:
    string intToRoman(int num) {
        string roman("");
        int ones, tens, hundreds, thousands;
        
        //Thousands place
        if(num >= 1000)
        {
            thousands = num/1000;
            num %= 1000;
            
            for(int i=1; i<=thousands; ++i)
                roman += 'M';
        }
        
        //Hundreds place
        if(num >= 100)
        {
            hundreds = num/100;
            num %= 100;
            
            if(hundreds == 9)
            {
                roman += "CM";
            }
            else if(hundreds == 4)
            {
                roman += "CD";
            }
            else if(hundreds >= 5)
            {
                roman += 'D';
                hundreds -= 5;
            }
            if(hundreds < 4 && hundreds > 0)
            {
                for(int i=1; i<=hundreds; ++i)
                    roman += 'C';
            }
        }
        
        //Tens place
        if(num >= 10)
        {
            tens = num/10;
            num %= 10;
            
            if(tens == 9)
            {
                roman += "XC";
            }
            else if(tens == 4)
            {
                roman += "XL";
            }
            else if(tens >= 5)
            {
                roman += 'L';
                tens -= 5;
            }
            if(tens < 4 && tens > 0)
            {
                for(int i=1; i<=tens; ++i)
                    roman += 'X';
            } 
        }
        
        //Ones place
        if(num > 0)
        {
            ones = num;
            
            if(ones == 9)
            {
                roman += "IX";
            }
            else if(ones == 4)
            {
                roman += "IV";
            }
            else if(ones >= 5)
            {
                roman += 'V';
                ones -= 5;
            }
            if(ones < 4 && ones > 0)
            {
                for(int i=1; i<=ones; ++i)
                    roman += 'I';
            }
        }
        return roman;
    }
};


//A MUCH WORSE SOLUTION USING A MAP:
/*
class Solution {
public:
    string intToRoman(int num) {
        string roman("");
        map<int, string> mp;
        
        //Insert all int-to-roman conversions that will be used into the map
        mp.insert(pair<int,string>(1,"I"));
        mp.insert(pair<int,string>(2,"II"));
        mp.insert(pair<int,string>(3,"III"));
        mp.insert(pair<int,string>(4,"IV"));
        mp.insert(pair<int,string>(5,"V"));
        mp.insert(pair<int,string>(6,"VI"));
        mp.insert(pair<int,string>(7,"VII"));
        mp.insert(pair<int,string>(8,"VIII"));
        mp.insert(pair<int,string>(9,"IX"));
        mp.insert(pair<int,string>(10,"X"));
        mp.insert(pair<int,string>(20,"XX"));
        mp.insert(pair<int,string>(30,"XXX"));
        mp.insert(pair<int,string>(40,"XL"));
        mp.insert(pair<int,string>(50,"L"));
        mp.insert(pair<int,string>(60,"LX"));
        mp.insert(pair<int,string>(70,"LXX"));
        mp.insert(pair<int,string>(80,"LXXX"));
        mp.insert(pair<int,string>(90,"XC"));
        mp.insert(pair<int,string>(100,"C"));
        mp.insert(pair<int,string>(200,"CC"));
        mp.insert(pair<int,string>(300,"CCC"));
        mp.insert(pair<int,string>(400,"CD"));
        mp.insert(pair<int,string>(500,"D"));
        mp.insert(pair<int,string>(600,"DC"));
        mp.insert(pair<int,string>(700,"DCC"));
        mp.insert(pair<int,string>(800,"DCCC"));
        mp.insert(pair<int,string>(900,"CM"));
        mp.insert(pair<int,string>(1000,"M"));
        mp.insert(pair<int,string>(2000,"MM"));
        mp.insert(pair<int,string>(3000,"MMM"));
        
        //Create string
        if(num >= 1000)
        {
            roman += mp[(num/1000)*1000];
            num %= 1000;
        }
        if(num >= 100)
        {
            roman += mp[(num/100)*100];
            num %= 100;
        }
        if(num >= 10)
        {
            roman += mp[(num/10)*10];
            num %= 10;
        }
        if(num >= 0)
        {
            roman += mp[num];
        }
        return roman;
    }
};
*/




/*
ANOTHER ALTERNATE SOLUTION, DESIGNED TO WORK WITH AN EXTENSIBLE ROMAN NUMERAL CHARACTER SET
THIS WAS MADE UNDER THE INCORRECT ASSUMPTION THAT ROMAN NUMERALS EXTEND BEYOND THE SET DEFINED IN THE PROBLEM DESCRIPTION


class Solution {
public:
    string intToRoman(int num) {
        /*
        Solution Intention:
            
        Use a 2D vector to store the symbols used to represent 1 and 5 in roman numerals.
        Given v[x][y], x represents the place for the symbols: 
            (0 = ones, 1 = tens, 2 = hundreds, etc.)
        and the corresponding vector will have two elements:
            y=0 holds the representation of 1*(place+1)
            y=1 holds the representation of 5*(place+1)
            
        A while loop will iterate for the number of digits in num, with each iteration
        popping the top number and passing it into a switch statement that will determine 
        what string represents that digit at that place.
        
        THIS DESIGN IS meant to be extensible; it can accommodate any size set of roman numeral values,
        simply by adding them into their correct index within the 2D vector.
        */
        /*
        //Return this string
        string roman("");
        
        //Set up vector to store roman numeral symbols for integer values
        vector<vector<string>> symVals;
        vector<string> onesVals {"I", "V"};
        vector<string> tensVals {"X", "L"};
        vector<string> hundredsVals {"C", "D"};
        vector<string> thousandsVals{"M"};
        symVals.push_back(onesVals);
        symVals.push_back(tensVals);
        symVals.push_back(hundredsVals);
        symVals.push_back(thousandsVals);
        
        //Get number of digits and declare first digit variable
        int digit, divisor = 1;
        int numDigits = 0;
        while(num/divisor != 0)
        {
            ++numDigits;
            divisor *= 10;
        }
        
        //Append to roman string while there are still digits to process
        for(int i=0; i<numDigits; ++i)
        {
            digit = num/pow(10, numDigits-1-i);
            num = (numDigits==1) ? num % 10 : num % (int) pow(10, numDigits-1-i);
            
            switch(digit)
            {
                case 1:
                    roman += symVals[numDigits-1-i][0];
                    break;
                case 2:
                    roman += symVals[numDigits-1-i][0];
                    roman += symVals[numDigits-1-i][0];
                    break;
                case 3:
                    roman += symVals[numDigits-1-i][0];
                    roman += symVals[numDigits-1-i][0];
                    roman += symVals[numDigits-1-i][0];
                    break;
                case 4:
                    roman += symVals[numDigits-1-i][0];
                    roman += symVals[numDigits-1-i][1];
                    break;
                case 5:
                    roman += symVals[numDigits-1-i][1];
                    break;
                case 6:
                    roman += symVals[numDigits-1-i][1];
                    roman += symVals[numDigits-1-i][0];
                    break;
                case 7:
                    roman += symVals[numDigits-1-i][1];
                    roman += symVals[numDigits-1-i][0];
                    roman += symVals[numDigits-1-i][0];
                    break;
                case 8:
                    roman += symVals[numDigits-1-i][1];
                    roman += symVals[numDigits-1-i][0];
                    roman += symVals[numDigits-1-i][0];
                    roman += symVals[numDigits-1-i][0];
                    break;
                case 9:
                    roman += symVals[numDigits-1-i][0];
                    roman += symVals[numDigits-i][0];
                    break;
            }
        }
        return roman;
    }
};
*/
