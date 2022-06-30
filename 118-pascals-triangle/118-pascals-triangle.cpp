class Solution 
    {
    vector<vector<int>>ans;
public:    
    vector<vector<int>>& generate(int n) 
    {
        if(n) 
        {
            generate(n-1);                       // generate above row first
            ans.emplace_back(vector<int>(n,1));  // insert current row into triangle
            for(int i = 1; i < n-1; i++)         // update current row values using above row
                ans[n-1][i] = ans[n-2][i] + ans[n-2][i-1];    
        }
        return ans;
    
    }
};