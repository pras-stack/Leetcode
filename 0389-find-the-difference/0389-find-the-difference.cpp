class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        char res;
        unordered_map<char,int>memo;
        for(auto ch:t)
            memo [ch]++;
        
        for(auto ch:s)
            memo [ch]--;
        
        for(auto val:memo)
        {
            if(memo[val.first]>0)
                res=val.first;
        }
        
        return res;
        
    }
};