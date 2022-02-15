class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
    int n = nums.size(), i = 0, j = 0, sum = 0, res = INT_MAX;
    while(j < n)
    {
        sum += nums[j];
        if(sum < target) 
        {
            j++;
            continue;
        }

        while(sum >= target) 
        {
            res = min(res, j - i + 1);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    if(res == INT_MAX) return 0;

    return res;
}
};