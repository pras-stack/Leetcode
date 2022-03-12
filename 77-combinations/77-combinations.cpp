class Solution {
public:
    void rec(int i, int k, int n, vector<int>& cur, vector<vector<int>>& res)
    {
    if(cur.size()==k) 
    {
        res.push_back(cur);
    } 
        else
        {
        for(int j=i;j<=n;j++) 
        {
            cur.push_back(j);
            rec(j+1, k, n, cur, res);
            cur.pop_back();
        }
    }
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> cur;
    rec(1, k, n, cur, res);
    return res;
}
};