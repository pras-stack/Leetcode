class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int res =0;
        for(auto val : nums)
        {
            res = res^val;
        }
        return res;
    }
};