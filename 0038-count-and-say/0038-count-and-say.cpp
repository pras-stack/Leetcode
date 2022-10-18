class Solution {
public:
    string countAndSay(int n) 
    {
         //base case
        if(n==1)
            return "1";
        
        
        
        //for nth int
        string s="1";
       
        
        for(int i=2;i<=n;i++){
        string temp="";
        int freqCount=1;
          s=s+'&';   //dummy charcter because In below for loop, previous character
        // is processed in current iteration
            
            for(int j=1;j<s.length();j++){
                if(s[j]==s[j-1])
                    freqCount++;
                else{
                    temp=temp+to_string(freqCount);
                    temp=temp+s[j-1];
                    freqCount=1;
                }
              
            }
         s=temp; 
            
        }
        
        return s;
    }
};