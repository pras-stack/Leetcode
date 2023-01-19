class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int K) 
    {
        vector<int> count(K);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : nums) 
        {
            prefix = (prefix + a % K + K) % K;
            res += count[prefix]++;
        }
        return res;
    }
};
























// Calculate the prefix sum and count it.
// In c++ and java, a % K + K takes care of the cases where a < 0