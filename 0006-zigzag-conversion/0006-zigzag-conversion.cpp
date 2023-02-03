class Solution {
public:
    string convert(string s, int numRows)
    {
           if (numRows == 1) return s;
    string result;
    int step = 2 * (numRows - 1);
    for (int i = 0; i < numRows; i++) 
    {
        int start;
        if (i == 0 || i == numRows - 1) 
        {
            start = i;
            while (start < s.length()) 
            {
                result += s[start];
                start += step;
            }
        } 
        else 
        {
            start = i;
            while (start < s.length()) 
            {
                result += s[start];
                int tmp = start + step - 2 * i;
                if (tmp < s.length()) result += s[tmp];
                start += step;
            }
        }
    }
    return result;
    }
};