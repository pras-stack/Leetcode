class Solution {
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        stack<char> s;
        //Store the final string in stack
        for(char c: num)
        {
            while(!s.empty() && k>0 && s.top()>c)
            {   s.pop();      k-=1;   }
            
            if(!s.empty() || c!='0')
                s.push(c);
        }
        
        //Now remove the largest values from the top of the stack
        while(!s.empty() && k--)
            s.pop();
        if(s.empty())
            return "0";
        
        //Now retrieve the number from stack into a string (reusing num)
        while(!s.empty())
        {
            num[n-1] = s.top();
            s.pop();
            n-=1;
        }
        return num.substr(n);
    }
};