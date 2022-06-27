class Solution {
public:
    int minPartitions(string n) 
    {
        int max1=0;
        for(auto i: n)
            max1 = max(max1,(int)(i-'0'));
        return max1;
    }
};